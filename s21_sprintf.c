#include "s21_string.h"

typedef struct {
  char flag;
  char flag_zero;
  int width;
  int accuracy;
  char length;
  char spec;
} Spec;

#define SIZE_ARRAY 2056

int convert_from_str_to_int(const char* str);
char* convert_from_int_to_str(char* src, long x, int base, Spec token);
void convert_from_float_to_str(char* str, double x, Spec token);
int parser(char* format, Spec* token, va_list var);
int validation(Spec token);

int s21_strtol(const char* str, char** end);
int X_counter(double x);
void insert_in_start(char* buffer, char c);
void exp_notation(char* buffer, double x, Spec token);
void del_zeroes(char* str);
int func_for_gG(Spec* token, double fval);
void func_for_p(char* buffer, void* ptr, Spec token);

void processing_the_specifier(char* buffer, va_list var, Spec* token);
void processing_the_accuracy(char* buffer, Spec token);
void processing_the_flags(char* buffer, Spec token);
void processing_width(char* buffer, Spec token);
void make_common_str(char* str, Spec* token, va_list var);

void checks_length(char* buffer, long dval, Spec token, int base);
void checks_length_u(char* buffer, unsigned long uval, Spec token, int base);
void check_grid_oxX(char* buffer, long val, Spec token);

int s21_sprintf(char* str, const char* format, ...) {
  va_list var;
  va_start(var, format);

  *str = 0;

  int flag = 1;

  char* ptr_in = (char*)format;
  int ptr_out = 0;

  while (*ptr_in && flag) {
    Spec token = {0, 0, -1, -1, 0, 0};
    if (*ptr_in == '%') {
      if ((flag = parser(ptr_in + 1, &token, var) && validation(token))) {
        ptr_in++;
        char make_str[SIZE_ARRAY] = "";
        make_common_str(make_str, &token, var);
        ptr_in += s21_strcspn(ptr_in, "sucdfxXopeEgGg%") + 1;
        s21_strncat(str, make_str, s21_strlen(make_str));
        ptr_out += s21_strlen(make_str);
      } else {
        str[ptr_out++] = *ptr_in++;
      }
    } else {
      str[ptr_out++] = *ptr_in++;
      str[ptr_out] = '\0';
    }
  }

  va_end(var);

  int res = s21_strlen(str);

  if (!flag) res = -1;

  return res;
}

void make_common_str(char* str, Spec* token, va_list var) {
  char buffer[SIZE_ARRAY] = "";
  // спецификаторы
  processing_the_specifier(buffer, var, token);
  // точность
  if (token->accuracy != -1) processing_the_accuracy(buffer, *token);
  // флаги
  if (token->flag != 0) processing_the_flags(buffer, *token);
  // ширина
  if (token->width != 0) processing_width(buffer, *token);

  s21_strncpy(str, buffer, s21_strlen(buffer) + 1);
}

void processing_the_specifier(char* buffer, va_list var, Spec* token) {
  switch (token->spec) {
    case ('s'): {
      const char* arg = va_arg(var, char*);
      s21_strncpy(buffer, arg, s21_strlen(arg));
      break;
    }
    case ('c'):
      buffer[0] = (char)va_arg(var, int);
      break;
    case ('d'):
      checks_length(buffer, va_arg(var, long), *token, 10);
      break;
    case ('u'):
      checks_length_u(buffer, va_arg(var, unsigned long), *token, 10);
      break;
    case ('o'):
    case ('x'):
    case ('X'): {
      long xoval = va_arg(var, long);
      int base = (token->spec == 'o') ? 8 : 16;
      checks_length_u(buffer, xoval, *token, base);
      check_grid_oxX(buffer, xoval, *token);
      break;
    }
    case ('p'):
      func_for_p(buffer, va_arg(var, void*), *token);
      break;
    case ('g'):
    case ('G'):
    case ('f'):
    case ('e'):
    case ('E'): {
      double fval = (token->length == 'L') ? va_arg(var, long double)
                                           : va_arg(var, double);
      if (token->spec == 'g' || token->spec == 'G') {
        if (func_for_gG(token, fval) == 1)
          convert_from_float_to_str(buffer, fval, *token);
        else
          exp_notation(buffer, fval, *token);
      } else if (token->spec == 'f')
        convert_from_float_to_str(buffer, fval, *token);
      else
        exp_notation(buffer, fval, *token);
      break;
    }
    case ('%'):
      buffer[0] = '%';
  }
}

void func_for_p(char* buffer, void* ptr, Spec token) {
  uintptr_t adress = (uintptr_t)ptr;
  convert_from_int_to_str(buffer, adress, 16, token);
  char* new_str = s21_insert(buffer, "0x", 0);
  s21_strncpy(buffer, new_str, s21_strlen(new_str));
  free(new_str);
}

int func_for_gG(Spec* token, double fval) {
  int res, P, X = X_counter(fval);
  if (token->accuracy == -1)
    P = 6;
  else if (token->accuracy == 0)
    P = 1;
  else
    P = token->accuracy;

  if (P > X && X >= -4) {
    token->accuracy = P - 1 - X;
    res = 1;
  } else {
    token->accuracy = P - 1;
    token->spec -= 2;
    res = 2;
  }
  return res;
}

void processing_the_accuracy(char* buffer, Spec token) {
  if (token.accuracy == 0 &&
      (buffer[0] == '0' || buffer[s21_strlen(buffer)] == '0') &&
      (token.spec == 'd' || token.spec == 'u')) {
    buffer[0] = 0;
  } else if ((token.spec == 'd' || token.spec == 'u' || token.spec == 'x' ||
              token.spec == 'X' || token.spec == 'o' || token.spec == 'p') &&
             token.accuracy != -1) {
    int i = 0, ind, len;
    if (buffer[0] == '-' || buffer[0] == '+') {
      ind = 1;
      len = token.accuracy - s21_strlen(buffer) + 1;
    } else if (buffer[0] == '0' && (buffer[1] == 'x' || buffer[1] == 'X')) {
      ind = 2;
      len = token.accuracy - s21_strlen(buffer) + 2;
    } else if (buffer[0] == '0') {
      ind = 1;
      len = token.accuracy - s21_strlen(buffer);
    } else {
      ind = 0;
      len = token.accuracy - s21_strlen(buffer);
    }
    while (i < len) {
      char* new_str;
      new_str = s21_insert(buffer, "0", ind + i);
      s21_strncpy(buffer, new_str, s21_strlen(new_str));
      i++;
      free(new_str);
    }

  } else if (token.spec == 's' && token.accuracy != -1) {
    int i = 0, len = s21_strlen(buffer) - token.accuracy;
    while (i++ < len) buffer[s21_strlen(buffer) - 1] = '\0';
  }
}

void processing_the_flags(char* buffer, Spec token) {
  switch (token.flag) {
    case ('+'):
      if (buffer[0] != '-') insert_in_start(buffer, '+');
      break;
    case (' '):
      if (buffer[0] != '-') insert_in_start(buffer, ' ');
      break;
    case ('-'): {
      if (token.width != -1) {
        int i = 0, len = token.width - s21_strlen(buffer);
        while (i++ < len) buffer[s21_strlen(buffer)] = ' ';
      }
      break;
    }
  }
}

void processing_width(char* buffer, Spec token) {
  int i = 0, ind = 0, len = token.width - s21_strlen(buffer);

  if ((buffer[0] == '-' || buffer[0] == '+') && token.flag_zero == '0') {
    ind = 1;
  } else if ((buffer[0] == '0' && (buffer[1] == 'x' || buffer[1] == 'X')) &&
             token.flag_zero == '0') {
    ind = 2;
  } else if ((buffer[0] == '0') && token.flag_zero == '0') {
    ind = 1;
  }
  while (i < len) {
    char* new_str;
    if (token.flag_zero == '0')
      new_str = s21_insert(buffer, "0", ind + i);
    else
      new_str = s21_insert(buffer, " ", ind + i);
    s21_strncpy(buffer, new_str, s21_strlen(new_str));
    i++;
    free(new_str);
  }
}

void insert_in_start(char* buffer, char c) {
  int end = 0;
  if (buffer[0] == '-' || buffer[0] == '+') {
    end = 1;
  }
  for (int i = s21_strlen(buffer) + 1; i > end; i--) {
    buffer[i] = buffer[i - 1];
  }
  buffer[end] = c;
}

void checks_length(char* buffer, long val, Spec token, int base) {
  if (token.length == 'h') {
    convert_from_int_to_str(buffer, (short)val, base, token);
  } else if (token.length == 'l') {
    convert_from_int_to_str(buffer, (long)val, base, token);
  } else {
    convert_from_int_to_str(buffer, (int)val, base, token);
  }
}

void checks_length_u(char* buffer, unsigned long uval, Spec token, int base) {
  if (token.length == 'h') {
    convert_from_int_to_str(buffer, (unsigned short)uval, base, token);
  } else if (token.length == 'l') {
    convert_from_int_to_str(buffer, (unsigned long)uval, base, token);
  } else {
    convert_from_int_to_str(buffer, (unsigned int)uval, base, token);
  }
}

int parser(char* format, Spec* token, va_list var) {
  int err = 1;

  if (*format == '0') token->flag_zero = *format++;
  if (*format == '-' || *format == '+' || *format == ' ' || *format == '#')
    token->flag = *format++;
  if (*format == '0') token->flag_zero = *format++;

  if (*format == '*') {
    token->width = va_arg(var, unsigned long);
    format++;
  } else if (*format >= '0' && *format <= '9' && token->width == -1)
    token->width = s21_strtol(format, &format);

  if (*format == '.' && token->accuracy == -1) {
    format++;
    if (*format == '*') {
      token->accuracy = va_arg(var, unsigned long);
      format++;
    } else
      token->accuracy = s21_strtol(format, &format);
  }

  if (*format == 'h' || *format == 'l' || *format == 'L')
    token->length = *format++;

  if (*format == 'c' || *format == 'd' || *format == 'u' || *format == 's' ||
      *format == '%' || *format == 'f' || *format == 'x' || *format == 'X' ||
      *format == 'o' || *format == 'p' || *format == 'e' || *format == 'E' ||
      *format == 'G' || *format == 'g') {
    token->spec = *format++;
  } else
    err = 0;
  return err;
}

char* convert_from_int_to_str(char* src, long x, int base, Spec token) {
  char str[256] = "";
  int f = 0;
  if (x < 0) {
    f = 1;
    x = -x;
  }
  if (x == 0) {
    str[0] = '0';
  } else {
    int i = 0;
    while (x) {
      int based = x % base;
      if (based <= 9) {
        str[i++] = based + '0';
      } else if (token.spec == 'x' || token.spec == 'p') {
        str[i++] = based + 87;
      } else if (token.spec == 'X') {
        str[i++] = based + 55;
      }
      x = x / base;
    }
    int s = 0, l = i - 1;
    while (s < l) {
      char tmp = str[s];
      str[s] = str[l];
      str[l] = tmp;
      s++;
      l--;
    }
  }
  s21_strncpy(src, str, s21_strlen(str));
  if (f) insert_in_start(src, '-');
  return src;
}

int convert_from_str_to_int(const char* str) {
  int result = 0;
  int mult = 1;
  s21_size_t len = s21_strlen(str);
  for (int i = len - 1; i >= 0; i--) {
    int num = str[i] - '0';
    result += num * mult;
    mult *= 10;
  }
  return result;
}

void convert_from_float_to_str(char* str, double x, Spec token) {
  int f = 0;
  if (x < 0) {
    f = 1;
    x = -x;
  }

  int int_part = (int)x;
  long double fval = x - int_part;
  int powers = 0, dif = 0;

  if (token.accuracy == -1)
    powers = 6;
  else if (token.accuracy <= 16)
    powers = token.accuracy;
  else {
    powers = 16;
    dif = token.accuracy - 16;
  }

  long long int float_part = (long long int)round(fval * pow(10.0L, powers));
  char str_int_part[256] = "";
  convert_from_int_to_str(str_int_part, int_part, 10, token);

  if (powers > 0 || token.flag == '#')
    str_int_part[s21_strlen(str_int_part)] = '.';

  char str_float_part[256] = "";

  convert_from_int_to_str(str_float_part, float_part, 10, token);
  if (token.accuracy == 0) str_float_part[0] = '\0';

  int i = 0, len = (float_part == 0)
                       ? powers - 1 + dif
                       : (int)s21_strlen(str_float_part) - powers + dif;

  while (i++ < len) str_float_part[s21_strlen(str_float_part)] = '0';
  s21_strncat(str_int_part, str_float_part, s21_strlen(str_float_part));

  if (f) insert_in_start(str_int_part, '-');

  if (token.flag != '#' && (token.spec == 'g' || token.spec == 'G'))
    del_zeroes(str_int_part);
  s21_strncpy(str, str_int_part, s21_strlen(str_int_part));
}

void del_zeroes(char* str) {
  char* p = str + s21_strlen(str) - 1;  // оказываемся в конце строки dest
  while (*p == 48) {
    *p = '\0';
    p--;
  }
  if (*p == '.') {
    *p = '\0';
  }
}

void exp_notation(char* buffer, double x, Spec token) {
  int step = 0;

  step = X_counter(x);
  x = x / (pow(10.0, step));

  convert_from_float_to_str(buffer, x, token);

  buffer[s21_strlen(buffer)] = token.spec;
  if (step < 0) {
    buffer[s21_strlen(buffer)] = '-';
    step *= -1;
  } else {
    buffer[s21_strlen(buffer)] = '+';
  }

  char powers[100] = "";

  if (step < 10) {
    buffer[s21_strlen(buffer)] = '0';
    buffer[s21_strlen(buffer)] = step + '0';
  } else {
    convert_from_int_to_str(powers, step, 10, token);
    s21_strncat(buffer, powers, s21_strlen(powers));
  }
}

int s21_strtol(const char* str, char** end) {
  char buffer[256] = "";
  int i = 0;
  while (*str >= '0' && *str <= '9') {
    buffer[i++] = *str;
    str++;
  }
  *end = (char*)str;
  return convert_from_str_to_int(buffer);
}

int validation(Spec token) {
  int err = 1;
  if ((token.spec == 's' || token.spec == 'c') &&
      (token.flag == ' ' || token.flag == '+')) {
    err = 0;
  }
  if (token.flag_zero == 48 && token.accuracy != -1) {
    err = 0;
  }
  return err;
}

int X_counter(double x) {
  int step = 0;
  if (x != 0) {
    if (x < 0) {
      x *= -1;
    }
    while (x > 10) {
      step++;
      x /= 10.0;
    }

    if ((int)x == 0) {
      step--;
    }
  }

  return step;
}

void check_grid_oxX(char* buffer, long val, Spec token) {
  if (val > 0 && token.flag == '#') {
    char* new_str = "";
    if (token.spec == 'x') {
      new_str = s21_insert(buffer, "0x", 0);
    } else if (token.spec == 'X') {
      new_str = s21_insert(buffer, "0X", 0);
    } else if (token.spec == 'o') {
      new_str = s21_insert(buffer, "0", 0);
    }
    s21_strncpy(buffer, new_str, s21_strlen(new_str));
    free(new_str);
  }
}

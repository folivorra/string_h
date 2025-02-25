GCC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra -g
LIB_NAME = s21_string.a
SRCS = s21_*.c

all: $(LIB_NAME)

test:rebuild tests/*.c
	$(GCC) tests/*.c $(LIB_NAME) -lcheck -lm -g -o test
	./test
	rm test

gcov_report: clean $(SRCS) tests/*.c
	@mkdir report
	$(GCC) --coverage $(SRCS) tests/*.c -lcheck -lm -lsubunit -o report/test
	./report/test
	@gcovr --html-details -o report/report.html
	@xdg-open report/report.html

$(LIB_NAME): $(OBJS)
	$(GCC) -c $(CFLAGS) $(SRCS)
	ar rcs $(LIB_NAME) *.o
	ranlib $(LIB_NAME)
	mkdir objects/
	mv *.o objects/

rebuild: clean $(LIB_NAME)

clang:
	@clang-format -i *.c *.h
	@clang-format -n *.c *.h
	@clang-format -i tests/*.c tests/*.h
	@clang-format -n tests/*.c tests/*.h

clean:
	rm -rf *.o objects $(LIB_NAME) report a.out
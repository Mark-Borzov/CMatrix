CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
FLAGS_COV = -lcheck -lgcov -fprofile-arcs --coverage
FLAGS_L = -lcheck -lm -lpthread -lrt -lsubunit

all: test

s21_matrix.a:
	$(CC) $(CFLAGS) -c s21_matrix.c s21_matrix.h
	ar rcs s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a
	rm -rf s21_matrix.o
	rm -rf s21_matrix.h.gch

clean:
	rm -rf s21_matrix
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf report
	rm -rf gcov_report.info
	rm -rf s21_matrix.o
	rm -rf s21_matrix.h.gch
	rm -rf s21_matrix.a
	rm -rf test
	rm -rf CMatrix.zip

test: clean s21_matrix.a
	$(CC) tests_s21_matrix.c s21_matrix.a $(FLAGS_L) -o test
	./test

gcov_report:
	$(CC) tests_s21_matrix.c s21_matrix.c $(FLAGS_L) -o test $(FLAGS_COV)
	./test
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info;
	open report/index.html
	rm -rf *.gcda
	rm -rf *.gcno

dist:
	zip -r CMatrix.zip Makefile README.md s21_matrix.c s21_matrix.h tests_s21_matrix.c
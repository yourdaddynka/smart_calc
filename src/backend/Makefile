CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
GCOVFLAGS:=-fprofile-arcs -ftest-coverage
LDFLAGS:=-lcheck -lgcov -fprofile-arcs --coverage
ifeq ($(shell uname), Linux)
LDFLAGS +=-lpthread -lrt -lm -lsubunit
endif

SRC:= $(wildcard s21_*.c)
OBJ = $(addprefix obj/,$(SRC:.c=.o))
OBJ_GCOV = $(addprefix gcov_obj/,$(SRC:.c=.o))
TEST_SRC:= $(wildcard tests/s21_*.c)
TEST_OBJ = $(addprefix tests/,$(TEST_SRC:.c=.o))

all: clean s21_smartcalc.a test

s21_smartcalc_gcov.a: $(OBJ_GCOV)
	ar -src $@ $(OBJ_GCOV) 

s21_smartcalc.a: $(OBJ)
	ar -src $@ $(OBJ) 

test: tests/s21_smartcalc_test.o s21_smartcalc_gcov.a
	$(CC) -g tests/s21_smartcalc_test.o s21_smartcalc_gcov.a -o $@ $(LDFLAGS) $(GCOVFLAGS)
	./test

gcov_report: test
	lcov -c -d gcov_obj/. -o gcov_obj/coverage.info
	genhtml gcov_obj/coverage.info --output-directory out
ifeq ($(shell uname), Linux)
	xdg-open out/index.html
else ifeq ($(shell uname), Darwin)
	open out/index.html
endif

gcov_obj/%.o: %.c
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $< -o $@

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

rebuild: clean all

rebuild_gcov: clean test gcov_report s21_smartcalc_gcov.a

clean:
	rm -f */*.o
	rm -f gcov_obj/*.gc*
	rm -f ./test
	rm -f -r out
	rm -f gcov_obj/*.info
	rm -f .DS_Store
	rm -f *.a
	rm -rf test.dSYM
	rm -f tests/*.o
	rm -f ../.DS_Store
	
clang:
	cp ../../materials/linters/.clang-format .
	clang-format -i *.c *.h tests/*.c
	cd ../frontend/s21_smartcalc/ && clang-format -i *.cpp *.h

leaks: rebuild
	leaks -atExit -- ./test

valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ./test

start: 
	cppcheck --enable=all --suppress=missingIncludeSystem mainwindow.cpp

install: uninstall
	cd ../../ && mkdir -p build
	cd ../frontend/s21_smartcalc/ && qmake && make && make clean && rm -rf Makefile && mv s21_smartcalc.app ../../../build
	cp -R ../../build/s21_smartcalc.app ~/Desktop/s21_smartcalc.app
	
uninstall:
	rm -rf ../../build
	rm -rf ~/Desktop/s21_smartcalc.app

dvi:
	cd ../ && open description.md

dist: 
	rm -rf ../Archive_calc_v1.0/
	mkdir ../Archive_calc_v1.0/
	mkdir ../Archive_calc_v1.0/src/
	mv ../../build/s21_smartcalc.app ../Archive_calc_v1.0/src/
	tar cvzf ../Archive_calc_v1.0.tgz -C ../Archive_calc_v1.0/ .
	rm -rf ../Archive_calc_v1.0/
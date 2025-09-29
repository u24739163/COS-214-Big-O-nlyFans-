
filesToDelete =  TestingMain Command ChatRoom Users
filesToCompile =  TestingMain.cpp Command.cpp ChatRoom.cpp Users.cpp Memento.cpp Caretaker.cpp
filesInCoverageReport =  TestingMain Command ChatRoom Users

main:
	g++ -g -std=c++11 ${filesToCompile} -o TestingMain

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${filesToDelete}

all:
	make clean
	make main
	clear
	./TestingMain

coverage:
	make clean
	g++ -g --coverage -dumpbase '' ${filesToCompile} -o main
	./main > outputXD.txt
	gcov -f -m -r -j ${filesInCoverageReport} > coverage.txt 
	gcovr --html-details output.html
	#make clean

valgrind:
	make clean
	make
	valgrind --track-origins=yes --leak-check=full --keep-stacktraces=alloc-and-free --error-exitcode=1 --log-file=valgrind.txt ./TestingMain > output.txt

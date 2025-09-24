
filesToDelete = TestingMain PizzaComponent Pizza Order Menus State 
filesToCompile = TestingMain.cpp PizzaComponent.cpp Pizza.cpp State.cpp Order.cpp DiscountStrategy.cpp Menus.cpp 
filesInCoverageReport = TestingMain PizzaComponent Pizza Order DiscountStrategy Menus State 

main:
	g++ -g -std=c++11 ${filesToCompile} -o TestingMain

clean:
	rm *.o *.gcov *.gcda *.gcno *.gz *.html *.css output.txt coverage.txt -f ${filesToDelete}

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

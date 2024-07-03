all: ./a.out

compRun:
	g++ -std=c++11 main.cpp boutique.cpp BoutiqueManager.cpp inventory.cpp female.cpp male.cpp children.cpp product.cpp sweeper.cpp cashier.cpp salesman.cpp customer.cpp employee.cpp -o r.out



run: clean compRun; ./r.out

clean:
	rm -f *.out



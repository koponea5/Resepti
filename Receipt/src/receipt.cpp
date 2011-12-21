/*
 * Receipt.cpp
 *
 *  Created on: 21.12.2011
 *      Author: koponea5
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "receipt.h"

using namespace std;

class receipt {
	vector<Product> vee;

public:
	receipt();
	receipt(const Product &product);
	receipt(std::vector<Product> product);
	~receipt();
	void add(const Product &product);
	void remove();
	void print();
	void receiptTest();
};


receipt::receipt(const std::vector<Product> products) {
	this->vee = products;
}
receipt::receipt(const Product &product) {
	this->vee.push_back(product);
}
receipt::receipt() { // in case we wish to put something in here, bu not needed
}
receipt::~receipt() {
}

// adding the product
void receipt::add(const Product &pr) {
	//Product pr;
//	pr.name = tuotedatat[0];
//	pr.price = tuotedatat[1];
//	pr.quantity = tuotedatat[2];
	this->vee.push_back(pr);
    cout << "Added: " << pr.quantity << " x " << pr.name << " a " << pr.price << " eur " << pr.quantity*pr.price << endl;
}
void receipt::remove() {
    if (!(this->vee.empty())) {
    vector<Product>::iterator it;
    it=vee.end()-1;
    cout << "Removed: " << it->quantity << " x " << it->name << " a " << it->price << " eur " << it->quantity*it->price << endl;
   	this->vee.pop_back();
    }
    else {
    	cout << "Error: nothing to remove" << endl;
    }
}
void receipt::print() {
	    vector<Product>::iterator it;
	    if (!(this->vee.empty())) {
				double Total = 0.0;
				  for ( it=vee.begin() ; it < vee.end(); it++ ){
					double subTotal = it->quantity*it->price;
				    cout << it->quantity << " x " << it->name << " a " << it->price << " eur " << subTotal << endl;
				    Total += subTotal;
				  }
				  cout << "Total price: " << Total << " eur" << endl;
	    }

}


//testataan reseptia
void receiptTest() {
	string prods = "jeppe 1.0 5";
    Product prod;
    Product prod2;
    prod.name = "Teppo";
    prod.price = 15.1;
    prod.quantity = 4;
    prod2.name = "seppo";
    prod2.price = 11.1;
    prod2.quantity = 1;
    Product prod3;

    vector<Product> testVector;

    testVector.push_back(prod);
    testVector.push_back(prod2);


    receipt rese = testVector;

    rese.print();

    rese.remove();
    rese.print();

    rese.add(prod2);
    rese.print();
    rese.remove();
    rese.remove();
    rese.remove();

}

int main(void) {

	//receiptTest();
	receipt res1;
	Product prod;
	string str;
	int i = 1;
	cout << "COMMANDS: ADD, REMOVE, PRINT, QUIT" << endl;
	while(i==1) {
		cout << "Enter command:" << endl;
		cin >> str;
		if(str=="REMOVE") {
			res1.remove();
		} else if(str=="QUIT") {
			i=0;
		} else if(str=="ADD") {
			cout << "Enter product information (<name> <price> <quantity>):" << endl;
			cin >> prod.name;
			cin >> prod.price;
			cin >> prod.quantity;
			res1.add(prod);
			//luetaan!!
		} else if(str=="PRINT") {
			res1.print();
		} else {
			cout << "Error: Invalid command" << endl;
		}

	}
	return 0;
}

/*
 * Receipt.cpp
 *
 *  Created on: 21.12.2011
 *      Author: koponea5
 */
#include "receipt.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

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
}
void receipt::remove() {
    if (!(this->vee.empty())) {
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

int main(void) {
    Product prod;
    Product prod2;
    prod.name = "Teppo";
    prod.price = 15.1;
    prod.quantity = 4;
    prod2 = {"seppo", 11.1, 1};
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



	return 0;
}

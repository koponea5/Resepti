#ifndef ELEC_AS_CPP_U1E1
#define ELEC_AS_CPP_U1E1

#include <string>
#include <iostream>
#include "receipt.h"
#include <vector>

using namespace std;

/* Product structure */
struct Product
{
	std::string name;
	double price;
    int quantity;
};

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
};
//const char *receipt::talk() {
//	int sentence = rand() % repertoire.size();
//	return repertoire[sentence].c_str();
//}





#endif


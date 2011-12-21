#ifndef ELEC_AS_CPP_U1E1
#define ELEC_AS_CPP_U1E1

#include <string>
#include <stdio>
#include "receipt.h"
#include <cstdlib>

using namespace std;

/* Product structure */
struct Product
{
	std::string name;
	double price;
    int quantity;
};


receipt::receipt(const char *n, const char *c)
{
	string phrase(n);
	phrase += " wanna cracker!";
	name = n;
	color = c;
	repertoire.push_back(phrase);
}

receipt::~receipt()
{
}

void receipt::add(const char *phrase) {
}
void receipt::remove(const char *phrase) {
}
void receipt::print(const char *phrase) {
}
void receipt::quit(const char *phrase) {
}

//const char *receipt::talk() {
//	int sentence = rand() % repertoire.size();
//	return repertoire[sentence].c_str();
//}





#endif


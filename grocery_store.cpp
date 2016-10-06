#include "grocery_store.hpp"

GroceryStore::GroceryStore(unsigned int timeToBeSimulated,
		unsigned int paceToCreateClients):
	timeToBeSimulated_{timeToBeSimulated}
	paceToCreateClients_{paceToCreateClients}
{}

void GroceryStore::simulate() {
	while (timePassed < timeToBeSimulated_) {
		for (unsigned int i = 0; i < numberOfClients; ++i) {
			cashierList.next().update();
		}
		if (timePassed % paceToCreateClients_ == 0) {
			createClient();
		}
		++timePassed;
	}
}

void GroceryStore::createClient() {
	// TODO Generate client and add to the correct cashier
}


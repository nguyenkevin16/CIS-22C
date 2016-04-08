/*
		Kevin Nguyen 20157997
		Ka U Leong
		CIS 22C - Data Structures, Spring 2016; 3:30 PM
		Extra Credit 1

		This program tests the functionality of the PlainBox, MagicBox, and ToyBox classes
		through the BoxInterface abstract class.
*/


#include <iostream>
#include <string>
#include "PlainBox.h"
#include "ToyBox.h"
#include "MagicBox.h"
#include "BoxInterface.h"

using namespace std;

int main() {
	
	string colors[] = { "BLACK", "RED", "BLUE", "GREEN", "YELLOW", "WHITE" };

	BoxInterface<string> *ptr3 = new ToyBox<string>("hello", RED);
	cout << ptr3->getItem() << endl;

	system("pause");
	return 0;
}
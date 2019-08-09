#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

bool intOverflowAddition (int intA, int intB) {
	if (intA > (INT_MAX - intB)) { return false;  }
	else { return true;  }
}

int addThemInts(vector<int> &arrayInt) {
	int intReturn = 0;

	for (int intElement : arrayInt) {
		if (intOverflowAddition(intReturn, intElement)) { intReturn += intElement; }
		else {
			intReturn = 0;
			break;
		}
	}

	return intReturn;
}

int main(int argc, char *argv[]) {
	int intResult = 0;
	int intIndex = 0;
	int intRandom = 0;
	vector<int> arrayOfInt;

	srand((unsigned int)time(NULL));

	cout << "Integers: ";
	for (intIndex = 0; intIndex < 10; intIndex++) {
		if (intIndex > 0) { cout << ", ";  }

		intRandom = (rand() % INT_MAX) + 1;

		arrayOfInt.push_back(intRandom);

		cout << intRandom;
	}
	cout << endl;
	
	intResult = addThemInts(arrayOfInt);
	if (intResult == 0) { cout << "Result: Integer Overflow." << endl; }
	else { cout << "Result: " << intResult << endl; }

	// and on multi attempts (looping whole random setup, display, addition)
	// arrayOfInt.clear();

	return 0;
}
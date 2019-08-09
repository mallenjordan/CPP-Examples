#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#define ARRAY_INT_INDEX_COUNT 20

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
	for (intIndex = 0; intIndex < ARRAY_INT_INDEX_COUNT; intIndex++) {
		if (intIndex > 0) { cout << ", ";  }

		// Commented out because RAND_MAX is garunteed to be at least 32767.
		// This value being smaller than INT_MAX (2147483647) will not overflow the integer.
		// I had to durring testing push the ARRAY_INT_INDEX_COUNT past 160,000 integers to get a overflow.
		//intRandom = (rand() % INT_MAX) + 1;
		//
		// So instead we just go with rand() + 1 to push 1 through 32767
		intRandom = (rand() + 1);

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

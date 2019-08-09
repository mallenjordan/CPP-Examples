#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Lets make some permutate fun.
// Warning: Recursion ahead.
void permutate (vector<string> &strArray, string strBuffer, int intStart, int intEnd) {
	int intIndex = 0;
	if (intStart == intEnd) { 
		strArray.push_back(strBuffer);
	}
	else {
		// Time to split the permutations.
		for (intIndex = intStart; intIndex <= intEnd; intIndex++) {

			// Swapping letters.
			swap (strBuffer[intStart], strBuffer[intIndex]);

			// Recursion called  
			permutate (strArray, strBuffer, intStart + 1, intEnd);

			// Swap letters back.
			swap (strBuffer[intStart], strBuffer[intIndex]);
		}
	}
}

// Driver Code
int main() {
	string strBuffer;
	vector<string> strArray;
	bool bMatchFound = false;
	int intIndexA = 0, intIndexB = 0;

	cout << "Warning: This is exponential recursive processing.." << endl;
	cout << "Meaning more letters, longer times!" << endl;
	cout << "Enter a string: ";
	getline(cin, strBuffer);
	cout << endl;

	int intBufferSize = strBuffer.size();

	permutate (strArray, strBuffer, 0, intBufferSize - 1);

	// Cleaning up the multiples.
	// Any string with multiple letters matching will duplicated the result permutations.
	for (intIndexA = 0; intIndexA < (int) strArray.size(); intIndexA++) {
		for (intIndexB = intIndexA + 1; intIndexB < (int) strArray.size(); intIndexB++) {
			if (strArray[intIndexA].compare(strArray[intIndexB]) == 0) { bMatchFound = true; break; }
		}
		if (bMatchFound) { strArray.erase(strArray.begin() + intIndexA); bMatchFound = false; }
	}

	cout << "Number of Permutates: " << strArray.size() << endl;
	/*
	for (string strElement : strArray) {
		cout << strElement << endl;
	}
	*/

	return 0;
}
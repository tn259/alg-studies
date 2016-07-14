#include <fstream>
#include <iostream>
#include <algorithm>
#include "../include/helpers.hpp"
#include "../src/InversionCounter.hpp"
#include "../src/QuickSortComparisonCounter.hpp"

namespace algsprocesses {
	//implement helper functions here
	const vector<int> arrayFileToVectorInt(const string& filename){
		string line;
		fstream file (filename.c_str());
		vector<int> intVector;
		if(file.is_open()) {
			while (getline(file, line)) {
				//parse string to int and pushback into vector
				intVector.push_back(stoi(line));
			}
			file.close();
		} else {
			cout << "Cannot open file";	
		}
		return intVector;	
	}	
	void print(const int n) { cout << " " << n << "\n"; }	
}

int main() {
	using namespace algsprocesses;
	const vector<int> numbers = arrayFileToVectorInt("../../IntegerArray.txt");
	//sanity check vector creation
	//for_each(numbers.begin(), numbers.end(), print);
	cout << "Number of inverions = " << InversionCounter<int>{}.countAllInv(numbers);
	const vector<int> numbers2 = arrayFileToVectorInt("../../QuickSort.txt");
	cout << "Number of QS comparisons 1 = " << QuickSortComparisonCounter<int>{}.countComparisons1(numbers2) << "\n";
	cout << "Number of QS comparisons 2 = " << QuickSortComparisonCounter<int>{}.countComparisons2(numbers2) << "\n";
	cout << "Number of QS comparisons 3 = " << QuickSortComparisonCounter<int>{}.countComparisons3(numbers2) << "\n";
	return 0;
}

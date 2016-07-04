#include <fstream>
#include <iostream>
#include "../include/helpers.hpp"
#include "../src/InversionCounter.hpp"

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

	
}

int main() {
	using namespace algsprocesses;
	cout << "QWERYT";
	const vector<int> numbers = arrayFileToVectorInt("../../numbers.txt");
	//const vector<int> numbers = vector<int>{};
	const int a = numbers.size();
	//int inversions = InversionCounter<int>().count(numbers, a);
	//cout << inversions;
	InversionCounter<int> IC = InversionCounter<int>{};
	cout <<	IC.count(numbers,a);
	return 0;
}

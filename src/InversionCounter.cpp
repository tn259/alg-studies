#include "../include/InversionCounter.hpp"

namespace algsprocesses {

 	template <typename T>
	int InversionCounter::count(const vector<T>& vec, const int vecSize){
		if (vecSize == 1) return 0;
		else {
			//use STL to pass in appropriate vector
			int x = count(.... , vecSize/2);
			int y = count(.... , vecSize/2);
			int z = countSplitInv(vec, vecSize);
			return x+y+z;
		} 	
	}

	template <typename T>
	int InversionCounter::countSplitInv(const vector<T>&, const int){
	}
}

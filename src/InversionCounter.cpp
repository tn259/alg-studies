#include "../include/InversionCounter.hpp"

namespace algsprocesses {

 	template <typename T>
	int InversionCounter::count(const std::vector<T>& vec, const int vecSize){
		if (vecSize == 1) return 0;
		else {
			//use STL to pass in appropriate vector
			int x = count(std::vector<T> firstHalf(vec.begin(), vec.begin()+vecSize/2) , vecSize/2);
			int y = count(std::vector<T> secondHalf(vec.begin()+vecSize/2+1, vec.end()) , vecSize/2);
			int z = countSplitInv(vec, vecSize);
			return x+y+z;
		} 	
	}

	template <typename T>
	int InversionCounter::countSplitInv(const std::vector<T>& vec, const int vecSize){
		std::vector<T> firstHalf(vec.begin(), vec.begin()+vecSize/2);
		std::vector<T> secondHalf(vec.begin()+vecSize/2+1, vec.end());
		//the old way...
		int f, s, inversions = 0;
		for (int i = 0; i<vecSize; i++) {
			if(firstHalf[f] < secondHalf[s]) {
				//merge..
				f++;
			} else if (secondHalf[s] < firstHalf[f]) {
				inversions += firstHalf.size() - f;
				s++
			}
		}
		return inversions;
	}
}

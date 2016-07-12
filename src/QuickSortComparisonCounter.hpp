#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

/*Template definition need to be provided in header*/

namespace algsprocesses {

template <typename T>
class QuickSortComparisonCounter {
	typedef typename std::vector<T> Vector;
	typedef typename std::vector<T>::iterator It;
	typedef unsigned long long num;
	public:
		const num countComparisons(const Vector v) {
			num comparisons = 0;
			Vector vecCopy(v);
			return (*this).sort(vecCopy, vecCopy.begin(), vecCopy.end(), vecCopy.size(), comparisons);
		}	
	private:
		const num sort(Vector& v, It b, It e, const int vecSize, num comparisons) {
			if (vecSize == 1) return comparisons;
			choosePivot(v, b, vecSize);
			It pivot = partition(v, b, e-1); //left and right iterators inclusive
			comparisons += vecSize - 1; //pivot compared against all others
			sort(v, b, pivot, std::distance(b, pivot), comparisons); //everything before pivot
			sort(v, pivot+1, e, std::distance(pivot+1, e), comparisons); //everything after pivot
			//
		}
		void choosePivot(Vector& v, It b, const int vecSize) {
			//just choose first for now 
			//figure out a design for others later
			return;
		}	
		It partition(Vector& v, It left, It right) {
			It i = left+1;
			for(It j = left+1; j != right+1; j++) {
				if (*j < *pivot) {
					std::iter_swap(j,i);
					i++;
				}
			}
			std::iter_swap(left, i-1);
			return i-1;
		}
};	

}

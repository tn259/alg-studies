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
		const num countComparisons(const Vector& v) {
			num comparisons = 0;
			Vector vecCopy(v);
			for(int i=0; i<vecCopy.size(); i++) { cout << vecCopy[i] << " ";}
			std::cout << "\n";
			return (*this).sort(vecCopy, vecCopy.begin(), vecCopy.end(), vecCopy.size(), comparisons);
		}	
	private:
		const num sort(Vector& v, It b, It e, const int vecSize, num& comparisons) {
			if (vecSize < 2) return comparisons;
			choosePivot(v, b, vecSize);
			It pivot = partition(v, b, e); 
		//	for(int i=0; i<v.size(); i++) { cout << v[i] << " "; }
			comparisons += vecSize - 1; //pivot compared against all others
			std::cout << "comps= " << comparisons << "\n";
			std::cout << "\n" << std::distance(b, e) << "\n";
		//	std::cout << "b= " << *b << "  pivot= " << *pivot << "\n";
		//	std::cout << "pivot+1= " << *(pivot+1) << " e= " << *e << "\n";

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
			for(It j = left+1; j != right; j++) {
				if (*j < *left) {
					std::iter_swap(j,i);
					i++;
				}
			}
			std::iter_swap(left, i-1);
			return i-1;
		}
};	

}

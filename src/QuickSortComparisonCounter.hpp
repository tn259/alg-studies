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
	typedef	void (*PivotMethod) (Vector&, It, const int);
	public:
		const num countComparisons1(const Vector& v) {
			num comparisons = 0;
			Vector vecCopy(v);
			return (*this).sort(vecCopy, vecCopy.begin(), vecCopy.end(), vecCopy.size(), comparisons, choosePivotFirst);
		}
		const num countComparisons2(const Vector& v) {
			num comparisons = 0;
			Vector vecCopy(v);
			return (*this).sort(vecCopy, vecCopy.begin(), vecCopy.end(), vecCopy.size(), comparisons, choosePivotLast);
		}
		const num countComparisons3(const Vector& v) {
			num comparisons = 0;
			Vector vecCopy(v);
			return (*this).sort(vecCopy, vecCopy.begin(), vecCopy.end(), vecCopy.size(), comparisons, choosePivot3Median);
		}
	
	private:
		const num sort(Vector& v, It b, It e, const int vecSize, num& comparisons, PivotMethod f) {
			if (vecSize < 2) return comparisons;
			f(v, b, vecSize);
			It pivot = partition(v, b, e); 
		//	for(int i=0; i<v.size(); i++) { cout << v[i] << " "; }
			comparisons += vecSize - 1; //pivot compared against all others
		//	std::cout << "b= " << *b << "  pivot= " << *pivot << "\n";
		//	std::cout << "pivot+1= " << *(pivot+1) << " e= " << *e << "\n";
			sort(v, b, pivot, std::distance(b, pivot), comparisons, f); //everything before pivot
			sort(v, pivot+1, e, std::distance(pivot+1, e), comparisons, f); //everything after pivot
		}
		static void choosePivotFirst(Vector& v, It b, const int vecSize) {
			return;
		}
		static void choosePivotLast(Vector& v, It b, const int vecSize) {
			std::iter_swap(b, b+vecSize-1);
			return;	
		}
		static void choosePivot3Median(Vector&, It b, const int vecSize) {
			It last = b+vecSize-1;
			It mid = vecSize % 2 == 0 ? b+(vecSize/2)-1 : b+(vecSize-1)/2;
			if(*b==*mid && *last>*b) {
				std::iter_swap(b, last);
				return;
			}
			if(*b < *mid && *mid < *last) { 
				std::iter_swap(b, mid);
				return;
			}
			if(*b > *mid && *mid > *last) {
				std::iter_swap(b, mid);
				return;
			}
			if(*last < *b && *b < *mid) return;
			if(*last > *b && *b > *mid) return;
			if(*mid < *last && *last < *b) {
				std::iter_swap(b, last);
				return;
			}
			if(*mid > *last && *last > *b) {
				std::iter_swap(b, last);
				return;
			}
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

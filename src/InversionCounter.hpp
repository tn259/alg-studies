#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

/*Template definition need to be provided in header*/

namespace algsprocesses {

template <typename T>
class InversionCounter {
	typedef typename std::vector<T> Vector;
	typedef typename std::vector<T>::iterator It;
	public:
		const int countAllInv(const Vector& vec) {
			Vector vecCopy(vec);
			It b = vecCopy.begin();
			It e = vecCopy.end();
			return (*this).count(vecCopy, b, e, std::distance(b, e));

		} 
	private:
		int count(Vector& vec, It b, It e, const int vecSize) {
			if (vecSize == 1) return 0;
			else {
				//use STL to pass in appropriate vector
				int x = count(vec, b, b+vecSize/2, std::distance(b, b+vecSize/2));
				int y = count(vec, b+vecSize/2, e, std::distance(b+vecSize/2, e));
				int z = countSplitInv(vec, b, e, std::distance(b,e));
				return x+y+z;
			}
		}	
		int countSplitInv(Vector& vec, It b, It e,const int vecSize) {
			Vector firstHalf(b, b+vecSize/2);
			Vector secondHalf(b+vecSize/2, e);
			int firstSize = firstHalf.size(), secondSize = secondHalf.size();
			//the old way...
			int f = 0, s = 0, inversions = 0;
			for (int i = 0; i<vecSize; i++) {
				//assume elements all distinct
				if(f==firstSize && s==secondSize) {
					break;
				} else if (f==firstSize) {
					*b = secondHalf[s];
					s++;
				} else if (s==secondSize) {
					*b = firstHalf[f];
					f++;
				} else if(firstHalf[f] < secondHalf[s]) {
				//piggyback on merge step..
					*b = firstHalf[f];
					f++;
				} else if (secondHalf[s] < firstHalf[f]) {
					inversions += firstSize - f;
					*b = secondHalf[s];
					s++;
				}
				b++;
			}
			return inversions;
		}
};


}

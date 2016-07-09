#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

/*Template definition need to be provided in header*/

namespace algsprocesses {

template <typename T>
class InversionCounter {
	typedef typename std::vector<T>::iterator It;
	public:
		const int countAllInv(const std::vector<T>& vec) {
			typename std::vector<T> vecCopy(vec);
			typename std::vector<T>::iterator b = vecCopy.begin();
			typename std::vector<T>::iterator e = vecCopy.end();
			//return (*this).count(vecCopy, b, e, vecCopy.size());
			int n =  (*this).count(vecCopy, b, e, std::distance(b,e));
			for(int i = 0; i<vecCopy.size(); i++) std::cout << vecCopy[i] << "\n";
			return n;

		} 
	private:
		int count(std::vector<T>& vec, It b, It e, const int vecSize) {
			if (vecSize == 1) return 0;
			else {
				//use STL to pass in appropriate vector
				int x = count(vec, b, b+vecSize/2, vecSize/2);
				int y = count(vec, b+vecSize/2, e, vecSize/2);
				int z = countSplitInv(vec, b, e, std::distance(b,e));
				return x+y+z;
			}
		}	
		int countSplitInv(std::vector<T>& vec, It b, It e,const int vecSize) {
			typename std::vector<T> firstHalf(b, b+vecSize/2);
			typename std::vector<T> secondHalf(b+vecSize/2, e);
			//the old way...
			std::cout << "first size= " << firstHalf.size() << "  second size= " << secondHalf.size() << "\n";
			std::cout << "first[0]= " << firstHalf[0] << " second[0]= " << secondHalf[0] << "\n";
			int f = 0, s = 0, inversions = 0;
			for (int i = 0; i<vecSize; i++) {
				//assume elements all distinct
				if(f==firstHalf.size() && s==secondHalf.size()) {
					break;
				} else if (f==firstHalf.size()) {
					*b = secondHalf[s];
					s++;
				} else if (s==secondHalf.size()) {
					*b = firstHalf[f];
					f++;
				} else if(firstHalf[f] < secondHalf[s]) {
				//piggyback on merge step..
					*b = firstHalf[f];
					f++;
				} else if (secondHalf[s] < firstHalf[f]) {
					inversions += firstHalf.size() - f;
					*b = secondHalf[s];
					s++;
				}
				b++;
				//std::cout << "f=" << f << " s=" << s << "\n";
				//std::cout << "firstHalf[f]= " << firstHalf[f] << " secondHalf[s] = " << secondHalf[s] << "\n";
			}
		//	std::cout << inversions << "  ";
			for(int i = 0; i<vec.size(); i++) std::cout << vec[i] << "\n";
			std::cout << "\n";
			return inversions;
		}
};


}

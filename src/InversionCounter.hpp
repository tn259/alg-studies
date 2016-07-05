#include <vector>
#include <algorithm>

/*Template definition need to be provided in header*/

namespace algsprocesses {

template <typename T>
class InversionCounter {
	public:
		int count(const std::vector<T>& vec, const int vecSize) {
			if (vecSize == 1) return 0;
			else {
				//use STL to pass in appropriate vector
				typename std::vector<T> firstHalf(vec.begin(), vec.begin()+vecSize/2); 
				int x = count(firstHalf, firstHalf.size());
				typename std::vector<T> secondHalf(vec.begin()+vecSize/2, vec.end());
				int y = count(secondHalf, secondHalf.size());
				int z = countSplitInv(vec, vec.size());
				return x+y+z;
			}
		}	 
	private:	
		int countSplitInv(const std::vector<T>& vec, const int vecSize) {
			typename std::vector<T> firstHalf(vec.begin(), vec.begin()+vecSize/2);
			typename std::vector<T> secondHalf(vec.begin()+vecSize/2, vec.end());
			//the old way...
			int f = 0, s = 0, inversions = 0;
			for (int i = 0; i<vecSize; i++) {
				//assume elements all distinct
				if(firstHalf[f] < secondHalf[s]) {
				//piggyback on merge step..
				f++;
				} else if (secondHalf[s] < firstHalf[f]) {
					inversions += firstHalf.size() - f;
					s++;
				}
			}
			return inversions;
		}
};


}

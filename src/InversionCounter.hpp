#include <vector>

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
				int x = count(firstHalf, vecSize/2);
				typename std::vector<T> secondHalf(vec.begin()+vecSize/2+1, vec.end());
				int y = count(secondHalf , vecSize/2);
				int z = countSplitInv(vec, vecSize);
				return x+y+z;
			}
		}	 
	private:	
		int countSplitInv(const std::vector<T>& vec, const int vecSize) {
			//core dump happening here....
			typename std::vector<T> firstHalf(vec.begin(), vec.begin()+vecSize/2);
			typename std::vector<T> secondHalf(vec.begin()+vecSize/2+1, vec.end());
			//the old way...
			int f, s, inversions = 0;
			for (int i = 0; i<vecSize; i++) {
				if(firstHalf[f] < secondHalf[s]) {
				//merge..
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

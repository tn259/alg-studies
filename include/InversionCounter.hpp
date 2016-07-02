#include <vector>

namespace algsprocesses {

template <typename T>
class InversionCounter {
	public:
		int count(const vector<T>&, const int);
	private:	
		int countSplitInv(const vector<T>&, const int);
};

}

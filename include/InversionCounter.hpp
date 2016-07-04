#include <vector>

namespace algsprocesses {

template <typename T>
class InversionCounter {
	public:
		int count(const std::vector<T>&, const int);
	private:	
		int countSplitInv(const std::vector<T>&, const int);
};

}

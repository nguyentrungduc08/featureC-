#include "../define.h"

using namespace std;

template<typename T>
T Max(T x, T y){
	cout << typeid(T).name() << endl;
	return x > y ? x : y;
}

int main(){
	Max(1,5);
	Max(1.1f, 3.5f);
	return 0;
}

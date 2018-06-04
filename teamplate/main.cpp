#include "../define.h"

using namespace std;

template<typename T>
T Max(T x, T y){
	cout << typeid(T).name() << endl;
	return x > y ? x : y;
}


int main(){
	cout << max <int> (1.1f, 3.1f) << endl;
	//call typename equal 'int'
	cout << Max(1,1) << endl;  // int 1
	cout << Max(1,1) << endl;  // int 1
	cout << Max(1,1) << endl;  // int 1

	//call typename equal 'float'
	cout << Max(1.1f, 3.5f) << endl; // float 3.5
	cout << max <float> (1.1f, 1.0f) << endl; 
	cout << Max(1.1f, 3.5f) << endl;
	//
	cout << max <int> (1.1f, 3.1f) << endl;

	cout << max <int> (1.1f, 3.1f) << endl;
	cout << max <int> (1.1f, 3.1f) << endl;
	cout << max <int> (1.1f, 3.1f) << endl;
	cout << max <float> (1.1f, 1.0f) << endl; 
	cout << max <float> (1.1f, 1.0f) << endl;
	cout << max <float> (1.1f, 1.0f) << endl; 
	cout << max <float> (1.1f, 1.0f) << endl; 
	return 0;
}

#include "../define.h"
#include <bitset>
using namespace std;
/*
*/

#define FFALIGN(x, a) (((x)+(a)-1)&(~((a)-1)))


int main(){
	int x = 14;
	int a = 10;
	cout <<	(int)((x+a-1)&(~(a-1))) << endl;
 	
	cout << std::bitset<32>(x) << endl;
	cout << std::bitset<32>(a) << endl;
	cout << std::bitset<32>(x + a - 1) << endl;
	cout << std::bitset<32>(a - 1) << endl;
	cout << std::bitset<32>(~(a - 1)) << endl;
	int tem1 = (x + a -1);
	int tem2 = ~(a-1);
	cout << "tem1 = " << std::bitset<32>(tem1) << endl;  
	cout << "tem2 = " << std::bitset<32>(tem2) << endl;
	cout << std::bitset<32>(tem1 & tem2) << endl;
	
	cout << FFALIGN(x,a) << endl; 
	
	return 0;
}

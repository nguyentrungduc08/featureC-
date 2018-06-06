#include "../define.h"
#include <bitset>
using namespace std;
/*
*/

class MailNotificationService {
public: 
	void notify(string to, string subject, string body){
		//logic send email to user 
	};
};

class Account {
public: 
	string email;
	string phone;

	void transfer() {
		//logic verify user
		// ...
		this->notifyTransferMoney();
	};

	void notifyTransferMoney() {
		
		
	};
	
};

#define FFALIGN(x, a) (((x)+(a)-1)&~((a)-1))


int main(){
	int x = 14;
	int a = 13;	
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

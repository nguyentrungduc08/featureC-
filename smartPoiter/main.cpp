#include "../define.h"

using namespace std;

float n, s, v, vs;

float tRest = 0.0;

int main(){
	freopen("test.txt", "r", stdin);

	cin >> n >> s >> v >> vs;

	//cout << "max: " << s/vs << endl;
	float maxT = s/vs;

	float x;
	while (n>4){
		x = (v*v*s + v*vs*s) / (v*v + 2*v*vs - vs*vs);
		tRest += x/v + (s-x)/vs;
	       	s -= vs*(x/v) + (s-x);	
		n -= 4;
		cout << "tRest " << tRest << endl;
	}

	if (n>0){
		tRest += s/v;	
	}	

	if (tRest < maxT)
		cout << tRest << endl;
	else 
		cout << maxT << endl;
	return 0;
}

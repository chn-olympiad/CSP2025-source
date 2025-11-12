#include <iostream>
#include <fstream>
#include <algorithm>

typedef int Int;
using namespace std;

Int poe(Int A, Int B){
	if(B == 1) return 1;
	if(B == 2) return A * A %  998244353LL;
	Int T = poe(A * A, B / 2) %  998244353LL;
	return T %  998244353LL * T * (B % 2 == 0 ? 1 : A) %  998244353LL;
}

int main(){
	ifstream Q;
	Q.open("employ.in", istream::in);
	Int M, N, Men[600] = {}, Ans = 1;
	string P;
	Q >> N >> M >> P;
	for(Int i = 0;i < N;i ++){
		Q >> Men[i];
	}
	sort(Men, Men + N + 1);
	for(Int i = 0, count = 0, j = 0;i < P.size();i ++){
		if(Men[j] <= count){
			Men[j ++] = i - 1, count ++;
			if(Men[j ++] > 0)
			Ans *= Men[j - 1] * Men[j - 1] * Men[j - 1] * Men[j - 1] * Men[j - 1] * Men[j - 1];
			Ans = Ans % 998244353LL;
		}
		if(P[i] == 0) count ++;
	}
	ofstream O;
	O.open("employ.out", ostream::out);
	O << Ans;
	O.close();
	
	return 0;
}
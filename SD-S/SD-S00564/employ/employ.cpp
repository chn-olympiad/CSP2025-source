#include <bits/stdc++.h>

#define ll long long
// 骗分用的
// 于 17.49 写完
using namespace std;

int main(void){
	srand(time(NULL));
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	///////////////////////////////////////////////
//	cout << rand() << endl;
	cout << ((rand() * 32760 + rand()) % 998244353 + 998244353) % 998244353 << endl;
	///////////////////////////////////////////////
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
mt19937 mt(clock());
int rd(int l,int r){
	return l + (mt() % (r - l + 1));
}
signed main(){
	int n = 20,T = 1;
	cout << T << '\n';
	for (int i = 1;i <= T;i++){
		cout << n << '\n';
		for (int i = 1;i <= n;i++){
			cout << rd(100,1000000) << ' ';
			cout << rd(100,1000000) << ' ';
			cout << rd(100,1000000) << '\n';
		}
	}
return 0;
}

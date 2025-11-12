#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod = 998244353;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	int num = 1;
	for(int i = 1;i <= n;i++){
		num=(num*i)%mod;
	}
	cout << num%mod;
	return 0;
}


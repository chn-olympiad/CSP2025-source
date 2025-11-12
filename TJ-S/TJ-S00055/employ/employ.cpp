#include <bits/stdc++.h>
using namespace std;
int n,m;
int MOD = 998244353;
long long ans = 1;
string s;
int a[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int num = n;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
	}
	for(int i = n;i>=1;i--){
		ans = ans * i % MOD;
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+5,mod = 998244353;
int n,m,a[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i = 1;i <= n;++ i){
		cin>>a[i];
	}
	s = ' ' + s;
	int cnt = 0;
	for (int i = 1;i <= n;++ i){
		cnt += s[i] - '0';
	}
	if (cnt < m){
		cout<<0;
		return 0;
	}
	if (cnt == m){
		cout<<1;
		return 0;
	}
	int ans = 1;
	for (int i = 1;i <= n;++ i){
		ans = 1ll * ans * i % mod;
	}
	cout<<ans;
	return 0;
}
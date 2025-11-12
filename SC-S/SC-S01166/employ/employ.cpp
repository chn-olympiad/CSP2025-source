#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 998244353;
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> c(n+1);
	string s;
	cin >> s;
	s='$'+s;
	bool ifAllOne=true;
	for(int i=1;i<=n;i++){
		if(s[i]!='1') ifAllOne=false;
	}
	int nopatine=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		if(c[i] == 0) nopatine++;
	}
//	cout << nopatine << '\n';
	if(n-nopatine < m){
		puts("0");
	}
	else if(ifAllOne || m == 1) {
		ll result=1;
		for(int i=1;i<=n;i++){
			result = result * i % p;
		}
		cout << result << '\n';
	}
	else{
		puts("0");
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int t=1;
//	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
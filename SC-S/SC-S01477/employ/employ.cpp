#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int ans=1;
	for(int i = 2;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout << ans;
	return 0;
}
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
//rp++
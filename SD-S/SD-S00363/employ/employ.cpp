#include<bits/stdc++.h>
#define ll  long long
using namespace std;
const int xx = 500;
const ll mod = 998244353;
ll ans = 0;
int n,m;
string s;
int a[xx];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	ll t=1;
	for(int i=m;i<=n;i++){
		t = 1;
		for(int j=n;j>=i+1;j--){
			t *= j;
			t %= mod;
		}
		ans += t;
		ans %= mod;
	}
	cout << 0 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

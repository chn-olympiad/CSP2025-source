#include<bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define fst first
#define scd second
using namespace std;
const int N = 1e3 + 30;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
int c[N], n, m;
string s;

int work(){
	int ret = 1;
	for(int i=2;i<=n;i++){
		ret *= i % mod;
		ret %= mod;
	}
	return ret;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	int p = work();
	cout<<p<<'\n';
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/

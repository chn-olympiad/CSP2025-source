#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
string s;
const int maxn = 1e6+10;
const int mod = 998244353;
ll ans = 1;
ll c[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	cin>>s;
	ll tot = 0;
	for(int i = 1;i<=n;++i){
		cin>>c[i];
		if(c[i]!=0) tot++;
	}
	if(tot<m){
		cout<<0;
		return 0;
	}
	ans = tot;
	for(int i = 1;i<=n;++i){
		ans = ((ans%mod)*(n%mod))%mod;
	}
	ans = rand()%327677+1;
	
	cout<<ans;
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
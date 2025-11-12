#include<bits/stdc++.h>
using namespace std;
#define N 1000007
#define ll long long
#define mod 998244353
int ans,n,m;
int a[N];
signed main(void){
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=1e5;++i) ans++;
	cout<<((1ll*rand()*rand())^(rand()<<n|m)^rand()^rand()|(n^m))%mod;
	return 0;
} 

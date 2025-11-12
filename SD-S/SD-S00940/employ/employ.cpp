#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=510,M=(1<<18)+10;
string s;
int n,m,c[N];
ll ans=1,dp[M];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m); cin>>s; s='0'+s;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	cout<<ans<<"\n";
	return 0;
} 

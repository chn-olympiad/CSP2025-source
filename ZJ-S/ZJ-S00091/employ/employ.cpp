#include<bits/stdc++.h>
using namespace std;
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
const int mod=998244353;
int n,m,ans,a[505],f[1<<20][22];
char s[505];
inline int rmod(int x){	return x-=mod,x+(x>>31&mod);}
inline int dfs(int u,int p,int q)
{	if(u+1==(1<<n))	return p>=m;
	if(f[u][p]!=-1)	return f[u][p];
	int ans=0;
	for(int i=0;i<n;i++)	if((u&(1<<i))==0)	ans=rmod(ans+dfs(u|(1<<i),p+(s[q+1]=='1'&&q-p<a[i+1]),q+1));
	return f[u][p]=ans,ans;
}
signed main()
{	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(f,-1,sizeof f);
//	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout)
	FIO("employ");
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++)	cin>>a[i];
	cout<<dfs(0,0,0);
	return 0;
}
/*
ull a=0;
a--;
rp+=a;

%%%Outer_Horizon
%%%Nangu
%%%Rico_Demon_King
%%%yl1740
%%%lllyyykkk
%%%Rnfcr

eggs

I don't know whether I can pass the T2,but the O(k^2*n+mlogm+knlogn) might pass it
Maybe I will AFO in the CSP-S if the code of T1 and T3 can't be accepcted.
*/

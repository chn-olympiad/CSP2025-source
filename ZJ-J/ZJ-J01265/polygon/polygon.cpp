#include <bits/stdc++.h>
#define int long long
using namespace std;
const int NB=5e3+5,mod=998244353;
int n,tans=0,a[NB];
bool cmp(int sheng,int ge)
{
	return sheng>ge;
}
int ksm(int xx,int yy)
{
	int tjxres=1,kk=xx;
	while(yy>0) {
		if(yy%2==1) tjxres=tjxres*kk%mod;
		yy/=2;
		kk=kk*kk%mod;
	}
	return tjxres;
}
void dfs(int lev,int stsum,int maxd,bool ff)
{
	if(lev==n+1 || ff) {
		if(stsum>2*maxd) tans=(tans+ksm(2,n+1-lev))%mod;
		return ;
	}
	if(2*maxd<stsum) ff=true;
	dfs(lev+1,stsum+a[lev],max(maxd,a[lev]),ff);
	dfs(lev+1,stsum,maxd,ff);
	return ;
}
signed main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	dfs(1,0,0,false);
	cout<<tans;
	return 0;
}

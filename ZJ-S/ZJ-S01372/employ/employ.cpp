#include <bits/stdc++.h>
using namespace std;
const long long N=600,mod=998244353;
long long n,m,c[N],sum=1,ans,p[N],kk,biao[N],fl[N],qian[N],qq[N],oi;
string a;
void dfs(int x,int as,int mm){
	if(mm>=m){
		ans=ans+qq[n-x+1];
		ans%=mod;
		return;
	}
	if(n-as<m) return;
	for(int i=1;i<=n;i++){
		if(fl[i]==0){
			fl[i]=1;
			biao[x]=i;
			if(c[biao[x]]<=as||a[x-1]=='0')dfs(x+1,as+1,mm);
			else dfs(x+1,as,mm+1);
			fl[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	cin>>a;
	for(int i=1;i<=n;i++) qian[i]=qian[i-1]+(a[i-1]=='0');
	qq[0]=1;
	for(int i=1;i<=n;i++) {qq[i]=qq[i-1]*i;qq[i]%=mod;}
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++) oi+=(c[i]=='0');
	if(oi==0&&qian[n]==0){cout<<qq[n]%mod;return 0;}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
//Ren5Jie4Di4Ling5%

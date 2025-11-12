#include<bits/stdc++.h>//64pts
#define int long long
#define INF 1145141919810
#define mod 998244353
using namespace std;
int n,a[120001],u[120001];
int ans,pmx;
int f1[120001],f2[120001];
int f3[120001],f4[120001];
void dfs(int now){
	if(now==n+1){
		int mx=0,pns=0;
		for(int i=1;i<=n;i++)
			if(u[i]){
				mx=max(mx,a[i]);
				pns+=a[i];
			}
		if(pns>mx*2)ans++;
		if(ans>mod)ans-=mod;
		return;
	}
	u[now]=0;
	dfs(now+1);
	u[now]=1;
	dfs(now+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],pmx=max(pmx,a[i]);
	if(pmx==1){
		f1[1]=2;
		for(int i=2;i<=n;i++)
			f1[i]=(f1[i-1]*2)%mod;
		f2[1]=1;
		for(int i=2;i<=n;i++)
			f2[i]=(f2[i-1]+f1[i-1])%mod;
		f3[1]=0;
		for(int i=2;i<=n;i++)
			f3[i]=(f3[i-1]+f2[i-1])%mod;
		f4[1]=0;
		for(int i=2;i<=n;i++)
			f4[i]=(f4[i-1]+f3[i-1])%mod;
		cout<<f4[n]%mod;
	}
	else{
		dfs(1);
		cout<<ans;	
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

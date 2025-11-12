#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500+10;
const int mod=998244353;
int n,m,ans=0,c[maxn],d[maxn],f[maxn][maxn],fac[maxn];
bool vis[maxn];
string s;
void dfs(int x,int y){
	if(x>n){
		if(y>=m) ans++;
		if(ans>=mod) ans-=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int t=y;
			vis[i]=true;
			if(s[x-1]=='1' && c[i]>x-t-1) y++;
			dfs(x+1,y);
			vis[i]=false;
			if(s[x-1]=='1' && c[i]>x-t-1) y--;
		}
	}
	return ;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; fac[0]=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		d[c[i]]++;
		fac[i]=(fac[i-1]*i)%mod;
	}
	if(m==1){
		int cnt=0;
		ans=1;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0') continue;
			int pcnt=0;
			for(int j=1;j<=n;j++) if(c[j]<i) pcnt++;
			ans=(ans*(pcnt-cnt))%mod; cnt++;
		}
		ans=(ans*fac[n-cnt])%mod;
		printf("%lld\n",((fac[n]-ans)%mod+mod)%mod);
	} else if(m==n){
		int ok=1;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0' || c[i]==0){
				ok=0;
				break;
			}
		}
		if(!ok) printf("0\n");
		else printf("%lld\n",fac[n]);
	} else if(n<=10){
		dfs(1,0);
		printf("%lld\n",ans);
	} else {
		f[0][0]=1;
		for(int i=1;i<=n;i++) d[i]+=d[i-1];
		for(int i=1;i<=n;i++){
			for(int j=1,ok=1;j<=i;j++){
				for(int k=i-1;k>=0;k--) f[i][j]=(f[i][j]+(f[k][j-1]*(d[j-1]-j+1))%mod)%mod;
				if(j>n-m) ans=((ans+(ok*(f[i][j]*fac[n-j])%mod)%mod)%mod+mod)%mod,ok=-ok;
			}
		}
		printf("%lld\n",((fac[n]-ans)%mod+mod)%mod);
	}
	return 0;
}
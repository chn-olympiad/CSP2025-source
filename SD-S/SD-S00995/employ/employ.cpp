#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e5+5,mod=998244353;
char ch;
bool f[N],is[N];
int n,m,c[N],fac[N]={0,1},sum[N],ans,t[N],tot;
void init(){
	for(int i=2;i<=505;i++){
		fac[i]=((fac[i-1]%mod)*(i%mod))%mod;
	}
}
void dfs(int xth,int now){
	if(now+sum[n]-sum[xth-1]<m){
		return;
	}
	if(xth==n+1){
		ans=(ans+(now>=m))%mod;
		return;
	}
	if(now==m){
		ans=(ans+fac[n-xth+1])%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(is[i]==0){
			is[i]=1;
			dfs(xth+1,now+(f[xth]==1&&c[i]>xth-now-1));
			is[i]=0; 
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		cin>>ch;
		f[i]=(ch=='1'),sum[i]=sum[i-1]+f[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m>sum[n]){
		ans=0;
	}else if(m==n){
		ans=(sum[n]==n?0:1);
	}else if(m==1){
		sort(c+1,c+n+1);
		int pos=1;
		for(int i=1;i<=n;i++){
			if(f[i]){
				while(pos<=n&&c[pos]<i-1){
					pos++;
				}
				ans=(ans+(fac[n-1]%mod)*(n-pos+1)%mod)%mod;
			}
		}
	}else{
		dfs(1,0);
	}
	cout<<ans;
	return 0;
}


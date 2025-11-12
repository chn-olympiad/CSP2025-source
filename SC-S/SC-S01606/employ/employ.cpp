#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,m1,s[512],c[512],b=1,vis[512];
string z;
long long ans=0;
void dfs(int x,int r){
	if(x==n+1){if(r>=m) ans++,ans%=mod;return ;}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]++;
		if(s[x]&&c[i]>(x-1-r)) dfs(x+1,r++);
		else dfs(x+1,r);
		vis[i]--;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);cin>>z;m1=m;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		s[i]=z[i-1]-'0';
		if(!s[i]) b=0,m1++;
		if(!c[i]) m1++;
	}
	if(m1>n){printf("0");return 0;}
	if(b){ 
		ans=1;
		for(long long i=2;i<=n;i++) ans=(ans*i)%mod;
		printf("%lld",ans);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
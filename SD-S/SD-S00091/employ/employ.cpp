#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,c[505],pp[505],ff[505],f[505][505],KKKK[505];
bool vis[505];
char s[505];
long long dfs(int u,int cnt){
	if(u==n+1){
		if(cnt>=m)
			return 1;
	}
	if(cnt>=m){
//		long long sum=1;
//		for(int i=1;i<=n-u+1;i++)
//			sum=(1ll*sum*i)%998244353;
		return KKKK[n-u+1];
	}
	if(s[u]=='0'){
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				sum=(sum+dfs(u+1,cnt))%998244353;
				vis[i]=0;
			}
		}
		return sum;
	}else{
		long long sum=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				if(c[i]>u-1-cnt){
					sum=(dfs(u+1,cnt+1)+sum)%998244353;
				}else{
					sum=(sum+dfs(u+1,cnt))%998244353; 
				}
				vis[i]=0;
			}
		}
		return sum;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,(s+1));
	KKKK[0]=1;
	for(int i=1;i<=n;i++)
		KKKK[i]=(1ll*KKKK[i-1]*i)%998244353;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++)
		if(s[i]=='1'){
			cnt++;
		}
	if(cnt==n){
		long long ans=1;
		for(int i=1;i<=n;i++)
			ans=(1ll*ans*i)%998244353;
		printf("%lld",ans);
		return 0;
	}
	if(m==n){
		puts("0");
		return 0;
	}
	printf("%lld",dfs(1,0));
	return 0;
}
/*
 */

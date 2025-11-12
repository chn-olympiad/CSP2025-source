#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505],pl[505],vis[505],ans;
char s[505];
void check(){
	int wl=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||wl>=a[pl[i]])wl++;
	}
	if(n-wl>=m){
		ans=(ans+1)%mod;
	}
}
void dfs(int cnt){
	if(cnt==n)check();
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		pl[cnt+1]=i;
		dfs(cnt+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				printf("0");
				return 0;
			}
		}
		int fac=1;
		for(int i=1;i<=n;i++)fac=(1ll*fac*i)%mod;
		printf("%d",fac);
		return 0;
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}
/*
3 2
101
1 1 2

*/

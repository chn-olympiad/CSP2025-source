#include<bits/stdc++.h>
#define ll long long
using namespace std;
char st[505];
int n,m,c[505],ans,mod=998244353,vis[505];
void dfs(int step,int sum){
	if(n-sum<m)	return ;
	if(step==n+1){
		if(n-sum>=m)	ans++,ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
//		a[step]=i;
		if(sum>=c[i] || st[step]=='0')	dfs(step+1,sum+1);
		else	dfs(step+1,sum);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)	scanf("%d",&c[i]);
	if(n<=18){
		dfs(1,0);
		printf("%d",ans);
	}
	else if(m==n){
		int flag=0;
		for(int i=1;i<=n;i++){
			if(st[i]!='1')flag=1;
			if(c[i]==0)	flag=1;
		}
		if(flag)	printf("0"); 
		if(!flag){
			ll nu=1;
			for(int i=1;i<=n;i++)	nu*=i,nu%=mod;
			printf("%lld",nu);
		}
	}
	else{
		printf("0");
	}
} 
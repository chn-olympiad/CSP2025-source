#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[500+5],c[500+5];
char sc[500+5];
int vis[500+5];

int ans;
int n,m;
void dfs(int num,int xnum){
	if(num==n){
		vis[xnum]=num;
		int tt=0,lq=0;
		for(int t=1;t<=n;t++){
			if(c[vis[t]]<=tt){
				tt++;
				continue;
			}
			if(a[t]==0){
				tt++;
				continue;
			}
			lq++;
			if(lq>=m){
				continue;
			}
		}
		if(lq>=m){
			ans++;
		}
		vis[xnum]=0;
		return;
	}
	vis[xnum]=num;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(num+1,i);
		}
	}
	vis[xnum]=0;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",sc);
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		a[i]=sc[i-1]-'0';
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		dfs(1,i);
	}
	printf("%d",ans);
	return 0;
}

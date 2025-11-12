#include <bits/stdc++.h>
using namespace std;
int n,m,a[1100000],c[1100000];
int ans=0;
int vis[1100000];
string str; 
void dfs(int x,int d,int p,int re){
	//printf("%d %d %d %d\n",x,d,p,re);
	vis[x]=1;
	if(re>=c[x]){
		for(int i=1;i<=n;++i){
			if(!vis[i])dfs(i,d+1,p,re+1);
		}
	}else if(a[d]==1){
		p++;
		for(int i=1;i<=n;++i){
			if(!vis[i])dfs(i,d+1,p,re);
		}
	}else if(a[d]==0){
		for(int i=1;i<=n;++i){
			if(!vis[i])dfs(i,d+1,p,re+1);
		}
	}
	vis[x]=0;
	if(d==n && p>=m){
		ans++;
		ans%=998244353;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>str;
	for(int i=0;i<str.length();++i){
		a[i+1]=str[i]-'0';
	}
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;++i){
		dfs(i,1,0,0);
		memset(vis,0,sizeof vis);
	}
	printf("%d\n",ans);
	return 0;
}


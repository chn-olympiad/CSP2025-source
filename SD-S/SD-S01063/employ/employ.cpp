#include<iostream>
#include<cstdio>
using namespace std;
char s[20];
int c[20],p[20],used[20];
void dfs(int u,int n,int m,int &ans){
	if(u==n+1){
		int lst=0,cnt=0;
		for(int i=1;i<=n;++i){
			if(s[i-1]=='1')++lst;
			else{
				if(lst>=c[p[i]])++lst;
				else ++cnt;
			}
		}
		if(cnt>=m)++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!used[i]){
			p[u]=i;
			used[i]=1;
			dfs(u+1,n,m,ans);
			used[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	cin>>(s+1);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	int ans=0;
	dfs(1,n,m,ans);
	printf("%d",ans);
	return 0;
}

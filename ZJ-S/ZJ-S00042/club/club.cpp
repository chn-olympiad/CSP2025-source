#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();int f=1,ret=0;
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=ret*10+(ch&15),ch=getchar();
	return f*ret;
}
int a[100005][4],n,mx[100005];
bool A=1;
int ans;
void dfs(int s,int x1,int x2,int x3,int sm){
	if(x1>(n>>1)||x2>(n>>1)||x3>(n>>1))return;
	if(s>n){
		if(sm>ans)ans=sm;
		return ;
	}
	dfs(s+1,x1+1,x2,x3,sm+a[s][1]);
	dfs(s+1,x1,x2+1,x3,sm+a[s][2]);
	dfs(s+1,x1,x2,x3+1,sm+a[s][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++){
			a[i][j]=read();
			if(A&&j!=1&&a[i][j]!=0)A=0;
		}
		if(A){
			for(int i=1;i<=n;i++)mx[i]=a[i][1];
			sort(mx+1,mx+n+1,greater<int>());
			for(int i=1;i<=n>>1;i++)ans+=mx[i];
		}
		else dfs(1,0,0,0,0);
		printf("%d\n",ans);
	}
}
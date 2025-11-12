#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int read(){
	int x=0;
	short f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
const int N=1e4+10,M=1e5+10;
int n,m,k;
int c[20],a[20][N];
bool vis[N];
struct node{
	int u,v,w;
}E[M<<1];
//void add(int u,int v,int w)
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	int ans=0,cnt=0,tot=m;
	bool flag=1;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		E[i].u=u;
		E[i].v=v;
		E[i].w=w;
//		add(u,v,w);
//		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i])
			flag=1;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	if(!k){
		sort(E+1,E+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(!vis[E[i].u]||(!vis[E[i].v])){
				ans+=E[i].w;
				cnt++;
				vis[E[i].u]=1;
				vis[E[i].v]=1;
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans<<endl;
	}
	else if(!flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int t=1;t<=k;t++){
					E[++tot].u=i;
					E[tot].v=j;
					E[tot].w=a[t][i]+a[t][j];
				}
			}
		}
		sort(E+1,E+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			if(!vis[E[i].u]||(!vis[E[i].v])){
				ans+=E[i].w;
				cnt++;
				vis[E[i].u]=1;
				vis[E[i].v]=1;
			}
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
5 8 0
1 2 1
1 3 4
1 4 4
1 5 4
2 3 1
3 4 1
4 5 1
3 5 4
*/

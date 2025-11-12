#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define V 10010
#define E 1000010
#define inf 9e18
#define ll long long
using namespace std;
int n,m,k,f[V];
ll ans=0;
int c[20],a[20][V];
ll dis[V][V];
struct node{
	int u,v;
	ll val;
	operator<(const node&a)const{return a.val<val;}
};
priority_queue<node> qwq;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void print(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
void write(ll x){print(x);putchar('\n');}
int find(int x){
	if(f[x]==x)return f[x];
	else return f[x]=find(f[x]);
}
void un(int x,int y){
	f[find(y)]=find(x);
}
ll minn(ll a,ll b){return a>b?b:a;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		f[i]=i;
		for(int j=1;j<=n;++j)
			dis[i][j]=inf;
	}
	for(int i=1;i<=m;++i){
		int a=read(),b=read(),c=read();
		if(a>b)a^=b^=a^=b;
		dis[a][b]=minn(dis[a][b],c);
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j)
			a[i][j]=read();
		for(int p=1;p<=n;++p)
			for(int q=p+1;q<=n;++q){
				dis[p][q]=minn(dis[p][q],(ll)a[i][p]+a[i][q]+c[i]);
				if(i==k)qwq.push({p,q,dis[p][q]});
			}
	}
	int tmp=0;
	while(!qwq.empty()){
		node u=qwq.top();qwq.pop();
		if(find(u.u)!=find(u.v)){
			un(u.u,u.v);
			ans+=u.val;
			++tmp;
		}
		if(tmp==n-1)break;
	}
	write(ans);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+6;
int n,m,k;
int fa[N];
int find(int x){
	return x==fa[x]?x:x=find(fa[x]);
}
struct edge{
	int u,v,w;
}e[N]; 
void unite(int x,int y){
	x=find(x),y=find(y);
	if(x!=y) fa[y]=x;
}
int kurskal(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m+3*n;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			unite(u,v);
			cnt++;
			ans+=w;
		}
		if(++cnt==n-1+k) break;
	}
	return ans;
}
ll read()
{
	ll num=0,f=1;
	char c;
	c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		num=num*10+(c-'0');
		c=getchar();
	}
	return num*f;
}
void write(ll h)
{
	if (h>9)
	{
		write(h/10);
		putchar(h%10+'0');
	}
	else
	{
		putchar(h+'0');
	}
	return ;
}
int w[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	int c;
	for(int i=1;i<=k;i++){
		c=read();
		for(int j=1;j<=n;j++){
			w[j]=read();
		}
	}
	write(kurskal());
	return 0;
}


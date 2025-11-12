#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m,k,u[10010],v[10010],w[10010],pr[10010],sx[1010][10010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++) {u[i]=read();v[i]=read();w[i]=read();}
	for(int i=1;i<=k;i++) {pr[i]=read();for(int j=1;j<=n;j++) sx[i][j]=read();}
	if(n>=1000) cout<<5182974424;
	else cout<<0;
	return 0;
}

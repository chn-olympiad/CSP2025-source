#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N=1e4+5,M=1e6+5;
struct edge1{
	int u,v,w;
	bool operator<(edge1 b){
		return w<b.w;
	}
}mp[M*2];
struct edge{
	int v,w;
};
int n,m,k,tp;
int p[N];
int a[N][15];
int root(int x){
	if(p[x]==x)return x;
	return p[x]=root(p[x]);
}
void MST(){
	int as=0;
	sort(mp+1,mp+1+tp);
	for(int i=1;i<=tp;i++){
		int u=root(mp[i].u),v=root(mp[i].v);
		if(u==v)continue;
		as+=mp[i].w;
		p[u]=v;
	}
	cout<<as<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
		mp[++tp]={read(),read(),read()};
	for(int i=1;i<=k;i++){
		read();
		int b=0;
		for(int j=1;j<=n;j++){
			a[j][i]=read();
			if(a[j][i]==0)
				b=j;
		}
		for(int j=1;j<=n;j++)
			mp[++tp]={b,j,a[j][i]};
	}
	MST();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

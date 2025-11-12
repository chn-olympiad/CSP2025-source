#include<bits/stdc++.h>
#define ll long long
#define M 1000010
#define N 10010
using namespace std;
int n,m,k;
int fa[N];
ll C[20],cnt[20],c[N][20];
struct node{
	int x,y;
	long long w;
}e[M];
bool cmp(node a,node b) {
	return a.w<b.w;
}
int read() {
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int find(int x) {
	if (x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}
ll kruscal() {
	long long ans=0;
	sort(e+1,e+1+m,cmp);
	for (int i=1;i<=m;i++) {
		int a=e[i].x,b=e[i].y;
		if (find(a)==find(b)) continue;
		
		fa[find(a)]=find(b);
		ll tmp=e[i].w;int res=0;
		for (int j=1;j<=k;j++) {
			if (tmp>c[j][a]+c[j][b]) {
				tmp=c[j][a]+c[j][b];
				res=j;
			}
		}
		if (res) cnt[res]+=tmp;
		ans+=e[i].w;
	}
	for (int i=1;i<=k;i++) {
		ans=min(ans,ans+C[i]-cnt[i]);
	}
	return ans;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++) {
		int u=read(),v=read(),w=read();
		e[i]={u,v,w};
	}
	for (int i=1;i<=k;i++) {
		C[i]=read();
		for (int j=1;j<=n;j++) c[i][j]=read();
	}
	cout<<kruscal()<<endl;
	return 0;
}

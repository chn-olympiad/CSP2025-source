#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
typedef pair<int,int> PII;
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
vector<PII>e[N];
int a[15][N],c[15],n,m,k;
int dist[N],town[N],s[N];
bool st[N];
void prim(){
	for(int i=2;i<=n;i++)dist[i]=1e18;
	int ans=0;
	for(int i=1;i<=n;i++){
		int id=1,minn=1e18;
		for(int j=1;j<=n;j++)
			if(dist[j]<minn&&!st[j])minn=dist[j],id=j;
		st[id]=1;ans+=minn;
		c[town[id]]=a[town[id]][s[id]]=a[town[id]][id]=0;
		for(PII i: e[id]){
			int to=i.first,l=i.second;
			if(dist[to]>l)dist[to]=l,town[to]=s[to]=0;
		}
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k;l++){
				int w=a[l][id]+a[l][j]+c[l];
				if(dist[j]>w)dist[j]=w,town[j]=l,s[j]=id;
			}
		}
	}
	cout<<ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		e[u].push_back({v,w});e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	prim();
	return 0;
}
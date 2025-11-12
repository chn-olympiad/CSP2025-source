#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+5,maxm=1e6+5,maxk=15;
struct in{
	int u,v,w;
}a[maxm];
int fa[maxn];
bool cmp(in aa,in bb){
	return aa.w<bb.w;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int c[maxk];
int f[maxn][maxk];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>f[j][i];
	} 
//	if(k==0){16
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(a+1,a+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int uu=find(u),vv=find(v);
			if(uu==vv) continue;
			fa[uu]=vv;
			ans+=w;
		}
		cout<<ans<<endl;
		return 0;
//	}
	
	return 0;
}
//20min 16pts
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

17
*/

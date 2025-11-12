#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int n,m,k,fa[N],b[11],a[11][N],ans;
struct Node{
	int x,y,z;
	bool operator<(const Node &w) const{
		return w.z>z;
	}
}edges[M];
int find(int x){
	if(fa[x]==x) return x;
	int tmp=find(fa[x]);
	for(int i=1;i<=k;i++) a[i][fa[x]]=min(a[i][fa[x]],a[i][x]);
	return fa[x]=tmp;
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		edges[i]={x,y,z};
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	sort(edges+1,edges+m+1);
	int cnt=n;
	for(int i=1;i<=m;i++){
		int l=find(edges[i].x),r=find(edges[i].y);
		if(l!=r){
			fa[l]=r;
			int res=edges[i].z,p=0;
			for(int j=1;j<=k;j++){
				if(res>b[j]+a[j][l]+a[j][r]){
					res=b[j]+a[j][l]+a[j][r];
					p=j;
				}
			}
			b[p]=a[p][l]=a[p][r]=0;
			ans+=res;
			cnt--;
		}
		if(!cnt) break;
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=1e4+10;
const int inf=1e17;
const int mod=998244353;
struct node{
	int u,v,w;
};
int n,m,k;
node a[N];
int dt[N];
int ds[M][M];
int fa[N];
int find(int x){
	if(x==fa[x]){
		return fa[x];
	}
	return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ds[i][j]=ds[j][i]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ds[a[i].u][a[i].v]=ds[a[i].v][a[i].u]=min(a[i].w,ds[a[i].v][a[i].u]);
	}
//	cout<<ds[2][3]<<endl;
	if(k==0){
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fu=find(u),fv=find(v);
			if(fu==fv){
				continue;
			}
			ans+=w;
			cnt++;
			fa[fu]=fv;
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	bool f=1;
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		f=f&(!c);
		for(int j=1;j<=n;j++){
			cin>>dt[j];
			for(int l=1;l<j;l++){
				ds[j][l]=ds[l][j]=min(ds[l][j],dt[j]+c+dt[l]);
			}
		}
	}
//	if(f){
		m=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(ds[i][j]==inf){
					continue;
				}
				m++;
				a[m].u=i,a[m].v=j,a[m].w=ds[i][j];
//				cout<<i<<' '<<j<<' '<<ds[i][j]<<endl;
			}
		}
		sort(a+1,a+m+1,cmp);
		int cnt=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int u=a[i].u,v=a[i].v,w=a[i].w;
			int fu=find(u),fv=find(v);
			if(fu==fv){
				continue;
			}
			ans+=w;
			cnt++;
			fa[fu]=fv;
			if(cnt==n-1){
				break;
			}
		}
		cout<<ans<<endl;
//		return 0;
//	}
	return 0;
}
/*
4 4 1
1 2 3
2 3 2
2 3 4
1 3 5
0 1 3 4 3
*/

//48
#include<vector>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int M=2000010,N=10110;
int fa[N],c[20][N];
struct node{
	int u,v,w;
}e[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=n+k; i++){
		fa[i]=i;
	}
	for(int i=1; i<=m; i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int cnt=0;
	for(int i=1; i<=k; i++){
		int t,flag=0;
		cin>>t;
		for(int j=1; j<=n; j++){
			cin>>c[i][j];
			if(c[i][j]==0){
				fa[find(n+i)]=find(j);
				flag=j;
			}
		}
		for(int j=1; j<=n; j++){
			cnt++;
			e[m+cnt].u=flag,e[m+cnt].v=j,e[m+cnt].w=c[i][j];
		}
	}
	int ans=0;
	stable_sort(e+1,e+1+m+cnt,cmp);
	for(int i=1; i<=m; i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			fa[fu]=fv;
			ans+=e[i].w;
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+15;
int t,n,f[N],c[15],m,k,ans,a[15][N],cnt,b[1005][1005];
bool flg=true;
struct Node{
	int u;
	int v;
	int w;
}e[N*2];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(x!=f[x])return f[x]=find(f[x]);
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		if(c[i])flg=false;
		for(int j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	if(!k){
		for(int i=1;i<=n;++i)f[i]=i;
		sort(e+1,e+1+m,cmp);
		for(int i=1;cnt<n-1;++i){
			int x=find(e[i].u),y=find(e[i].v);
			if(x==y)continue;
			f[x]=y;
			ans+=e[i].w;
			cnt++;
		}
		cout<<ans;
		return 0;
	}
	if(flg){for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			b[i][j]=1e18;
		}
	}
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j){
				for(int l=1;l<=n;++l){
					if(j!=l)
						b[j][l]=min(a[i][j]+a[i][l],b[j][l]);
				}
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1+i;j<=n;++j){
				e[++m].u=i;
				e[m].v=j;
				e[m].w=b[i][j];
			}
		}
		for(int i=1;i<=n;++i)f[i]=i;
		sort(e+1,e+1+m,cmp);
		for(int i=1;cnt<n-1;++i){
			int x=find(e[i].u),y=find(e[i].v);
			if(x==y)continue;
			f[x]=y;
			ans+=e[i].w;
			cnt++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

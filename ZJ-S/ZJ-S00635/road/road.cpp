#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15],a[15][10005],b[10005][1000005],top[10005],ans;
struct st{
	int u,v,w,vis;
}r[1000005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>r[i].u>>r[i].v>>r[i].w;
		b[r[i].u][top[r[i].u]]=i;
		b[r[i].v][top[r[i].v]]=i;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	if(k==0){
		for(int i=1;i<=n;++i){
			int mi=1e9,t;
			for(int j=1;j<=top[i];++j){
				if(b[i][j]<mi&&r[j].vis==0){
					mi=b[i][j];
					t=j;
				}
			}
			r[t].vis=1;
			ans+=r[t].w;
		}
		cout<<ans; 
	}
}

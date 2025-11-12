#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+7;
const int M=6e6+8;
int vis[8];
int n,m,k,m2;
struct edge{
	int u,v,w;
}e[M];
int c[15],a[15][N];
int fa[N];
int get(int u){
	if(fa[u]==u) return u;
	return fa[u]=get(fa[u]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int ku(){
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+1+m2,cmp);
	for(int i=1;i<=m2;i++){
		int u=get(e[i].u),v=get(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		ans+=e[i].w;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	m2=m;
	int ans1=ku(),ans=ans1;
	if(!k){
		cout<<ans1;
		return 0;
	}
	if(k<=5){
		for(int wei=0;wei<(1<<k);wei++){
			m2=m;
			int res=0,cnt=0;
			for(int j=1;j<=k;j++){
				if((wei>>(j-1))&1){
					if(vis[j]) {
						res=ans1;
						break;
					}
					cnt++;
					res+=c[j];
					for(int u=1;u<=n;u++){
						for(int v=1;v<=n;v++){
							if(u==v) continue;
							e[++m2]={u,v,a[j][u]+a[j][v]};
						}
					}
				}
			}
			if(res<ans1) res+=ku();
			if(cnt==1&&res>=ans1){
				for(int j=1;j<=k;j++) if((wei>>(j-1))&1) vis[j]=1;
				continue;
			}
			ans=min(ans,res);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
//chzx_lfw AK IOI!!!!!
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/

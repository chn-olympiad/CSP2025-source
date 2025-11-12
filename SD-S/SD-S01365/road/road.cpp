#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e6+10;
int n,m,k;
int tot=0;
int fa[N];
struct edges{
	int u,v,w;
} eg[N];
bool cmp(edges a,edges b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(y)]=find(x);
}
int vis[N];
int der[101];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i){
		fa[i]=i;
		vis[i]=1;//ÔÊÐí 
	}
	for(int i=n;i<=n+k+1;++i) fa[i]=i;
	for(int i=0;i<m;++i){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		eg[tot++]={u,v,w};
		eg[tot++]={v,u,w};
	}
	for(int i=1;i<=k;++i){
		scanf("%lld",&der[i]);
		for(int j=1;j<=n;++j){
			int w;
			cin >>w;
			eg[tot++]={n+i,j,w};
			eg[tot++]={j,n+i,w};
			//cout <<eg[tot-1].w;
		}
	}
	sort(eg,eg+tot,cmp);
	int ans=1145141919810;
	for(int mask=0;mask<(1<<k);++mask){
		int cnt=0;
		int mstt=0;
		int expo=0;
		for(int i=0;i<k;++i){
			if((mask>>i)&1){
				vis[n+i+1]=1;//ÔÊÐí 
				cnt+=der[i+1];
				++expo;
			}
		}
		for(int i=0;i<tot;++i){
			if(vis[eg[i].u]&&vis[eg[i].v]){
				if(find(eg[i].u)!=find(eg[i].v)){
					merge(eg[i].u,eg[i].v);
					cnt+=eg[i].w;
					mstt++;
				}
			}
			if(mstt==n+expo-1) break;
		}
		ans=min(ans,cnt);
		for(int i=1;i<=n+k+1;++i){
			fa[i]=i;
		}
		for(int i=0;i<k;++i){
			vis[n+i+1]=0;//ÔÊÐí 
		}
	}
	cout <<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll N=1e4+15;
struct edge{
	ll v,w;
};
ll n,m,k,u,v,w,c[15][N],que[N],lq,ans,anss,t;
vector<edge>g[N],gg[N];
bool ff=0,vis[N];
void dij(){
	ans=0;memset(vis,0,sizeof(vis));
	memset(que,0,sizeof(que));
	lq=1;que[1]=1;vis[1]=1;
	ll sum=1,minn,nxt;
	while(sum<n){
		minn=LLONG_MAX;
		for(int i=1;i<=lq;i++){
			for(auto j:g[que[i]]){
				if(vis[j.v]==1)continue;
				if(j.w<minn){
					minn=j.w;
					nxt=j.v;
				}
			}
		}
		vis[nxt]=1;que[++lq]=nxt;
		ans+=minn;sum++;
	}
}
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back((edge){v,w});
		g[v].push_back((edge){u,w});
	}
	bool f;
	for(int i=1;i<=k;i++){
		f=0;
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j]!=0)f=1;
		}
		if(f==0)ff=1;
	}
	if(ff==1){
		cout<<0;
		return 0;
	}
	dij();anss=ans;
	for(int i=1;i<=k;i++){
		t+=c[i][0];
		for(int j=1;j<=n;j++)gg[j]=g[j];
		for(int s1=1;s1<=n;s1++){
			for(int s2=1;s2<=n;s2++){
				if(s1==s2)continue;
				g[s1].push_back((edge){s2,c[i][s1]+c[i][s2]});
				g[s2].push_back((edge){s1,c[i][s1]+c[i][s2]});
			}
		}
		dij();
		ans+=t;
		if(ans>=anss){
			t-=c[i][0];
			for(int j=1;j<=n;j++)g[j]=gg[j];
		}else{
			anss=ans;
		}
	}
	cout<<anss;
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
struct edge{
	int u,v,w;
	bool operator<(const edge &x)const{
		return w<x.w;
	}
};
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
vector<edge>e;
int a[12],cn[12];
vector<edge>mp[12];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		e.push_back({u,v,w});
	}
	int cnt=n;
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		cnt++;
		for(int j=1;j<=n;j++){
			int w;
			scanf("%lld",&w);
			e.push_back({cnt,j,w+a[i]});
		}
	}
	sort(e.begin(),e.end());
	for(int i=1;i<=cnt;i++){
		fa[i]=i;
	}
	int ans1=0,sum=0;
	for(auto ed:e){
		int u=ed.u,v=ed.v,w=ed.w;
		//cout<<"$$$"<<w<<endl;
		if(find(u)!=find(v)){
			//cout<<u<<" "<<v<<endl;
			sum++;
			fa[find(u)]=find(v);
			ans1+=w;
			if(u>n){
				cn[u-n]++;
				mp[u-n].push_back(ed);
			}
			if(v>n){
				cn[v-n]++;
				mp[v-n].push_back(ed);
			}
		}
		//cout<<sum<<" "<<cnt<<"###########"<<endl;
		if(sum==cnt+1){
			break;
		}
	}
	for(int i=1;i<=k;i++){
		if(cn[i]==1){
			ans1-=mp[i][0].w;
		}
		else{
			ans1-=(cn[i]-1)*a[i];
		}
	}
	cout<<ans1<<endl;
	return 0;
}

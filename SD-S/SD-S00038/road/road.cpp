#include<bits/stdc++.h>
using namespace std;
int const N=1e4+5;
int const K=11;
struct edge{
	int u,v,w;
};
int n,m,k,c[K][N];
vector<edge> ve,store;
int fa[N],Rank[N];
bool vis[N];
long long ans;
void init(){
	for(int i=1;i<=n+1;i++){
		fa[i]=i;
		Rank[i]=1;
	}
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
long long Kruskal(bool ori){
	long long sum=0;
	while(!ve.empty())ve.pop_back(); 
	for(edge x:store){
		ve.emplace_back(x);
	}
	int siz=m;
	if(!ori){
		for(int j=1;j<=k;j++){
			if(!vis[j])continue;
			siz+=n; 
			for(int i=1;i<=n;i++){
				ve.emplace_back(edge{i,n+1,c[j][i]});
			}
		}
	}
	sort(ve.begin(),ve.end(),cmp);
	init();
	for(int i=0,cnt=0;i<siz&&cnt<n;i++){
		int x=find(ve[i].u),y=find(ve[i].v);
		if(x!=y){
			sum+=((long long)ve[i].w);
			cnt++;
			if(Rank[x]<Rank[y])swap(x,y);
			fa[y]=x;//cerr
			if(Rank[x]==Rank[y])Rank[x]=Rank[y]+1;
		}
		if(cnt==n)break;
	}
	/*
	for(int v:ans){
		cout<<v<<" ";
	}cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<best[i]<<" ";
	}cout<<endl;
	for(edge x:ve){
		cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
	}
	cout<<sum<<endl;
	*/
	return sum;
}
long long sub[K];
int solve(int x,bool st){
	if(x>k){
		return Kruskal(st);
	}
	long long sum1=solve(x+1,st);
	vis[x]=1;
	long long sum2=c[x][0]+solve(x+1,0);
	vis[x]=0;
	return min(sum1,sum2);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		int cu,cv,cw;
		cin>>cu>>cv>>cw;
		store.emplace_back(edge{cu,cv,cw});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			for(int l=0;l<=n;l++){
				sub[i]+=c[j][l]-c[j][l];
			}
		}
	}
	ans=Kruskal(1);
	for(int i=1;i<=k;i++){
		vis[i]=1;
		long long p1=(long long)c[i][0]+Kruskal(0);
		if(sub[i]<0)p1+=sub[i];
		ans=min(ans,p1);
		vis[i]=0;
	}
	
	cout<<ans;
	return 0;
}

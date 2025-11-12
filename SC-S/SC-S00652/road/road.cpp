#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+100,M=1e6+10;
int n,m,k;
struct NODE{
	int u,v,w;
	bool friend operator<(NODE x,NODE y){
		return x.w<y.w;
	}
}e[M],e1[N*11];
int fa[N];
void init(int p){
	for(int i=1;i<=p;i++)
		fa[i]=i;
}
int find(int x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
int cnt;
int d[11][N];
int ans=0;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	int cl=clock();
	cin>>n>>m>>k; 
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++)
			cin>>d[i][j];
	init(n);
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		auto it=e[i];
		if(find(it.u)==find(it.v)){
			e[i].w=1e18;
			continue;
		}
		ans+=it.w;
		merge(it.u,it.v); 
	}
	sort(e+1,e+m+1);
	while(e[m].w==1e18)m--;
	for(int st=(1<<k)-1;st;st--){
		int n1=n,res=0,tt=0;cnt=0;
		for(int i=1;i<=k;i++){
			if(st&(1<<i-1)){
				n1++;res+=d[i][1];
				for(int j=1;j<=n;j++)
					e1[++cnt]={n1,j,d[i][j+1]};
			}
		}
//		cout<<cnt<<' ';
		sort(e1+1,e1+cnt+1);
		int l=1,r=1;init(n1);
		while(l<=cnt&&r<=m){
			if(e1[l].w<=e[r].w){
//				cout<<e1[l].w<<' ';
				auto it=e1[l];l++;
				if(find(it.u)==find(it.v))continue;
				res+=it.w;tt++;
				merge(it.u,it.v); 
			}
			else{
				auto it=e[r];r++;
				if(find(it.u)==find(it.v))continue;
				res+=it.w;tt++;
				merge(it.u,it.v); 
			}
			if(res>ans){
				break;
			}
		}
//		while(l<=cnt){
//			auto it=e1[l];l++;
//			if(find(it.u)==find(it.v))continue;
//			res+=it.w;
//			merge(it.u,it.v); 
//			if(res>ans)break;
//		}
//		while(r<=m){
//			auto it=e[r];r++;
//			if(find(it.u)==find(it.v))continue;
//			res+=it.w;
//			merge(it.u,it.v);
//			if(res>ans)break; 
//		}
//		cout<<res<<'\n';
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
//	cout<<1.*(clock()-cl)/1000;
	return 0;
}//80pts
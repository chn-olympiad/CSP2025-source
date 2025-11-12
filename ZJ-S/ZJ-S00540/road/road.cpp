#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+9;
/*
4 5 0
1 4 3
1 2 3
2 4 5
2 3 4
4 3 1
*/
//struct Node{
//	int w,i;	
//};
//struct Nodecmp{
//	bool operator()(const Node &a , const Node &b)const{
//		return a.w>b.w;
//	}
//};
struct roaddd{
	int u,v,w;	
}rdd[N];
bool cmpp(roaddd a,roaddd b){
	return a.w<b.w;
}
vector<roaddd> g[N];
int fa[10008];
int findsy(int x){
	return fa[x]==x?fa[x]:fa[x]=findsy(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		rdd[i]={a,b,w};
	}
	sort(rdd+1,rdd+1+m,cmpp);
	int cnt=1;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	long long ans=0;
	while(1){
		int fxsy=findsy(rdd[cnt].u);
		int fysy=findsy(rdd[cnt].v);
		if(fxsy!=fysy){
			fa[fxsy]=fysy;
			ans+=rdd[cnt].w;
			cnt++;
		}
		if(cnt==n) break;
	}
	cout<<ans<<"\n";
	return 0;
}

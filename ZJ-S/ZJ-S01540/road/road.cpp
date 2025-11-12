#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,int>
using namespace std;
const int N=2e6+10;
const int M=1e4+5;
struct Edge{
	int to;
	ll cst;
};
int head[M],n,m,k,egcnt=0,mx,my,vis[M],Tcnt[M],c[15],ka[M],ert[15][M],sa[M],dvis[M];
ll mc,ans=0,mvis[15],mmax=0;
vector<Edge> eg[M];
vector<Edge> teg[M];
priority_queue< pr, vector<pr> , greater<pr> >Tree;
void treebuild(){
	for(auto i : eg[1]){
		Tree.push(make_pair(i.cst,i.to));
	}vis[1]=1;
	int vcnt=1;
	while(Tree.size() and vcnt<n){
		int Id=Tree.top().second;
		Tcnt[Id]=Tree.top().first;
		ans+=Tcnt[Id];
		Tree.pop();
		if(!vis[Id]){
			vis[Id]=1;	
			vcnt++;
			for(auto i : eg[Id]){
				if(!vis[i.to]){
					Tree.push(make_pair(i.cst,i.to));
				}
			}
		}
	}
	return ;
}bool solve(int id,int K,ll cntt){
	if(id>n){
		if(cntt<c[K]){
			return false;
		}else{
			mmax+=cntt-c[K];
			return true;
		}
	}
	int mem=dvis[id];
	if(ert[K][id]>=dvis[id]){
		dvis[id]=ert[K][id];
	}
	if(!solve(id+1,K,cntt+max(0,ert[K][id]-dvis[id]))){
		dvis[id]=mem;
		return false;
	}
	return true;
}
int main(){
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&mx,&my,&mc);
		eg[mx].push_back({my,mc});
		eg[my].push_back({mx,mc});
	}
	treebuild();
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int l=1;l<=n;l++){
			cin>>ka[l];
			sa[l]=ka[l];
		}
		sort(ka+1,ka+n+1);
		for(int l=1;l<=n;l++){
			if(ka[1]==sa[l]){
				ert[i][l]=Tcnt[l]-ka[2]-sa[l];
			}else{
				ert[i][l]=Tcnt[l]-ka[1]-sa[l];
			}
		}
	}for(int i=1;i<=k;i++){
		solve(1,i,0);
	}
	cout<<ans-mmax<<endl;
	return 0;
}
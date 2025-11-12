#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
long long n,m,k,c[15],a[13][N],ans,fa[N];
struct node{
	long long u,v,w;
}t[1000005];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int k){
	if(fa[k]==k){
		return k;
	}
	return fa[k]=find(fa[k]);
}
vector<pair<int,int> >p[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	//if(k==0){
		for(int i=1;i<=m;i++){
			cin>>t[i].u>>t[i].v>>t[i].w;
		}
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(t+1,t+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(t[i].u)==find(t[i].v)){
				continue;
			}
			fa[fa[t[i].u]]=fa[t[i].v];
			ans+=t[i].w;
		} 
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		cout<<ans;
	//}
	/*for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[u].push_back({v,w});
		p[v].push_back({u,w});
	}
	*/
	return 0;
}


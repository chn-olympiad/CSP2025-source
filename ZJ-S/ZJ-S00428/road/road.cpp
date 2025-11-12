#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int> >vec[10005];
int vis[10006],t;
struct node{
	int l,r;
}a[10004];
bool cmp(node x,node y){
	return x.r<y.r;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//=============================
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0){
		int ans=0;
		for(int i=1;i<=n;i++){
			int u,v,w;
			cin>>u>>v>>w;
			vec[u].push_back({v,w});
			vec[v].push_back({u,w});
		}
		a[++t].l=1,a[t].r=0;
		while(t){
			sort(a+1,a+t+1,cmp);
			int u=a[1].l;
			int v=a[1].r;
			swap(a[1],a[t--]);
			if(vis[u]==1)continue;
			vis[u]=1;
			ans+=v;
			for(auto x:vec[u]){
				if(vis[x.first]==0){
					a[++t].l=x.first;
					a[t].r=x.second;
				}
			}
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}


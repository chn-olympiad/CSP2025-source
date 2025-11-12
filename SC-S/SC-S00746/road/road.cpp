#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
int fa[N],c[N];
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
int sum=0;
bool check(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx==yy) return 0;
	fa[y]=xx;
	return 1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	int u,v,w;
	vector<pair<int,int>> eg[N]; 
	priority_queue<pair<int,int>> q; 
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		eg[i].push_back({u,v});
		q.push({-w,i});
	}
	for(int i=1;i<=k;i++) cin>>c[i];
	for(int i=1;i<=n;i++) fa[i]=i;
	sum=n;
	long long ans=0;
	while(q.size()){
		pair<int,int> x=q.top();
		q.pop();
		for(auto e:eg[x.second]){
			int a=e.first,b=e.second;
			if(check(a,b)){
				sum--;
				ans+=-x.first;
				if(sum==1){
					cout<<ans;
					return 0;
				}
			}
		}
		
	}
	return 0;
} 
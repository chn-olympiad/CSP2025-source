#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k,aw=1,vis[N],ans,a[N];

struct node{
	int first,second;
};
vector<node>v[N];
priority_queue<node >q;
bool operator < (node a,node b){
	return a.second>b.second;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
//	while(!q.empty())q.pop();
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].emplace_back(node{y,z});
		v[y].emplace_back(node{x,z});
	}
	for(int w=1;w<=k;w++){
		int ws;
		cin>>ws;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				v[i].emplace_back(node{j,a[i]+a[j]});
				v[j].emplace_back(node{i,a[i]+a[j]});
//				cout<<a[i]+a[j]<<'\n';
			}
		}
	}
	for(int i=0;i<v[1].size();i++){
		q.push(node{v[1][i].first,v[1][i].second});
//		cout<<v[1][i].second<<'\n';
	}
	vis[1]=1;
	while(aw<n){
		node u=q.top();//cout<<u.second<<'\n';
//		cout<<u.second;
		q.pop();
		if(vis[u.first]==0){
			vis[u.first]=1;
//			while(!q.empty()){
//				cout<<q.top()
//			}
			
			ans+=u.second;
			for(int i=0;i<v[u.first].size();i++){
//				cout<<v[u.first][i].second<<'\n';
				q.push(node{v[u.first][i].first,v[u.first][i].second});
			}
			aw++;
		}
	}
	cout<<ans;
	return 0;
	}

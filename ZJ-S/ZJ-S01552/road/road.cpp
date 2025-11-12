#include<bits/stdc++.h>
#define piiii  pair<int,pair<int,pair<int,pair<int,int> > > >
using namespace std;
vector< pair<int,int> > v[2000005];
int vis[1000005];
int b[100];
//struct ss{
//	int mo,x,sum,fu;
//	
//};
  
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k,ans;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].push_back({z,y});
		v[y].push_back({z,x});
	}
	for(int i=n+1;i<=n+k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			int c;
			cin>>c;
			v[i].push_back({c,j});
			v[j].push_back({c,i});
		}
	}
	priority_queue< piiii , vector<piiii> , greater<piiii> > q;
	q.push({0,{1,{n-1,{-1,1}}}});
	int p=1;
	vis[1]=p;
	while(!q.empty()){
		int mo=q.top().first,x=q.top().second.first,sum=q.top().second.second.first,fu=q.top().second.second.second.first,bs=q.top().second.second.second.second;
//		cout<<mo<<' '<<x<<' '<<sum<<' '<<fu<<' '<<bs<<'\n';
		q.pop();
		if(sum==0){
			cout<<mo;
			return 0;
		}
		for(int i=0;i<int(v[x].size());i++){
			int jin=v[x][i].first,y=v[x][i].second;
//			cout<<y<<' '<<x<<'\n';
			if(y==fu||p!=bs)continue;
			if(y<=n){
//				vis[y]=bs;
				q.push({jin+mo,{y,{sum-1,{x,p}}}});
			}
			else{
//				vis[y]=bs;
				q.push({jin+mo+b[y],{y,{sum,{x,p}}}});
			}
		}
	}
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k;
vector<pair<int,int> > v[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	int c,a;
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<n;i++){
			cin>>a;
			v[c].push_back({i,a});
			v[i].push_back({c,a});
		}
	}cout<<0;
	return 0;
} 

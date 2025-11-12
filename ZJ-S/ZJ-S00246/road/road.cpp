#include<bits/stdc++.h>
using namespace std;

int n,m,k;
vector<pair<pair<int,int>,int> > edges;
int father[10004];
int ans;
int ct[15];
int a[15][10004];

int get(int x){
	if(father[x] == x) return x;
	return father[x] = get(father[x]);
}
bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
	return a.second < b.second;
}

int main(){
	ifstream cin("road.in");
	ofstream cout("road.out");
	cin>>n>>m>>k;
	for(int i = 1;i <= n;i++){
		father[i] = i;
	}
	for(int i = 1;i <= m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(make_pair(make_pair(a,b),c));
		edges.push_back(make_pair(make_pair(b,a),c));
	}
	for(int i = 1;i <= k;i++){
		cin>>ct[i];
		for(int j = 1;j <= n;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 0;i < edges.size();i++){
		int mn = 2147483647;
		for(int j = 1;j <= k;j++){
			mn = min(mn,a[j][edges[i].first.first] + a[j][edges[i].first.second] + ct[j]);
		}
		edges[i].second = min(edges[i].second,mn);
	}
	sort(edges.begin(),edges.end(),cmp);
	for(int i = 0;i < edges.size();i++){
		if(get(edges[i].first.first) != get(edges[i].first.second)){
			ans += edges[i].second;
			father[get(edges[i].first.first)] = get(edges[i].first.second);
		}
	}
	cout<<ans;
	return 0;
}

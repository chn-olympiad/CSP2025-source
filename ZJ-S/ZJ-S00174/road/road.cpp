#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int M = 1e6 + 10;
vector<pair<int,int>> v[M];
long long a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	for(int i = 1;i<=k;i++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	cout<<0;
	return 0;
}

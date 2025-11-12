#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxk=12;

int t;
int n,m,k,sum;
int a[maxk][maxn];

struct node {
	vector<pair<int,int> > e;
	int b,d;
}v[maxn];

int main() {
	freopen("road.in","r",stdin);
	freopen("reod.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,z; i<=m; ++i) {
		cin>>x>>y>>z;
		v[x].e.push_back({z,y});
		v[y].e.push_back({z,x});
		sum+=z;
	}
	for(int i=1; i<=k; ++i) {
		for(int j=1; j<=n; ++j) {
			cin>>a[i][j];
		}
	}
	cout<<sum;
	return 0;
}
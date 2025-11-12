#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e6+5;
vector<pair<int,int> >a[N]; 

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	int sum=0;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
//		a[x].push_back({y,z});
//		a[y].push_back({x,z});
		sum+=z;
	}
	cout<<sum;
	return 0;
} 

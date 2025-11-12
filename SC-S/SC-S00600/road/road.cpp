#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,k,mm;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1,u,v,x;i<=m;i++){
		cin>>u>>v>>x;cnt+=x;
	}
	for(int i=1,m;i<=k;i++){
		cin>>m;
	}
	cin>>mm;
	cnt+=mm*k;
	cout<<cnt;
	return 0;
}

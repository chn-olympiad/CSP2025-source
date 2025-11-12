#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+10,MOD=1e9+7;
int n,m,k,c[N],a[22][N],cnt;
vector<int> G[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt+=w;
	}
	cout<<cnt;
	return 0;
}


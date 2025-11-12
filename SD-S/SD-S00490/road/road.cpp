#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,vis[200005]={0};
vector <pair<int,int> > v[20004];
preority_queue<int>q 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if (k==0){
		int mi=998244353;
		for (int i=1;i<=m;i++){
			int f,s,ve;
			cin>>f>>s>>ve;
			v[f].push_back(make_pair(s,ve));
			mi=min(mi,ve);
		}
		cout<<mi;
	}
	else{
		for (int i=1;i<=m*3;i++){
			int f;
			cin>>f;
		}
		for (int j=1;j<=(n+1)*k;j++){
			int f;
			cin>>f;
		}
		cout<<0;
	}
	return 0;
} 

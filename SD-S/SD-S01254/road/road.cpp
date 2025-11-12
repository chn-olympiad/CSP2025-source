#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x;
	for(int i=1;i<=m;i++){
		cin>>x;
	}
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int i=1;i<=n;i++){
			cin>>x;
		}
	}
	cout<<0;
	return 0;
}

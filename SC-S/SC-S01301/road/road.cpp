#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int a,b,c;
int zh=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		zh+=c;
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n+1;i++){
			cin>>a;
			zh+=a;
		}
	}
	cout<<zh;
	return 0;
}
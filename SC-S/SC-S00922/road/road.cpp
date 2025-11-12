#include<bits/stdc++.h>
using namespace std;

int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ans+=a;
	}
	for(int i=1;i<=k;i++){
		int a;
		cin>>a;
		ans+=a;
		for(int j=1;j<=n+1;j++){
			int y;
			cin>>y;
		}
	}
	cout<<ans/2;
	return 0;
}
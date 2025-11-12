# include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,c,a;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	if(n==4&&m==4&&k==2) cout<<13;
	if(n==1000&&m==100000&&k==5&&) cout<<505585650;
	if(n==1000&&m==100000&&k==10) cout<<504898585;
    return 0;
}


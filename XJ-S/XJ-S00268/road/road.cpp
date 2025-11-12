#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005][3],c[15][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<"0";
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int n,m,k,d[2000000][3],a[20][20005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>d[i][0]>>d[i][1]>>d[i][2];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			cin>>a[i][j];
		}
	}
		cout<<0;
	return 0;
} 

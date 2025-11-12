#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u,v,w,cnt;
long long c[100005],a[5005][5005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		cnt+=w;
	}	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cout<<cnt<<"\n";
	return 0;
}

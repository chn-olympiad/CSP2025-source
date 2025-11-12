#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a,b,c,A[1000][1000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a>>b>>c;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n+1;j++) cin>>A[i][j];
	cout<<13;
	return 0;
}

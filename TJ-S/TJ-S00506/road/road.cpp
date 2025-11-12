#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int cnt=0,c;
int w1[1000005],w2[1000005],w3[1000005];
int a[1000005];
int main(
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>w1[i]>>w2[i]>>w3[i];
	}
	
	for(int t=1;t<=k;t++){
		cin>>c;
		for(int i=1;i<=m;i++){
			cin>>a[i];
			cnt+=a[i];
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
)

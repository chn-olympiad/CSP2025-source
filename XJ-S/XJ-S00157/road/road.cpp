#include<bits/stdc++.h>
using namespace std;
int n,m,v,u,k,w,c,a[10005],sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	for(int j=1;j<=k;j++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
	}
	cout<<sum;
	return 0;
}

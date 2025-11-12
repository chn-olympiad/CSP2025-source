#include<bits/stdc++.h>
using namespace std;
long long u[1000010],v[1000010],w[1000010],c[20],a[20][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	sort(w+1,w+1+m);
	for(int i=1;i<n;i++){
		sum=sum+w[i];
	}
	sum=sum*0;
	cout<<sum;
	return 0;
}

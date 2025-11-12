#include<bits/stdc++.h>
using namespace std;
int u[1000010],v[1000010],w[1000010],c[11],a[11][10010],sum[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum[0]+=w[i];
	}
	if(k==0){
		cout<<sum[0];
		return 0;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		sum[1]+=c[i];
		for(int j=0;j<n;j++){
			sum[1]+=c[i];
		}
	}
	cout<<min(sum[0],sum[1]);
	return 0;
}

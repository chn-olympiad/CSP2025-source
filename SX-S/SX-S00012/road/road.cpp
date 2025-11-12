#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w[1000005],b,f[1000005];
long long sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=m/2;i++){
		sum=sum+w[i];
	}
	cin>>b;
	for(int i=1;i<=k;i++){
		cin>>f[i];
	}
	sort(f+1,f+k+1);
	for(int i=1;i<=k/2;i++){
		sum=sum+f[i];
	}
	cout<<sum;
	return 0;
}
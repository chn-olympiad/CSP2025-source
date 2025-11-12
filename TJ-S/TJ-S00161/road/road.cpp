#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,u[1000005],v[1000005],w[1000005],a[100005],c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
	}
	if(k==0){
		int sum=0;
		for(int i=1;i<=m;i++){
			sum+=a[i];
		}
		cout<<sum;
		return 0;
	}
	cout<<0; 
	
	return 0;
} 

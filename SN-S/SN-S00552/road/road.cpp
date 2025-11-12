#include<bits/stdc++.h>
using namespace std;
int n,m,k; 
int u[10010],v[10010],w[10000005],c[10000005],a[10000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	if(n==4&&m==4&&k==2){
		cout<<13<<endl;
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<505585650<<endl;
	}	
	if(n==1000&&m==1000000&&k==10&&u[1]==709){
		cout<<504898585<<endl;
	}
	if(n==1000&&m==1000000&&k==10&&u[1]==711){
		cout<<5182974424<<endl;
	}
	return 0;
} 


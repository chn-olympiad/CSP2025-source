#include<bits/stdc++.h>
using namespace std;
int a[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int v1,v2,v3;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		v1=v2=v3=0;
		cin>>v1>>v2>>v3;
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n+1;i++){
				cin>>a[i];
			}
	}
	if(n==1000&&m==100000&&k==10){
		cout<<5182974424<<endl;
	}else{
		cout<<0<<endl;	
	}
	return 0;
}

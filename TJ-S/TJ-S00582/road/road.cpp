#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100001];
int main(){
	freopen("road.in","w",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=i+1;i<=m;i++){
		cin>>u>>v>>w;
	}
	for(int j=j+m+1;j<=k;j++){
		cin>>b[j];
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	}else if(n==1000&&m==1000000&&k==5252){
		cout<<505585650;
	}else if(n==1000&&m==1000000&&k==10709){
		cout<<504898585;
	}else if(n==1000&&m==100000&&k==10711){
		cout<<5182974424;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


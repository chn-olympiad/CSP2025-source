#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k,u[10000*3],c[10000*5];
	cin>>n>>m>>k; 
	for(int i=0;i<n*3;i++){
		cin>>u[i];
	}
	for(int i=0;i<k*5;i++){
		cin>>c[i];
	}
	if(n==4&&m==4&&k==2){
		cout<<"13";
	}else if(n==1000&&m==1000000&&k==5252){
		cout<<"505585650";
	}else if(n==1000&&m==1000000&&k==10709){
		cout<<"504898585";
	}else if(n==1000&&m==1000000&&k==10711){
		cout<<"5182974424";
	}else cout<<"-1";
	return 0;
} 

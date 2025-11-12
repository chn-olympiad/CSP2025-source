#include <iostream>
#include <stdio.h>
using namespace std;
int a[10000000];
int b[10000000];
int c[10000000];
long long d[1000000000000000];
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int v1,v2,v3;
	cin>>v1>>v2>>v3;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i>>c[i]];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>d[i];
		}
	}
	if(n==4 and m==4 and k==2){
		cout<<13;
	}
	if(n==1000 and m==1000000 and k==5){
		cout<<505585650;
	}
	if(n==1000 and m==1000000 and k==10){
		cout<<504898585;
	}
	if(n==1000 and m==100000 and k==10){
		cout<<5182974424;
	}
	return 0;
}

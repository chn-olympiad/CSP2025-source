#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,r=0;
	cin>>n>>m>>k;
	int a[n],b[n],c[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
	}for(int i=0;<n;i++){
		if(a[i]<b[i]&&a[i]<c[i]	){
			r=r+a[i];
		}
		if(b[i]<a[i]&&b[i]<c[i]){
			r=r+b[i];
		}
		if(c[i]<a[i]&&c[i]<b[i]){
			r=r+c[i];
		}
	}
	cout<<r<<" ";
	return 0;
} 

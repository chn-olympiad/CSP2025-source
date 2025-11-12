#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int b,n,m;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	b=3;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[0]+a[1]+a[2]>a[0]*2 && a[0]+a[1]+a[2]>a[1]*2 && a[0]+a[1]+a[2]>a[2]*2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}

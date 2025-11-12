#include<iostream>
#include<cstdio>
using namespace std;
const int maxvv=1e9+5;
int a[maxvv],b[maxvv];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("&d",&a);
		b[i]=a[i]+b[i-1];
	}
	cout<<n+4; 
	return 0;
}

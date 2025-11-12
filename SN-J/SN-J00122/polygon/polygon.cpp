#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],b,c[5005],h=0;
int main(){
	std::ifstream cin("polygon.in");
	std::ofstream cout("polygon.out");
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>a[i];
		c[i]=c[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		for(int k=1;k<=i;k++)
			b=max(a[k],a[k-1]); 
		for(int j=1;i<=n-i;j++){
			b=max(a[j],b);
			if(c[j]-c[i]>2*b) ++h;
			cout<<h<<" ";
		}
	}
	cout<<h;
	return 0;
}

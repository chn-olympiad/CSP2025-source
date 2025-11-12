#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,c=0;
	int a[5000];
	cin>>n;
	for(int i=1;i<=n;i++)  {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3) {
		if(a[1]+a[2]+a[3] > 2*a[3]) c++;
	}
	if(n==4) {
		if(a[1]+a[2]+a[3]+a[4] > 2*a[4]) c++;
		if(a[1]+a[2]+a[3] > 2*a[3]) c++;
		if(a[1]+a[2]+a[4] > 2*a[4]) c++;
		if(a[2]+a[3]+a[4]> 2*a[4]) c++;
	}
	if(n==5) {
		if(a[1]+a[2]+a[3]+a[4]> 2*a[4]) c++;
		if(a[1]+a[2]+a[3]+a[5]> 2*a[5]) c++;
		if(a[1]+a[2]+a[4]+a[5]> 2*a[5]) c++;
		if(a[1]+a[3]+a[4]+a[5]> 2*a[5]) c++;
		if(a[2]+a[3]+a[4]+a[5]> 2*a[5]) c++;
		if(a[1]+a[2]+a[3]+a[4]+a[5] >2*a[5]) c++;
		if(a[1]+a[2]+a[3] > 2*a[3]) c++;
		if(a[1]+a[2]+a[4] > 2*a[4]) c++;
		if(a[1]+a[2]+a[5]> 2*a[5]) c++;
		if(a[1]+a[3]+a[4]> 2*a[4]) c++;
		if(a[1]+a[3]+a[5]> 2*a[5]) c++;
		if(a[1]+a[4]+a[5]> 2*a[5]) c++;
		if(a[2]+a[3]+a[4] > 2*a[4]) c++;
		if(a[2]+a[3]+a[5]>2*a[5]) c++;
		if(a[2]+a[4]+a[5]>2*a[5]) c++;
		if(a[3]+a[4]+a[5]> 2*a[5]) c++;
	}
	cout<<c;
	return 0;	
}

#include<bits/stdc++.h>
using namespace std;
int n,i,a[5020],mx,x;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1; i<=n; i++) {
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx!=1) {
		if(n==3)if(a[1]+a[2]+a[3]>2*mx)x++;
		if(n==4) {
			if(a[1]+a[2]+a[3]>2*mx)x++;
			if(a[1]+a[2]+a[4]>2*mx)x++;
			if(a[1]+a[4]+a[3]>2*mx)x++;
			if(a[4]+a[2]+a[3]>2*mx)x++;
			if(a[1]+a[2]+a[3]+a[4]>2*mx)x++;
		}
		if(n==5) {
			if(a[1]+a[2]+a[3]>2*mx)x++;
			if(a[1]+a[2]+a[5]>2*mx)x++;
			if(a[1]+a[2]+a[4]>2*mx)x++;
			if(a[1]+a[4]+a[3]>2*mx)x++;
			if(a[1]+a[3]+a[5]>2*mx)x++;
			if(a[1]+a[4]+a[5]>2*mx)x++;
			if(a[4]+a[2]+a[3]>2*mx)x++;
			if(a[5]+a[2]+a[3]>2*mx)x++;
			if(a[4]+a[2]+a[5]>2*mx)x++;
			if(a[1]+a[2]+a[3]+a[4]>2*mx)x++;
			if(a[1]+a[2]+a[3]+a[5]>2*mx)x++;
			if(a[5]+a[2]+a[3]+a[4]>2*mx)x++;
			if(a[1]+a[5]+a[3]+a[4]>2*mx)x++;
		}
	} else {
		a[3]=1;
		for(i=4; i<=5000; i++)a[i]=a[i-1]+i+1;
		cout<<a[n];
	}
}

#include<bits/stdc++.h>
using namespace std;
long long a[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,js=0;
	cin>>n;
	int m=3;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3) {
		if(a[1]+a[2]+a[3]>a[3]*2) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	if(n==4) {
		int ans=0;
		if(a[1]+a[2]+a[3]>a[3]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[4]>a[4]*2) {
			ans++;
		}
		if(a[4]+a[2]+a[3]>a[4]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) {
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(n==5) {
		int ans=0;
		if(a[1]+a[2]+a[3]>a[3]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[4]>a[4]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[5]>a[5]*2) {
			ans++;
		}
		if(a[4]+a[2]+a[3]>a[4]*2) {
			ans++;
		}
		if(a[4]+a[2]+a[5]>a[5]*2) {
			ans++;
		}
		if(a[5]+a[2]+a[3]>a[5]*2) {
			ans++;
		}
		if(a[5]+a[3]+a[4]>a[5]*2) {
			ans++;
		}
		if(a[1]+a[3]+a[4]>a[4]*2) {
			ans++;
		}
		if(a[1]+a[3]+a[5]>a[5]*2) {
			ans++;
		}
		if(a[1]+a[4]+a[5]>a[5]*2) {
			ans++;
		}
		if(a[1]+a[3]+a[5]+a[4]>a[5]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2) {
			ans++;
		}
		if(a[5]+a[2]+a[3]+a[4]>a[5]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[5]+a[4]>a[5]*2) {
			ans++;
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2) {
			ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}



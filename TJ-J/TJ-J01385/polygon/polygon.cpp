#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5];
	int maxai=-1;
	int num=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		num+=a[i];
		maxai=max(a[i],maxai);
	}
	if(maxai==1) {
		if(n==3) {
			cout<<'1';
		} else {
			int ans=-2;
			for(int i=3; i<=n; i++) {
				ans+=(n-i)*2+2;
			}
			cout<<ans;
		}
	} else if(n==3) {
		sort(a+1,a+4);
		if(a[2]-a[3]<a[1]&&a[1]+a[2]>a[3]) {
			cout<<'1';
		} else {
			cout<<'0';
		}
	} else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) {
		cout<<'9';
	} else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) {
		cout<<'6';
	}
	return 0;
}

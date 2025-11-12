#include<bits/stdc++.h>
using namespace std;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],s[5010];
	long long ans=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(n==3) {
		if(a[1]+a[2]>a[3]) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	for(int i=1; i<=n-2; i++) {
		for(int j=i+1; j<=n; j++) {
			int sum=s[j]-s[i-1];
			if(sum>2*a[j]) {
				ans++;
			}
		}
	}
	cout<<ans;
}


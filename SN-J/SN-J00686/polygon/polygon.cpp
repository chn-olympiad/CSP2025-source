//SN-J00686  汤佳忆  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000001],maxn=-INT_MAX,cnt,sum;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n<3) {
		cout<<0;
	}
	if(n==3) {
		if(sum>maxn) {
			cout<<1;
		} else {
			cout<<0;
		}
	}
	return 0;
}


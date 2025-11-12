#include<bits/stdc++.h>
using namespace std;
#define int long long
int q[200005];
int a[200005];
int n,k,cnt,t;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k) {
			cnt++;
			a[i]=0;
			q[i]=1;
		}
	}
	int c=0;
	int t1=0;
	int ans=0;
	for(int j=1; j<=n; j++) {
		t1=0;
		c=0;
		for(int i=j; i<=n; i++) {
			if(q[i]==1) {
				c=0;
			} else {
				c^=a[i];
				if(c==k) {
					t1++;
					c=0;
				}
			}
		}
		ans=max(ans,t1);
	}
	cout<<ans+cnt;
	return 0;
}

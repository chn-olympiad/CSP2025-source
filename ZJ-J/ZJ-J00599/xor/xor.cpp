#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N],cnt1,cnt2,ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) {
			cnt1++;
		}
		if(a[i]>=0&&a[i]<=1) {
			cnt2++;
		}
	}
	if(cnt1==n&&k==0) {
		cout<<n/2;
		return 0;
	}
	if(cnt2==n&&(k>=0&&k<=1)) {
		for(int i=1; i<=n; i++) {
			if(a[i]==0) {
				ans++;
			} else if(a[i]==1&&a[i-1]==1) {
				ans++;
				a[i]=0;
				a[i-1]=0;
			}
		}
		if(k==0) {
			cout<<ans;
		} else {
			cout<<cnt1;
		}
		return 0;
	}
	return 0;
}
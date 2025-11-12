#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,cnt;
long long a[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int l=1; l<=n;l++) {
		cnt=a[l];
		for(int r=l; r<=n; r++) {
			if(a[l]==k) {
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

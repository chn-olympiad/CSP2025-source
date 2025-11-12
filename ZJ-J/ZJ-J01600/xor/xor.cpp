#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k,a[500003],sum[500003];
int getsum(int l,int r) {
	return sum[r]^sum[l-1];
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i = 1; i<=n; i++) {
		cin>>a[i];
		sum[i] = a[i]^sum[i-1];
	}
	int ans = 0;
	for(int j = 1,i = 1;j<=n;) {
		i = j;
		bool flag = false;
		while(j<=n&&!flag) {
			int p = i;
			while(p<=j) {
				if(getsum(p,j)==k) {
					flag = true;
					ans++;
					break;
				}
				p++;
			}
			j++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

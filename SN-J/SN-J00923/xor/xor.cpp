#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,ans;
int a[500005],xor_[500005];
void f(int l,int sum) {
	ans = max(ans,sum);
	for(int j = l;j<=n;j++) {
		int x = xor_[j] ^ xor_[l - 1];
		if(x == k) {
			f(j + 1,sum + 1);
			break;
		}
	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		xor_[i] = xor_[i - 1] ^ a[i];
	}
	for(int i = 1;i<=n;i++) {
		f(i,0);
	}
	cout << ans << "\n";
	return 0;
}


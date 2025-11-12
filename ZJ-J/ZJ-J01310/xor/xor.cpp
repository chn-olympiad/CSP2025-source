#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int N=514514;

int a[N];
int n,k;

signed main() {
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		qz[i]=qz[i-1]^a[i];
	}
	int ans=0;
	int t=0;
	for(int i=1; i<=n; i++) {
		t^=a[i];
		if(t==k) {
			t=0;
			ans++;
		}
	}
	cout<<ans;
}

// 5555555555
//T_T T_T T_T T_T

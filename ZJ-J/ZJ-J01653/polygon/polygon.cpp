#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5050;
const int MOD = 998244353;

int a[N];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n; cin >> n;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	if(a[1] + a[2] > a[3]) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}

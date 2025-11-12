#include <bits/stdc++.h>
using namespace std;
const int T = 5e5 + 10;

long long a[T],s[T],f[T];

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for (long long i = 1;i <= n;i++){
		cin >> a[i];
	}
	memset(f,0,sizeof(f));
	f[0] = 0;
	for (long long i = 1;i <= n;i++){
		f[i] = max(f[i],f[i - 1]);
		long long x = 0;
		for (long long j = i;j >= 1;j--){
			x = x ^ a[j];
			if (x == k){
				f[i] = max(f[i],f[j - 1] + 1);
			}
		}
	}
	cout << f[n] << endl;
	return 0;
}

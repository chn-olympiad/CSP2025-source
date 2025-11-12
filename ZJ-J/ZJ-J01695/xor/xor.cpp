#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(0); \
cout.tie(0);
ll n, k, a[500005], f[500005], ans;
//f[i]:a1^a2^a3^...^ai
//al^...^ar = (a1^....^ar)^(a1^...^al)=f[r]^f[l - 1]
void fr() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
}
int main() {
	fr();
	IOS
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] ^ a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		cout << f[i] << " ";
//	}cout << "\n";
	for (int i = 1; i <= n;) {
		ll id = i;
		bool r = 1;//no ans
		while(id <= n) {
			for (int j = i; j <= id; j++) {
				if ((f[id] ^ f[j - 1]) == k) {
				//	cout << f[id] << " " << f[j - 1] << " " << (f[id] ^ f[j - 1]) << " ";
				//	cout << j << " " << id << "\n";
					r = 0;
					break;
				}
			}
			if (!r) {
				//have ans
				ans++;
				break; 
			}
			id++;
		}
		i = id + 1;
	}
	cout << ans;
	return 0;
}


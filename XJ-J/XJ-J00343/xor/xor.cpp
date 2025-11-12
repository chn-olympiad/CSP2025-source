#include <bits/stdc++.h>

#define ULL unsigned long long 
#define LL long long

using namespace std;

const int N = 5e5 + 10;
LL n;
ULL k;
LL ans;
ULL a[N], s[N];
int b[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout); 
	
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		s[i] = a[i] ^ s[i - 1]; 
	}
	for(int i = 1; i <= n; i ++) //求出有多少个相等的由i~b[i]亦或和区间
		for(int j = i; j <= n; j ++) {
			ULL l = s[j] ^ s[i - 1];
//			cout << i << " " << j << " " << l << endl;
//			if(l == k) ans ++, cout << l << k << "GET" << endl;
			if(l == k) {
				if(b[i] != 0)b[i] = min(b[i], j);
				else b[i] = j;
			}
		}
//	cout << ans;
//	for(int i = 1; i <= n; i ++)
//		cout << i << " " << b[i] << endl;

	//查重 
	int kk = 0x3f3f3f3f;
	bool cntt = 0;
	for(int i = 1; i <= n; i ++)  {
		if(i > kk) {
			cntt = 0;
			kk = 0x3f3f3f3f;
		}
		if(b[i] != 0) {
//			cout << "GET" << i << " " << b[i] << " " << cntt << " " << kk << " ";
			if(cntt == 0) {
				ans ++;
			}
			kk = min(b[i], kk);
			cntt = 1;
//			cout << " " << min(b[i], kk) << " " << kk << endl;
		}
	}
	cout << ans;
}
//吾日三省吾身：写freopen乎，开longlong乎，freopen无数字乎

#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
const int N = 5e6 + 5, bas = 29;
int n, q;
unsigned int a[N], b[N], A[N], B[N], frc[N], siz[N];
unsigned int clac(unsigned int hsh[], int l, int r){
	return hsh[r] - hsh[l - 1] * frc[r - l + 1];
}
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	frc[0] = 1;
	rep(i, 1, 5e6) frc[i] = frc[i - 1] * bas;
	rep(i, 1, n){
		string S1, S2;
		cin >> S1 >> S2;
		for(auto x : S1)
			a[i] = a[i] * bas + x - 'a';
		for(auto x : S2)
			b[i] = b[i] * bas + x - 'a';
		siz[i] = S1.size();
	}
	while(q--){
		string S1, S2;
		cin >> S1 >> S2;
		int nn = S1.size(), ans = 0;
		S1 = ' ' + S1, S2 = ' ' + S2;
		rep(i, 1, nn){
			A[i] = A[i - 1] * bas + S1[i] - 'a';
			B[i] = B[i - 1] * bas + S2[i] - 'a';
		}
		rep(i, 1, n)
			rep(j, 1, nn)
				if(j + siz[i] - 1 <= nn)
					if(clac(A, j, j + siz[i] - 1) == a[i] &&
					   clac(B, j, j + siz[i] - 1) == b[i] &&
					   clac(A, 1, j - 1) == clac(B, 1, j - 1) &&
					   clac(A, j + siz[i], nn) == clac(B, j + siz[i], nn))
		                 ++ans;
		cout << ans << '\n'; 
	}
	return 0;
}


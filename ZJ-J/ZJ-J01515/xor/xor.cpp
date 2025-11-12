#include <bits/stdc++.h>
using namespace std;
int a[100002], k, n, b[100002], ans, f1;
struct aa{
	int b;
	string s;
	string a1;
}c[200003];
string mxor(string x, string y){
	string ans;
	for (int i = 0; i < max(x.size(), y.size()); i++){
		if (i < min(x.size(), y.size())){
			if (x[i] == y[i]){
				ans += '0';
			}else{
				ans += '1';
			}
		}
		if (i >= x.size()){
			if (y[i] == '0'){
				ans += '0';
			}else{
				ans += '1';
			}
		}else if (i >= y.size()){
			if (x[i] == '0'){
				ans += '0';
			}else{
				ans += '1';
			}
		}
	}
	return ans;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] == 0){
			f1 = 1;
		}
	}
	if (k == 0){
		if (f1){
			int t;
			for (int i = 1; i <= n; i++){
				if (a[i] == 0){
					t++;
				}
				if (a[i] == 1 && a[i - 1] == 1 && b[i - 1] != 1){
					t++;
					b[i] = 1;
				}
			}
			cout << t;
			return 0;
		}
		cout << n / 2;
		return 0;
	}
	if (k == 1){
		for (int i = 2; i <= n; i++){
			if (a[i] != a[i - 1] && b[i - 1] != 1){
				ans++;
				b[i] = 1;
			}
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= n; i++){
		c[i].b = a[i];
		int t = c[i].b;
		while (t){
			c[i].s += (t % 2 + '0');
			t /= 2;
		}
	}
	int d = 1;
	string f2 = c[1].s;
	c[1].a1 = f2;
	for (int i = 2; i <= n; i++){
		f2 = mxor(f2, c[i].s);
		c[i].a1 = f2;
	}
	for (int i = 1; i <= n; i++){
		for (int j = i; j >= d; j--){
			f1 = 0;
			string f = mxor(c[i].a1, c[j - 1].a1);
			for (int y = f.size() - 1; y >= 0; y--){
				f1 *= 2;
				f1 += (f[y] - '0');
			}
			if (f1 == k){
				ans++;
				d = i + 1;
				break;
			}
		}
	}
	cout << ans; 
	return 0;
}
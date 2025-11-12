#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n, q;
string str1, str2;
map<string, string >mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> str1 >> str2;
		mp[str1] = str2;
	}
	while (q--) {
		cin >> str1 >> str2;
		string x;
		int l = str1.size();
		str1 = " " + str1;
		str2 = " " + str2;
		int ans = 0;
		for (int i = 1; i <= l; i++) {
			for (int j = i + 1; j <= l; j++) {
				string y, z;
				for (int k = i; k <= j; k++) {
					y += str1[k];
				}
				for (int k = j + 1; k <= l; k++) {
					z += str1[k];
				}
//				cout << x +mp[y] + z << '\n';
				if (" "+x + mp[y] + z == str2)ans++;
			}
			x += str1[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
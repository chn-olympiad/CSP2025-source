#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
int a[200005];//相比s1，s2左移的位数

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int f1 = s1.find('b');
		int f2 = s2.find('b');
		a[f1 - f2]++;
	}
	for (int i = 1; i <= q; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int f1 = s1.find('b');
		int f2 = s2.find('b');
		cout << a[f1 - f2] << endl;
	}
}
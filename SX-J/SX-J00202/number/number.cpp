#include <bits/stdc++.h>
using namespace std;
string a, m, l;
int p, c;

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> a;
	int b = a.size();
	for (int i = 0; i < b; i++) {
		if (a[i] == '0' || a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6'
		        || a[i] == '7' || a[i] == '8' || a[i] == '9')	{
			m = a[i];
		}
	}
	for (int j = 0; j < c; j++) {
		cout << c;
		if (m[j] >= m[j + 1])
			break;
		else {
			p = m[j + 1];
			m[j + 1] = m[j];
			m[j] = p;
		}
		l = l + m[j];
	}

	cout << m << endl;
	return 0;

}
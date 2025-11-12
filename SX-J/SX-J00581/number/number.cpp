#include <bits/stdc++.h>
using namespace std;
char s[1000010];
long long a[1000010];
bool b[1000010];

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> s;
	int n = strlen(s);
	int ans = 0;
	int ai = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			ans++;
			if (s[i] == '1') {
				a[ai] = 1;

			} else if (s[i] == '2') {
				a[ai] = 2;
			} else if (s[i] == '3') {
				a[ai] = 3;
			} else if (s[i] == '4') {
				a[ai] = 4;
			} else if (s[i] == '5') {
				a[ai] = 5;
			} else if (s[i] == '6') {
				a[ai] = 6;
			} else if (s[i] == '7') {
				a[ai] = 7;
			} else if (s[i] == '8') {
				a[ai] = 8;
			} else if (s[i] == '9') {
				a[ai] = 9;
			} else if (s[i] == '0') {
				a[ai] = 0;
			}
//||||||||||||||||||||
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			cout << "a[" << ai << "]=" << a[ai] << endl;
			ai++;

		}
	}
///	for (int i = 0; i < ai; i++) {
//		cout << "a[" << i << "]=" << a[i] << endl;
//	}
	/*	for (int i = 0; i < ans; i++) {
			cout << "a[" << i << "]=" << a[i] << endl;
		}*/
	long long anss = 0;
	long long xb = 0;  //记录下标

	for (int j = 0; j < ans; j++) {
		int p = -1;
		for (int i = 0; i < ans; i++) {
			if (b[i] == false) {
				if (a[i] > p) {
					p = a[i];
					xb = i;
//					cout << "p=" << p << endl;
				}
			}
		}
//		cout << "p=" << p << endl;
///		cout << endl;
		b[xb] = true;
		long long gs = 0;   //false的个数
		for (int i = 0; i < ans; i++) {
			if (b[i] == false) {
				gs++;
			}
		}
//		cout << "gs=" << gs << endl;
		long long dqsz = p; //当前的数字
		for (int i = 1; i <= gs; i++) {
			dqsz = dqsz * 10;
		}
//		cout << "dqsz=" << dqsz << endl;
		anss += dqsz;
	}
	cout << anss;
//////	fclose(stdin);
//	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
//inculde<bits.stdc++/h<
using namespace std;
//using namspace sdt;
int n, m, sum = 1; //n行m列sum名次


//int mian(){}
int main() {
	freopen("seat.in", "r", stdin);
//freeopen("saet.in"."w"."stdout);
//freeopen('seat.out'.'r'.stdin);

	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int a;
	cin >> a;
	for (int i = 1; i < n * m; i++) {
		int b;
		cin >> b;
		if (b > a) {
			sum++;
		}
	}
	int p = sum / n + 1, q = sum % n;
	if (q == 0)
		q = n;
	if (p % 2) {
		cout << p << " " << q;
	} else {
		cout << p << " " << n - q + 1;
	}
	return 0;
}
//以上注释代码均为创某编程机构曹某老师所教，货真价实，无添改

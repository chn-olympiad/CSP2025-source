#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a,c;
	int b[10];
	for (int i = 1; i <= 10; i++) {
		b[i]=i*11;
	}
	cin >> a;
	int n;
	if (a <= 10) {
		cout << a;
	}
	if (a > 10 and a < 89) {
		for (int i = 1; i <=10; i++) {
			if (b[i] == a) {
				cout << a;
			}
		}
		if(a == 11) {
			cout << 11;
		} else if (a < 20) {
			for (int i = 1; i <=a-10 ; i++) {

				n = a+9*(i-1);
			}
			cout << n;
		}
	}
	if (a >= 90 and a <=100) {
		cout << a;
	}
	return 0;
}

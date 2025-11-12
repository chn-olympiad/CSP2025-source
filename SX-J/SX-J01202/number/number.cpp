#include <bits/stdc++.h>
using namespace std;
char s[100];

int main() {
//	freopen("number.in","r",stdin);
//	freopen("number.out","r",stdout);

	cin.getline (s, 100);
	int a;

	for (int i = 0; i <= a; i++) {

//		cin >> a[i];
		if (a[i] <= "9" && a[i] >= "1") {
			cout << a[i];
		}
		if (a[i][1] > a[i][i - 1]) {
			cout << a[1];
		} else {
			cout << a[i]++;
		}
	}

}
cout << a[i];



return 0;
}

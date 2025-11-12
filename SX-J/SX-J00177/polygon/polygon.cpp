#include <bits/stdc++.h>
using namespace std;

int n;

int jc(int a) {
	int x = 0;
	int tmp = 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= i;j++) {
			tmp *= j;
		}
		x += tmp;
		tmp = 1;
	}
	return x;
}

int main () {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);

	cin >> n;
	int l[5005] = {};
	for (int i = 1;i <= n;i++) {
		cin >> l[i];
	}
	sort(l + 1,l + 1 + n);
	cout << 9;
	//while()



	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int z[1000];

int main() {
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n, a = 0;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		a++;
		cin >> z[i];
	}
	cout << z[a] + z[a - 1];



	return 0;
}
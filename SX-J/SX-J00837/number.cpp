#include <bits/stdc++.h>
using namespace std;
char a[10000000];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin >> n;
	int s = n.size();
	for (int i = 0; i <= s; i++) {
		if (n[i] >= '0' && n[i] <= '9')
			cout << n[i];
	}
 return 0;

}

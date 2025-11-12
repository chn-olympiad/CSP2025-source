#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(int x, int y) {
	if (x != y)
		return x > y;
}

int main() {
//freopen("number.in","r",stdin)
//freopen("number.out","w",stdout)
	int s[100000];
	int sum = 0;
	string o;
	cin >> o;
	int i;
	for (i = 0; i <= o.size(); i++) {
		s[i] = int(o[i]);
		sum++;
	}
}

for (int y = 1; y <= sum; y++) {
	cout << s[y];
}
return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, m, c, r;
int Rc;//中间变量
vector<int> a;

bool cmp(int n1, int n2) {
	return n1 > n2;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	//in
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * m; i++) {
		int ai;
		scanf("%d", &ai);
		if (i == 0)
			Rc = ai;
		a.push_back(ai);
	}
	if (m == 1) {
		printf("%d %d", n, m);
		return 0;
	}
	//work
	sort(a.begin(), a.end(), cmp);
	int dex = 0;
	for (; dex < a.size(); dex++) {
		if (a[dex] == Rc)
			break;
	}
	dex++;
	c = (dex / n) + 1;
	r = (dex % n);
	//校正c
	if (dex % n == 0)
		c--;
	//校正r
	if (r == 0) {
		if ((dex / n) % 2 == 1)
			r = n;
		if ((dex / n) % 2 == 0)
			r = 1;
	} else if (r == 1 && c != 1) {
		if (c % 2 == 1)
			r = 1;
		if (c % 2 == 0)
			r = n;
	}
	printf("%d %d", c, r);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, score[10005], goal, num;

bool cmp(int a, int b) {
	return a > b;
}

void get_ans(int x) {
	int k = ceil(x / (n * 1.0));
	cout << k  << " ";
	if (k % 2 == 0)
		cout << n - x % n + 1;
	else
		cout <<  (x - 1) % n + 1;
	return;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> score[i];
	goal = score[1];
	sort(score + 1, score + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
		if (score[i] == goal)
			num = i;
	get_ans(num);
	return 0;
}

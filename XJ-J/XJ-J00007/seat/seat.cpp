#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 13, MAXM = 13;
struct Student {
	int grade;
	bool R;
	bool operator < (const Student &y)const {
		return grade > y.grade;
	}
}s[MAXN * MAXM];
int main(void) {
	ios :: sync_with_stdio(false);
	cin . tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n * m; ++i) {
		cin >> s[i].grade;
		s[i].R = (i == 1 ? true : false);
	}
	sort(s + 1, s + 1 + n * m);
	int head = 1;
	while (!s[head].R)
		++head;
	int list = (head + n - 1) / n, line = head - (list - 1) * n;
	if (list % 2 == 0)
		line = n - line + 1;
	cout << list << ' ' << line;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Student {
	long long a;
	long long b;
	long long c;
};
long long dp1[11111], dp2[11111], dp3[11111];
bool v[11111];

bool cmp1 (Student s1, Student s2) {
	if (s1.a != s2.a)
		return s1.a > s2.a;
	if (s1.b != s2.b)
		return s1.b > s2.b;
	return s1.c > s2.c;
}

bool cmp2 (Student s1, Student s2) {
	if (s1.a != s2.a)
		return s1.a > s2.a;
	if (s1.c != s2.c)
		return s1.c > s2.c;
	return s1.b > s2.b;
}

bool cmp3 (Student s1, Student s2) {
	if (s1.b != s2.b)
		return s1.b > s2.b;
	if (s1.a != s2.a)
		return s1.a > s2.a;
	return s1.c > s2.c;
}

bool cmp4 (Student s1, Student s2) {
	if (s1.b != s2.b)
		return s1.b > s2.b;
	if (s1.c != s2.c)
		return s1.c > s2.c;
	return s1.a > s2.a;
}

bool cmp5 (Student s1, Student s2) {
	if (s1.c != s2.c)
		return s1.c > s2.c;
	if (s1.a != s2.a)
		return s1.a > s2.a;
	return s1.b > s2.b;
}

bool cmp6 (Student s1, Student s2) {
	if (s1.c != s2.c)
		return s1.c > s2.c;
	if (s1.b != s2.b)
		return s1.b > s2.b;
	return s1.a > s2.a;
}

int main() {
	freopen("club2.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long T;
	cin >> T;
	while (T > 0) {
		T--;
		long long n;
		cin >> n;
		Student st[n + 1];
		long long A = 0, B = 0, C = 0;
		for (long long i = 1; i <= n; i++) {
			cin >> st[i].a >> st[i].b >> st[i].c;
			A += st[i].a;
			B += st[i].b;
			C += st[i].c;
		}
		long long ANS = 0;
		long long ans = 0;

		sort(st + 1, st + 1 + n, cmp1);
		for (long long i = 1; i <= n / 2; i++)
			ans += max(st[i].a, st[i].);
		for (long long i = n / 2 + 1; i <= n; i++)
			ans += max(st[i].b, st[i].c);
		ANS = max(ANS, ans);
		ans = 0;

		sort(st + 1, st + 1 + n, cmp3);
		for (long long i = 1; i <= n / 2; i++)
			ans += st[i].b;
		for (long long i = n / 2 + 1; i <= n; i++)
			ans += max(st[i].a, st[i].c);
		ANS = max(ANS, ans);
		ans = 0;

		sort(st + 1, st + 1 + n, cmp5);
		for (long long i = 1; i <= n / 2; i++)
			ans += st[i].c;
		for (long long i = n / 2 + 1; i <= n; i++)
			ans += max(st[i].a, st[i].b);
		ANS = max(ANS, ans);
		ans = 0;

		cout << ANS << '\n';
	}
	return 0;
}
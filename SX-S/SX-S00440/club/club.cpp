#include <bits/stdc++.h>
using namespace std;
int t, n;

struct Node {
	int num1, num2;
};

bool operator <(const Node &A, const Node &B) {
	return min(A.num1, A.num2) > min(B.num1, B.num2);
}

void mian() {
	int num1, num2, num3, s1 = 0, s2 = 0, s3 = 0, ans = 0;
	priority_queue <Node> q1, q2, q3;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &num1, &num2, &num3);
		if (num1 >= num2 && num1 >= num3)
			q1.push({num1 - num2, num1 - num3}), ans += num1, s1 ++;
		else if (num2 >= num1 && num2 >= num3)
			q2.push({num2 - num1, num2 - num3}), ans += num2, s2 ++;
		else
			q3.push({num3 - num1, num3 - num2}), ans += num3, s3 ++;
	}
	while (s1 > n / 2) {
		Node tp = q1.top();
		q1.pop();
		s1 --;
		if (tp.num1 < tp.num2)
			q2.push({tp.num1, (int)abs(tp.num2 - tp.num1)}), ans -= tp.num1;
		else
			q3.push({tp.num2, (int)abs(tp.num2 - tp.num1)}), ans -= tp.num2;
	}
	while (s2 > n / 2) {
		Node tp = q2.top();
		q2.pop();
		s2 --;
		if (tp.num1 < tp.num2)
			q1.push({tp.num1, (int)abs(tp.num2 - tp.num1)}), ans -= tp.num1;
		else
			q3.push({tp.num2, (int)abs(tp.num2 - tp.num1)}), ans -= tp.num2;
	}
	while (s3 > n / 2) {
		Node tp = q3.top();
		q3.pop();
		s3 --;
		if (tp.num1 < tp.num2)
			q1.push({tp.num1, (int)abs(tp.num2 - tp.num1)}), ans -= tp.num1;
		else
			q2.push({tp.num2, (int)abs(tp.num2 - tp.num1)}), ans -= tp.num2;
	}
	printf("%d\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t --)
		mian();
	return 0;
}
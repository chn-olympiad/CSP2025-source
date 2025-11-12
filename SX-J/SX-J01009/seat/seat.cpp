#include <bits/stdc++.h>
using namespace std;
int n, m, grade_of_R, minci_of_R, lei_of_R, hang_of_R;

struct node {
	int fenshu;
	int minci;
} a[105];

bool cmp(node x, node y) {
	return x.fenshu > y.fenshu;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].fenshu);
	}
	grade_of_R = a[1].fenshu;
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (grade_of_R == a[i].fenshu) {
			minci_of_R = i;
			break;
		}
	}
	if (minci_of_R % n == 0) {
		lei_of_R = minci_of_R / n;
	} else {
		lei_of_R = (minci_of_R / n + 1);
	}
	if (minci_of_R % n == 0) {
		if (lei_of_R % 2 == 0) {
			hang_of_R = 1;
		} else {
			hang_of_R = n;
		}
	} else {
		int wei = minci_of_R % n;
		if (lei_of_R % 2 == 0) {
			hang_of_R = n - wei + 1;
		} else {
			hang_of_R = wei;
		}
	}
	printf("%d %d", lei_of_R, hang_of_R);
	return 0;
}
/*
1.读入n和m及成绩
2.用struct储存成绩和名次
3.用R的名次%m
4.如果R的名次%m==0，在R的名次/m列，否则在（R的名次/m + 1）列
5.奇数列从前往后，偶数列从后往前
6.R的行：if(R的名次%m == 0),在最后一位，else在R的名次%m位
*/
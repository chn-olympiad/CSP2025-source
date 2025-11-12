#include <bits/stdc++.h>
using namespace std;
int n, m; //行数，列数
int seat[15][15];//座位表
int a[105];//学生成绩
int ts = 0; //小R的成绩
int sr = 0;//排序后小R的位置

void find(int l, int left, int right) { //二分查找,，left为左指针,right为右指针
	int mid = left + (right - left) / 2; //mid为当前查找位置
	if (l == a[mid]) {
		sr = mid;//
		return;
	}
	if (l < a[mid]) { //往后查找
		left = mid;
		find(l, left, right);
	}
	if (l > a[mid]) { //往前查找
		right = mid;
		find(l, left, right);
	}
}

bool cmp(int c, int b) {
	return (c > b);
}

void jisuan(int r) {
	int line = (r + (r % n)) / n; //具体列数
	int s = r % n;//行数
	if (s == 0)
		s = n;
	int row = 0;
	if (line % 2 == 0) {
		//偶数列，从后往前
		row = n - s + 1; //具体列数
	} else {
		row = s;//奇数列，直接取s(s不为零)
	}
	cout << line << " " << row;
	return ;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int c = n * m; //学生数量
	for (int i = 1; i <= c; i++) {
		cin >> a[i];
	}
	ts = a[1];
	sort(a + 1, a + c + 1, cmp);
	find(ts, 1, c);//计算排序后小R的位置
//	cout << sr;
	jisuan(sr);//计算排序后小R的座位号
	return 0;
}
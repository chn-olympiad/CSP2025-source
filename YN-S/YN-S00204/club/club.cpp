#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long n, t;
long long A = 0, B = 0, C = 0, sum = 0;

struct node {
	int datamax1;
	int datamax2;
	int d1;
	int d2;
} maxx[N];
long long max2 = -1;//第二大的数
long long m1d = -1, m2d = -1;

int qmax(int a, int b, int c) {//求3个数的最大值
	int max1;
	if (a >= b && b >= c) {
		max1 = a;
		max2 = b;
		m1d = 1;
		m2d = 2;
	} else if (a >= c && c >= b) {
		max1 = a;
		max2 = c;
		m1d = 1;
		m2d = 3;
	}

	else if (b >= a && a >= c) {
		max1 = b;
		max2 = a;
		m1d = 2;
		m2d = 1;
	} else if (b >= c && c >= b) {
		max1 = b;
		max2 = c;
		m1d = 2;
		m2d = 3;
	} else if (c >= a && a >= b) {
		max1 = c;
		max2 = a;
		m1d = 3;
		m2d = 1;
	} else if (c >= b && b >= a) {
		max1 = c;
		max2 = b;
		m1d = 3;
		m2d = 2;
	}
	return max1;
}

bool cmp(node a, node b) {//排序
	return a.datamax1 > b.datamax2;
}

int find_d2(int w) {//B计划：输入第二大的数的坐标
	if (w == 1) {//如果第二大的数属于集合A
		A++;//集合A人数+=1
	} else if (w == 2) {//如果第二大的数属于集合B
		B++;//集合B人数+=1
	} else if (w == 3) {//如果第二大的数属于集合C
		C++;//集合C人数+=1
	}
	return 0;
}
int c = 0, cc = 0, ccc = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a1, a2, a3;
			cin >> a1 >> a2 >> a3;
			maxx[i].datamax1 = qmax(a1, a2, a3);//最大的数
			maxx[i].datamax2 = max2;//第二大的数
			maxx[i].d1 = m1d;//最大的数的坐标
			maxx[i].d2 = m2d;//第二大的数的坐标
			max2 = -1;//初始化
			m1d = -1;
			m2d = -1;
		}
		sort(maxx + 1, maxx + 1 + n, cmp);//排序

//		for (int i = 1; i <= n + 1; i++) {
//			cout << maxx[i].datamax1 << " " ; //最大的数
//			cout << maxx[i].datamax2 << " "; //第二大的数
//			cout << maxx[i].d1 << " "; //最大的数的坐标
//			cout << maxx[i].d2 << endl; //第二大的数的坐标
//		}



		for (int i = n; i >= 1; i--) {//从大到小遍历
			if (maxx[i].d1 == 1) {//如果最大的数在第一个集合
				A++;//集合A人数+=1
				if (A <= n / 2 || c == 0) { //如果没超员
					sum += maxx[i].datamax1;//sum+=最大的数
				} else {//如果超员
					if (c == 0) {
						A--;
					}
					//退出集合
					c = 1;
					//find_d2(maxx[i].d2);//B计划：输入第二大的数的坐标
					sum += maxx[i].datamax2;//sum+=第二大的数
				}
			} else if (maxx[i].d1 == 2) {//如果最大的数在第二个集合
				B++;
				if (B <= n / 2 || cc == 0) {
					sum += maxx[i].datamax1;
				} else {
					if (c == 0) {
						B--;
					}
					cc = 1;
					//find_d2(maxx[i].d2);
					sum += maxx[i].datamax2;
				}
			} else if (maxx[i].d1 == 3) {//如果最大的数在第三个集合
				C++;
				if (C <= n / 2 || ccc == 0) {
					sum += maxx[i].datamax1;
				} else {
					if (c == 0) {
						C--;
					}
					ccc = 1;
					//find_d2(maxx[i].d2);
					sum += maxx[i].datamax2;
				}
			}
		}
		cout << sum << endl;
		A = 0;//初始化
		B = 0;
		C = 0;
		sum = 0;
		max2 = -1;
		m1d = -1;
		m2d = -1;
		maxx[N] = {};
	}

	return 0;
}



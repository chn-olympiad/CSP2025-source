#include <bits/stdc++.h>
using namespace std;

//第i个新成员对1，2，3个部门的满意度 0<=a[i][j]<=20000
//b数组用来标记对应a数组的部门
int a[100005][5];
int b[100005][5];

//满意度ans[]
//社团名额bns[]
int ans[100005];
int bns[3];

int main() {

	//临时数据
	int z = 1;

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	//测试数据组数 1<=t<=5
	int t;
	cin >> t;

	//新成员数量 2<=n<=100000 偶数
	int n;

	//名额
	int me = n / 2;

	//组
	for (int ii = 1; ii <= t; ii++) {
		cin >> n;

		//成员
		for (int i = 1; i <= n; i++) {

			//个人对不同社团满意度
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				b[i][j] = j;
			}

			//排序 swap交换 从小到大
			for (int m = 1; m < 3; m++) {
				if (a[i][m] > a[i][m + 1]) {
					swap(a[i][m], a[i][m + 1]);
					swap(b[i][m], b[i][m + 1]);
					if (m == 2 && a[i][1] > a[i][2]) {
						swap(a[i][1], a[i][2]);
						swap(b[i][1], b[i][2]);
					}
				}
			}

			//看每一组名额是否足够
			if (b[i][3] == 1)
				bns[1]++;
			if (b[i][3] == 2)
				bns[2]++;
			if (b[i][3] == 3)
				bns[3]++;

			while ((bns[1] > me || bns[2] > me || bns[3] > me) && z <= 3) {

				swap(a[z][3], a[z][2]);
				swap(b[z][3], b[z][2]);

				z++;

			}

			ans[ii] += a[i][3];
		}

	}

	//输出
	for (int i = 1; i <= t; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}
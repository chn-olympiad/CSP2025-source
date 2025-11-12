#include <bits/stdc++.h>
using namespace std;
int n1, n2, n3, n4, n5, d1, d2, d3; //n为新成员总数 dx为部门当前人数
int t;//测试数据组数
int ans1, ans2, ans3, ans4, ans5; //答案保存
int ansa, ansb, ansc;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int k = 0; k < t; k++) {
		cin >> n1;
		int arr1[4][n1];//每个成员对每个部门的满意程度数组arr1
		//arr数组输入
		for (int i = 0; i < n1; i++) {
			for (int j = 1; j < 4; j++) {
				cin >> arr1[j][i];
				arr1[0][i] = arr1[1][i] + arr1[2][i] + arr1[3][i];
			}
		}
		//个人总兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[0][j] > arr1[0][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		//初次试探 满意程度总和优先
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ans1 += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans1 += arr1[2][i];
					} else {
						d3++;
						ans1 += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ans1 += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans1 += arr1[3][i];
					} else {
						d2++;
						ans1 += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ans1 += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans1 += arr1[1][i];
					} else {
						d3++;
						ans1 += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ans1 += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans1 += arr1[3][i];
					} else {
						d1++;
						ans1 += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ans1 += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans1 += arr1[1][i];
					} else {
						d2++;
						ans1 += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ans1 += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans1 += arr1[2][i];
					} else {
						d1++;
						ans1 += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//总数倒序尝试
		//个人总兴趣量排序 倒序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[0][j] < arr1[0][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		//初次试探 满意程度总和优先
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ans5 += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans5 += arr1[2][i];
					} else {
						d3++;
						ans5 += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ans5 += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans5 += arr1[3][i];
					} else {
						d2++;
						ans5 += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ans5 += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans5 += arr1[1][i];
					} else {
						d3++;
						ans5 += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ans5 += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans5 += arr1[3][i];
					} else {
						d1++;
						ans5 += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ans5 += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans5 += arr1[1][i];
					} else {
						d2++;
						ans5 += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ans5 += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans5 += arr1[2][i];
					} else {
						d1++;
						ans5 += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//第一个社团 满意程度高 优先
		//个人第一个社团兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[1][j] > arr1[1][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ans2 += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans2 += arr1[2][i];
					} else {
						d3++;
						ans2 += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ans2 += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans2 += arr1[3][i];
					} else {
						d2++;
						ans2 += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ans2 += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans2 += arr1[1][i];
					} else {
						d3++;
						ans2 += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ans2 += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans2 += arr1[3][i];
					} else {
						d1++;
						ans2 += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ans2 += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans2 += arr1[1][i];
					} else {
						d2++;
						ans2 += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ans2 += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans2 += arr1[2][i];
					} else {
						d1++;
						ans2 += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//第一个社团 满意程度高 优先 倒序
		//个人第一个社团兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[1][j] < arr1[1][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ansa += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ansa += arr1[2][i];
					} else {
						d3++;
						ansa += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ansa += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ansa += arr1[3][i];
					} else {
						d2++;
						ansa += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ansa += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ansa += arr1[1][i];
					} else {
						d3++;
						ansa += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ansa += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ansa += arr1[3][i];
					} else {
						d1++;
						ansa += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ansa += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ansa += arr1[1][i];
					} else {
						d2++;
						ansa += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ansa += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ansa += arr1[2][i];
					} else {
						d1++;
						ansa += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//第二个社团 满意程度高 优先
		//个人第二个社团兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[2][j] > arr1[2][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ans3 += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans3 += arr1[2][i];
					} else {
						d3++;
						ans3 += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ans3 += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans3 += arr1[3][i];
					} else {
						d2++;
						ans3 += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ans3 += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans3 += arr1[1][i];
					} else {
						d3++;
						ans3 += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ans3 += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans3 += arr1[3][i];
					} else {
						d1++;
						ans3 += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ans3 += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans3 += arr1[1][i];
					} else {
						d2++;
						ans3 += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ans3 += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans3 += arr1[2][i];
					} else {
						d1++;
						ans3 += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//第2个社团 满意程度高 优先 倒序
		//个人第2个社团兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[2][j] < arr1[2][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ansb += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ansb += arr1[2][i];
					} else {
						d3++;
						ansb += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ansb += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ansb += arr1[3][i];
					} else {
						d2++;
						ansb += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ansb += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ansb += arr1[1][i];
					} else {
						d3++;
						ansb += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ansb += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ansb += arr1[3][i];
					} else {
						d1++;
						ansb += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ansb += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ansb += arr1[1][i];
					} else {
						d2++;
						ansb += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ansb += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ansb += arr1[2][i];
					} else {
						d1++;
						ansb += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//第三个社团 满意程度高 优先
		//个人第三个社团兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[3][j] > arr1[3][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ans4 += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans4 += arr1[2][i];
					} else {
						d3++;
						ans4 += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ans4 += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans4 += arr1[3][i];
					} else {
						d2++;
						ans4 += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ans4 += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans4 += arr1[1][i];
					} else {
						d3++;
						ans4 += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ans4 += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ans4 += arr1[3][i];
					} else {
						d1++;
						ans4 += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ans4 += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ans4 += arr1[1][i];
					} else {
						d2++;
						ans4 += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ans4 += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ans4 += arr1[2][i];
					} else {
						d1++;
						ans4 += arr1[1][i];
					}
				}
			}
		}
		//初始化
		d1 = 0;
		d2 = 0;
		d3 = 0;
		//第三个社团 满意程度高 优先 倒序
		//个人第三个社团兴趣量排序
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n1 - 1; j++) {
				if (arr1[3][j] < arr1[3][j + 1]) {
					swap(arr1[0][j], arr1[0][j + 1]);
					swap(arr1[1][j], arr1[1][j + 1]);
					swap(arr1[2][j], arr1[2][j + 1]);
					swap(arr1[3][j], arr1[3][j + 1]);
				}
			}
		}
		for (int i = 0; i < n1; i++) {
			if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
				if (d1 < n1 / 2) {
					d1++;
					ansc += arr1[1][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ansc += arr1[2][i];
					} else {
						d3++;
						ansc += arr1[3][i];
					}
				}
			}
			if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
				if (d1 < n1 / 2) {
					d1++;
					ansc += arr1[1][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ansc += arr1[3][i];
					} else {
						d2++;
						ansc += arr1[2][i];
					}
				}
			}

			if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
				if (d2 < n1 / 2) {
					d2++;
					ansc += arr1[2][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ansc += arr1[1][i];
					} else {
						d3++;
						ansc += arr1[3][i];
					}
				}
			}
			if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
				if (d2 < n1 / 2) {
					d2++;
					ansc += arr1[2][i];
				} else {
					if (d3 < n1 / 2) {
						d3++;
						ansc += arr1[3][i];
					} else {
						d1++;
						ansc += arr1[1][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
				if (d3 < n1 / 2) {
					d3++;
					ansc += arr1[3][i];
				} else {
					if (d1 < n1 / 2) {
						d1++;
						ansc += arr1[1][i];
					} else {
						d2++;
						ansc += arr1[2][i];
					}
				}
			}

			if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
				if (d3 < n1 / 2) {
					d3++;
					ansc += arr1[3][i];
				} else {
					if (d2 < n1 / 2) {
						d2++;
						ansc += arr1[2][i];
					} else {
						d1++;
						ansc += arr1[1][i];
					}
				}
			}
		}
		int ans = 0;
		if (ans1 > ans)
			ans = ans1;
//		cout << ans << "\n";
		if (ans2 > ans)
			ans = ans2;
//		cout << ans << "\n";
		if (ans3 > ans)
			ans = ans3;
//		cout << ans << "\n";
		if (ans4 > ans)
			ans = ans4;
//		cout << ans << "\n";
		if (ansa > ans)
			ans = ansa;
//		cout << ans << "\n";
		if (ansb > ans)
			ans = ansb;
//		cout << ans << "\n";
		if (ansc > ans)
			ans = ansc;
//		cout << ans << "\n";
		cout << ans << "\n";
		d1 = 0;
		d2 = 0;
		d3 = 0;
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		ans4 = 0;
		ans5 = 0;
		ansa = 0;
		ansb = 0;
		ansc = 0;
	}
//	cin >> n1;
//	int arr1[4][n1];//每个成员对每个部门的满意程度数组arr1
//	//arr数组输入
//	for (int i = 0; i < n1; i++) {
//		for (int j = 1; j < 4; j++) {
//			cin >> arr1[j][i];
//			arr1[0][i] = arr1[1][i] + arr1[2][i] + arr1[3][i];
//		}
//	}
//	//个人总兴趣量排序
//	for (int i = 0; i < n1; i++) {
//		for (int j = 0; j < n1 - 1; j++) {
//			if (arr1[0][j] > arr1[0][j + 1]) {
//				swap(arr1[0][j], arr1[0][j + 1]);
//				swap(arr1[1][j], arr1[1][j + 1]);
//				swap(arr1[2][j], arr1[2][j + 1]);
//				swap(arr1[3][j], arr1[3][j + 1]);
//			}
//		}
//	}
//	for (int i = 0; i < n1; i++) {
//		if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[3][i]) { //a1>a2>a3
//			if (d1 < n1 / 2) {
//				d1++;
//				ans1 += arr1[1][i];
//			} else {
//				if (d2 < n1 / 2) {
//					d2++;
//					ans1 += arr1[2][i];
//				} else {
//					d3++;
//					ans1 += arr1[3][i];
//				}
//			}
//		}
//		if (arr1[1][i] >= arr1[3][i] && arr1[3][i] >= arr1[2][i]) { //a1>a3>a2
//			if (d1 < n1 / 2) {
//				d1++;
//				ans1 += arr1[1][i];
//			} else {
//				if (d3 < n1 / 2) {
//					d3++;
//					ans1 += arr1[3][i];
//				} else {
//					d2++;
//					ans1 += arr1[2][i];
//				}
//			}
//		}
//
//		if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[3][i]) { //a2>a1>a3
//			if (d2 < n1 / 2) {
//				d2++;
//				ans1 += arr1[2][i];
//			} else {
//				if (d1 < n1 / 2) {
//					d1++;
//					ans1 += arr1[1][i];
//				} else {
//					d3++;
//					ans1 += arr1[3][i];
//				}
//			}
//		}
//		if (arr1[2][i] >= arr1[3][i] && arr1[3][i] >= arr1[1][i]) { //a2>a3>a1
//			if (d2 < n1 / 2) {
//				d2++;
//				ans1 += arr1[2][i];
//			} else {
//				if (d3 < n1 / 2) {
//					d3++;
//					ans1 += arr1[3][i];
//				} else {
//					d1++;
//					ans1 += arr1[1][i];
//				}
//			}
//		}
//
//		if (arr1[3][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a3>a1>a2
//			if (d3 < n1 / 2) {
//				d3++;
//				ans1 += arr1[3][i];
//			} else {
//				if (d1 < n1 / 2) {
//					d1++;
//					ans1 += arr1[1][i];
//				} else {
//					d2++;
//					ans1 += arr1[2][i];
//				}
//			}
//		}
//
//		if (arr1[3][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a3>a2>a1
//			if (d3 < n1 / 2) {
//				d3++;
//				ans1 += arr1[3][i];
//			} else {
//				if (d2 < n1 / 2) {
//					d2++;
//					ans1 += arr1[2][i];
//				} else {
//					d1++;
//					ans1 += arr1[1][i];
//				}
//			}
//		}
//	}
//	d1 = 0;
//	d2 = 0;
//	d3 = 0;
	//排序后输出测试
//	for (int i = 0; i < n1; i++) {
//		for (int j = 0; j < 4; j++) {
//			cout << arr1[j][i];
//		}
//		cout << endl;
//	}
//算法错误
//	for (int i = 0; i < n1; i++) {
//		if (arr1[0][i] >= arr1[1][i] && arr1[1][i] >= arr1[2][i]) { //a1>a2>a3
//			if (d1 < n1 / 2) {
//				d1++;
//				ans1 += arr1[0][i];
//			} else {
//				if (d2 < n1 / 2) {
//					d2++;
//					ans1 += arr1[1][i];
//				} else {
//					d3++;
//					ans1 += arr1[2][i];
//				}
//			}
//		}
//		if (arr1[0][i] >= arr1[2][i] && arr1[2][i] >= arr1[1][i]) { //a1>a3>a2
//			if (d1 < n1 / 2) {
//				d1++;
//				ans1 += arr1[0][i];
//			} else {
//				if (d3 < n1 / 2) {
//					d3++;
//					ans1 += arr1[2][i];
//				} else {
//					d2++;
//					ans1 += arr1[1][i];
//				}
//			}
//		}
//
//		if (arr1[1][i] >= arr1[0][i] && arr1[0][i] >= arr1[2][i]) { //a2>a1>a3
//			if (d2 < n1 / 2) {
//				d2++;
//				ans1 += arr1[1][i];
//			} else {
//				if (d1 < n1 / 2) {
//					d1++;
//					ans1 += arr1[0][i];
//				} else {
//					d3++;
//					ans1 += arr1[2][i];
//				}
//			}
//		}
//		if (arr1[1][i] >= arr1[2][i] && arr1[2][i] >= arr1[0][i]) { //a2>a3>a1
//			if (d2 < n1 / 2) {
//				d2++;
//				ans1 += arr1[1][i];
//			} else {
//				if (d3 < n1 / 2) {
//					d3++;
//					ans1 += arr1[2][i];
//				} else {
//					d1++;
//					ans1 += arr1[0][i];
//				}
//			}
//		}
//
//		if (arr1[2][i] >= arr1[0][i] && arr1[0][i] >= arr1[1][i]) { //a3>a1>a2
//			if (d3 < n1 / 2) {
//				d3++;
//				ans1 += arr1[2][i];
//			} else {
//				if (d1 < n1 / 2) {
//					d1++;
//					ans1 += arr1[0][i];
//				} else {
//					d2++;
//					ans1 += arr1[1][i];
//				}
//			}
//		}
//
//		if (arr1[2][i] >= arr1[1][i] && arr1[1][i] >= arr1[0][i]) { //a3>a2>a1
//			if (d3 < n1 / 2) {
//				d3++;
//				ans1 += arr1[2][i];
//			} else {
//				if (d2 < n1 / 2) {
//					d2++;
//					ans1 += arr1[1][i];
//				} else {
//					d1++;
//					ans1 += arr1[0][i];
//				}
//			}
//		}
//	}


//	if (t > 1) {
//		cin >> n2;
//		int arr2[3][n2];//每个成员对每个部门的满意程度数组arr2
//
//		for (int i = 0; i < n2; i++) {
//			for (int j = 0; j < 3; j++) {
//				cin >> arr2[j][i];
//				arr2[0][i] = arr2[1][i] + arr2[2][i] + arr2[3][i];
//			}
//		}
//		//个人总兴趣量排序
//		for (int i = 0; i < n2; i++) {
//			for (int j = 0; j < n2 - 1; j++) {
//				if (arr2[0][j] > arr2[0][j + 1]) {
//					swap(arr2[0][j], arr2[0][j + 1]);
//					swap(arr2[1][j], arr2[1][j + 1]);
//					swap(arr2[2][j], arr2[2][j + 1]);
//					swap(arr2[3][j], arr2[3][j + 1]);
//				}
//			}
//		}
//		for (int i = 0; i < n2; i++) {
//			if (arr2[1][i] >= arr2[2][i] && arr2[2][i] >= arr2[3][i]) { //a1>a2>a3
//				if (d1 < n2 / 2) {
//					d1++;
//					ans2 += arr2[1][i];
//				} else {
//					if (d2 < n2 / 2) {
//						d2++;
//						ans2 += arr2[2][i];
//					} else {
//						d3++;
//						ans2 += arr2[3][i];
//					}
//				}
//			}
//			if (arr2[1][i] >= arr2[3][i] && arr2[3][i] >= arr2[2][i]) { //a1>a3>a2
//				if (d1 < n2 / 2) {
//					d1++;
//					ans2 += arr2[1][i];
//				} else {
//					if (d3 < n2 / 2) {
//						d3++;
//						ans2 += arr2[3][i];
//					} else {
//						d2++;
//						ans2 += arr2[2][i];
//					}
//				}
//			}
//
//			if (arr2[2][i] >= arr2[1][i] && arr2[1][i] >= arr2[3][i]) { //a2>a1>a3
//				if (d2 < n2 / 2) {
//					d2++;
//					ans2 += arr2[2][i];
//				} else {
//					if (d1 < n2 / 2) {
//						d1++;
//						ans2 += arr2[1][i];
//					} else {
//						d3++;
//						ans2 += arr2[3][i];
//					}
//				}
//			}
//			if (arr2[2][i] >= arr2[3][i] && arr2[3][i] >= arr2[1][i]) { //a2>a3>a1
//				if (d2 < n2 / 2) {
//					d2++;
//					ans2 += arr2[2][i];
//				} else {
//					if (d3 < n2 / 2) {
//						d3++;
//						ans2 += arr2[3][i];
//					} else {
//						d1++;
//						ans2 += arr2[1][i];
//					}
//				}
//			}
//
//			if (arr2[3][i] >= arr2[1][i] && arr2[1][i] >= arr2[2][i]) { //a3>a1>a2
//				if (d3 < n2 / 2) {
//					d3++;
//					ans2 += arr2[3][i];
//				} else {
//					if (d1 < n2 / 2) {
//						d1++;
//						ans2 += arr2[1][i];
//					} else {
//						d2++;
//						ans2 += arr2[2][i];
//					}
//				}
//			}
//
//			if (arr2[3][i] >= arr2[2][i] && arr2[2][i] >= arr2[1][i]) { //a3>a2>a1
//				if (d3 < n2 / 2) {
//					d3++;
//					ans2 += arr2[3][i];
//				} else {
//					if (d2 < n2 / 2) {
//						d2++;
//						ans2 += arr2[2][i];
//					} else {
//						d1++;
//						ans2 += arr2[1][i];
//					}
//				}
//			}
//		}
//	}
//	d1 = 0;
//	d2 = 0;
//	d3 = 0;
//	if (t > 2) {
//		cin >> n3;
//		int arr3[3][n3];//每个成员对每个部门的满意程度数组arr3
//
//		for (int i = 0; i < n3; i++) {
//			for (int j = 0; j < 3; j++) {
//				cin >> arr3[j][i];
//				arr3[0][i] = arr3[1][i] + arr3[2][i] + arr3[3][i];
//			}
//		}
//		//个人总兴趣量排序
//		for (int i = 0; i < n3; i++) {
//			for (int j = 0; j < n3 - 1; j++) {
//				if (arr3[0][j] > arr3[0][j + 1]) {
//					swap(arr3[0][j], arr3[0][j + 1]);
//					swap(arr3[1][j], arr3[1][j + 1]);
//					swap(arr3[2][j], arr3[2][j + 1]);
//					swap(arr3[3][j], arr3[3][j + 1]);
//				}
//			}
//		}
//		for (int i = 0; i < n3; i++) {
//			if (arr3[1][i] >= arr3[2][i] && arr3[2][i] >= arr3[3][i]) { //a1>a2>a3
//				if (d1 < n3 / 2) {
//					d1++;
//					ans3 += arr3[1][i];
//				} else {
//					if (d2 < n3 / 2) {
//						d2++;
//						ans3 += arr3[2][i];
//					} else {
//						d3++;
//						ans3 += arr3[3][i];
//					}
//				}
//			}
//			if (arr3[1][i] >= arr3[3][i] && arr3[3][i] >= arr3[2][i]) { //a1>a3>a2
//				if (d1 < n3 / 2) {
//					d1++;
//					ans3 += arr3[1][i];
//				} else {
//					if (d3 < n3 / 2) {
//						d3++;
//						ans3 += arr3[3][i];
//					} else {
//						d2++;
//						ans3 += arr3[2][i];
//					}
//				}
//			}
//
//			if (arr3[2][i] >= arr3[1][i] && arr3[1][i] >= arr3[3][i]) { //a2>a1>a3
//				if (d2 < n3 / 2) {
//					d2++;
//					ans3 += arr3[2][i];
//				} else {
//					if (d1 < n3 / 2) {
//						d1++;
//						ans3 += arr3[1][i];
//					} else {
//						d3++;
//						ans3 += arr3[3][i];
//					}
//				}
//			}
//			if (arr3[2][i] >= arr3[3][i] && arr3[3][i] >= arr3[1][i]) { //a2>a3>a1
//				if (d2 < n3 / 2) {
//					d2++;
//					ans3 += arr3[2][i];
//				} else {
//					if (d3 < n3 / 2) {
//						d3++;
//						ans3 += arr3[3][i];
//					} else {
//						d1++;
//						ans3 += arr3[1][i];
//					}
//				}
//			}
//
//			if (arr3[3][i] >= arr3[1][i] && arr3[1][i] >= arr3[2][i]) { //a3>a1>a2
//				if (d3 < n3 / 2) {
//					d3++;
//					ans3 += arr3[3][i];
//				} else {
//					if (d1 < n3 / 2) {
//						d1++;
//						ans3 += arr3[1][i];
//					} else {
//						d2++;
//						ans3 += arr3[2][i];
//					}
//				}
//			}
//
//			if (arr3[3][i] >= arr3[2][i] && arr3[2][i] >= arr3[1][i]) { //a3>a2>a1
//				if (d3 < n3 / 2) {
//					d3++;
//					ans3 += arr3[3][i];
//				} else {
//					if (d2 < n3 / 2) {
//						d2++;
//						ans3 += arr3[2][i];
//					} else {
//						d1++;
//						ans3 += arr3[1][i];
//					}
//				}
//			}
//		}
//	}
//	d1 = 0;
//	d2 = 0;
//	d3 = 0;
//	if (t > 3) {
//		cin >> n4;
//		int arr4[3][n4];//每个成员对每个部门的满意程度数组arr4
//
//		for (int i = 0; i < n4; i++) {
//			for (int j = 0; j < 3; j++) {
//				cin >> arr4[j][i];
//				arr4[0][i] = arr4[1][i] + arr4[2][i] + arr4[3][i];
//			}
//		}
//		//个人总兴趣量排序
//		for (int i = 0; i < n4; i++) {
//			for (int j = 0; j < n4 - 1; j++) {
//				if (arr4[0][j] > arr4[0][j + 1]) {
//					swap(arr4[0][j], arr4[0][j + 1]);
//					swap(arr4[1][j], arr4[1][j + 1]);
//					swap(arr4[2][j], arr4[2][j + 1]);
//					swap(arr4[3][j], arr4[3][j + 1]);
//				}
//			}
//		}
//		for (int i = 0; i < n4; i++) {
//			if (arr4[1][i] >= arr4[2][i] && arr4[2][i] >= arr4[3][i]) { //a1>a2>a3
//				if (d1 < n4 / 2) {
//					d1++;
//					ans4 += arr4[1][i];
//				} else {
//					if (d2 < n4 / 2) {
//						d2++;
//						ans4 += arr4[2][i];
//					} else {
//						d3++;
//						ans4 += arr4[3][i];
//					}
//				}
//			}
//			if (arr4[1][i] >= arr4[3][i] && arr4[3][i] >= arr4[2][i]) { //a1>a3>a2
//				if (d1 < n4 / 2) {
//					d1++;
//					ans4 += arr4[1][i];
//				} else {
//					if (d3 < n4 / 2) {
//						d3++;
//						ans4 += arr4[3][i];
//					} else {
//						d2++;
//						ans4 += arr4[2][i];
//					}
//				}
//			}
//
//			if (arr4[2][i] >= arr4[1][i] && arr4[1][i] >= arr4[3][i]) { //a2>a1>a3
//				if (d2 < n4 / 2) {
//					d2++;
//					ans4 += arr4[2][i];
//				} else {
//					if (d1 < n4 / 2) {
//						d1++;
//						ans4 += arr4[1][i];
//					} else {
//						d3++;
//						ans4 += arr4[3][i];
//					}
//				}
//			}
//			if (arr4[2][i] >= arr4[3][i] && arr4[3][i] >= arr4[1][i]) { //a2>a3>a1
//				if (d2 < n4 / 2) {
//					d2++;
//					ans4 += arr4[2][i];
//				} else {
//					if (d3 < n4 / 2) {
//						d3++;
//						ans4 += arr4[3][i];
//					} else {
//						d1++;
//						ans4 += arr4[1][i];
//					}
//				}
//			}
//
//			if (arr4[3][i] >= arr4[1][i] && arr4[1][i] >= arr4[2][i]) { //a3>a1>a2
//				if (d3 < n4 / 2) {
//					d3++;
//					ans4 += arr4[3][i];
//				} else {
//					if (d1 < n4 / 2) {
//						d1++;
//						ans4 += arr4[1][i];
//					} else {
//						d2++;
//						ans4 += arr4[2][i];
//					}
//				}
//			}
//
//			if (arr4[3][i] >= arr4[2][i] && arr4[2][i] >= arr4[1][i]) { //a3>a2>a1
//				if (d3 < n4 / 2) {
//					d3++;
//					ans4 += arr4[3][i];
//				} else {
//					if (d2 < n4 / 2) {
//						d2++;
//						ans4 += arr4[2][i];
//					} else {
//						d1++;
//						ans4 += arr4[1][i];
//					}
//				}
//			}
//		}
//	}
//	d1 = 0;
//	d2 = 0;
//	d3 = 0;
//	if (t > 4) {
//		cin >> n5;
//		int arr5[3][n5];//每个成员对每个部门的满意程度数组arr5
//
//		for (int i = 0; i < n5; i++) {
//			for (int j = 0; j < 3; j++) {
//				cin >> arr5[j][i];
//				arr5[0][i] = arr5[1][i] + arr5[2][i] + arr5[3][i];
//			}
//		}
//		//个人总兴趣量排序
//		for (int i = 0; i < n5; i++) {
//			for (int j = 0; j < n5 - 1; j++) {
//				if (arr5[0][j] > arr5[0][j + 1]) {
//					swap(arr5[0][j], arr5[0][j + 1]);
//					swap(arr5[1][j], arr5[1][j + 1]);
//					swap(arr5[2][j], arr5[2][j + 1]);
//					swap(arr5[3][j], arr5[3][j + 1]);
//				}
//			}
//		}
//		for (int i = 0; i < n5; i++) {
//			if (arr5[1][i] >= arr5[2][i] && arr5[2][i] >= arr5[3][i]) { //a1>a2>a3
//				if (d1 < n5 / 2) {
//					d1++;
//					ans5 += arr5[1][i];
//				} else {
//					if (d2 < n5 / 2) {
//						d2++;
//						ans5 += arr5[2][i];
//					} else {
//						d3++;
//						ans5 += arr5[3][i];
//					}
//				}
//			}
//			if (arr5[1][i] >= arr5[3][i] && arr5[3][i] >= arr5[2][i]) { //a1>a3>a2
//				if (d1 < n5 / 2) {
//					d1++;
//					ans5 += arr5[1][i];
//				} else {
//					if (d3 < n5 / 2) {
//						d3++;
//						ans5 += arr5[3][i];
//					} else {
//						d2++;
//						ans5 += arr5[2][i];
//					}
//				}
//			}
//
//			if (arr5[2][i] >= arr5[1][i] && arr5[1][i] >= arr5[3][i]) { //a2>a1>a3
//				if (d2 < n5 / 2) {
//					d2++;
//					ans5 += arr5[2][i];
//				} else {
//					if (d1 < n5 / 2) {
//						d1++;
//						ans5 += arr5[1][i];
//					} else {
//						d3++;
//						ans5 += arr5[3][i];
//					}
//				}
//			}
//			if (arr5[2][i] >= arr5[3][i] && arr5[3][i] >= arr5[1][i]) { //a2>a3>a1
//				if (d2 < n5 / 2) {
//					d2++;
//					ans5 += arr5[2][i];
//				} else {
//					if (d3 < n5 / 2) {
//						d3++;
//						ans5 += arr5[3][i];
//					} else {
//						d1++;
//						ans5 += arr5[1][i];
//					}
//				}
//			}
//
//			if (arr5[3][i] >= arr5[1][i] && arr5[1][i] >= arr5[2][i]) { //a3>a1>a2
//				if (d3 < n5 / 2) {
//					d3++;
//					ans5 += arr5[3][i];
//				} else {
//					if (d1 < n5 / 2) {
//						d1++;
//						ans5 += arr5[1][i];
//					} else {
//						d2++;
//						ans5 += arr5[2][i];
//					}
//				}
//			}
//
//			if (arr5[3][i] >= arr5[2][i] && arr5[2][i] >= arr5[1][i]) { //a3>a2>a1
//				if (d3 < n5 / 2) {
//					d3++;
//					ans5 += arr5[3][i];
//				} else {
//					if (d2 < n5 / 2) {
//						d2++;
//						ans5 += arr5[2][i];
//					} else {
//						d1++;
//						ans5 += arr5[1][i];
//					}
//				}
//			}
//		}
//	}
//	cout << ans1;
//	if (t > 1) {
//		cout << "\n" << ans2;
//	}
//	if (t > 2) {
//		cout << "\n" << ans3;
//	}
//	if (t > 3) {
//		cout << "\n" << ans4;
//	}
//	if (t > 4) {
//		cout << "\n" << ans5;
//	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct node {
	int cnt;
	int a1;
	int a2;
	int a3;
};

vector<node>c1;
vector<node>c2;
vector<node>c3;


bool cmp1(node a, node b) {
	return a.a1 > b.a1;
}

bool cmp2(node a, node b) {
	return a.a2 > b.a2;
}

bool cmp3(node a, node b) {
	return a.a3 > b.a3;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	node z;
	c1.push_back(z);
	c2.push_back(z);
	c3.push_back(z);

	int t;


	scanf("%d", &t);
	while (t) {
		int n;
		scanf("%d", &n);
		int book[n + 1];
		node per[n + 1];
		long long sum[7] = {0};

		for (int i = 1; i <= n; i++) {
			per[i].cnt = i;
			scanf("%d %d %d", &per[i].a1, &per[i].a2, &per[i].a3);
			c1.push_back(per[i]);
			c2.push_back(per[i]);
			c3.push_back(per[i]);
		}
		sort(c1.begin() + 1, c1.end(), cmp1);
		sort(c2.begin() + 1, c2.end(), cmp2);
		sort(c3.begin() + 1, c3.end(), cmp3);
		//1
		for (int i = 1; i <= n; i++) {
			book[i] = 0;
		}
		for (int i = 1, c = 0; c < n / 2 && i <= n; i++) {
			if (book[c1[i].cnt] == 0) {
				//	cout << "1 ";
				sum[1] += c1[i].a1;
				book[c1[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0; c < n / 2 && i <= n; i++) {
			if (book[c2[i].cnt] == 0) {
				//	cout << "2 ";
				sum[1] += c2[i].a2;
				book[c2[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c3[i].cnt] == 0) {
				//	cout << "3 ";
				sum[1] += c3[i].a3;
				book[c3[i].cnt] = 1;
				c++;
			}
		}

		for (int i = 1; i <= n; i++) {
			book[i] = 0;
		}
		for (int i = 1, c = 0; c < n / 2 && i <= n; i++) {
			if (book[c1[i].cnt] == 0) {
				//	cout << "1 ";
				sum[2] += c1[i].a1;
				book[c1[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c3[i].cnt] == 0) {
				//	cout << "3 ";
				sum[2] += c3[i].a3;
				book[c3[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0; c < n / 2 && i <= n; i++) {
			if (book[c2[i].cnt] == 0) {
				//	cout << "2 ";
				sum[2] += c2[i].a2;
				book[c2[i].cnt] = 1;
				c++;
			}
		}

		//2
		for (int i = 1; i <= n; i++) {
			book[i] = 0;
		}

		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c2[i].cnt] == 0) {
				//cout << "2 ";
				sum[3] += c2[i].a2;
				book[c2[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c1[i].cnt] == 0) {
				//cout << "1 ";

				sum[3] += c1[i].a1;
				book[c1[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {

			if (book[c3[i].cnt] == 0) {
				//cout << "3 ";

				sum[3] += c3[i].a3;
				book[c3[i].cnt] = 1;
				c++;
			}
		}


		for (int i = 1; i <= n; i++) {
			book[i] = 0;
		}

		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c2[i].cnt] == 0) {
				//cout << "2 ";
				sum[4] += c2[i].a2;
				book[c2[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {

			if (book[c3[i].cnt] == 0) {
				//cout << "3 ";

				sum[4] += c3[i].a3;
				book[c3[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c1[i].cnt] == 0) {
				//cout << "1 ";

				sum[4] += c1[i].a1;
				book[c1[i].cnt] = 1;
				c++;
			}
		}

		//3
		for (int i = 1;  i <= n ; i++) {
			book[i] = 0;
		}
		for (int i = 1,  c = 0; c < n / 2 && i <= n; i++) {
			if (book[c3[i].cnt] == 0) {
				//cout << "3 ";
				sum[5] += c3[i].a3;
				book[c3[i].cnt] = 1;
				c++;
			}
		}

		for (int i = 1,  c = 0; c < n / 2 && i <= n; i++) {

			if (book[c1[i].cnt] == 0) {
				//cout << "1 ";

				sum[5] += c1[i].a1;
				book[c1[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1, c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c2[i].cnt] == 0) {
				//cout << "2 ";

				sum[5] += c2[i].a2;
				book[c2[i].cnt] = 1;
				c++;
			}
		}


		for (int i = 1;  i <= n ; i++) {
			book[i] = 0;
		}
		for (int i = 1,  c = 0; c < n / 2 && i <= n; i++) {
			if (book[c3[i].cnt] == 0) {
				//cout << "3 ";
				sum[6] += c3[i].a3;
				book[c3[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1, c = 0;  c < n / 2 && i <= n; i++) {
			if (book[c2[i].cnt] == 0) {
				//cout << "2 ";

				sum[6] += c2[i].a2;
				book[c2[i].cnt] = 1;
				c++;
			}
		}
		for (int i = 1,  c = 0; c < n / 2 && i <= n; i++) {

			if (book[c1[i].cnt] == 0) {
				//cout << "1 ";

				sum[6] += c1[i].a1;
				book[c1[i].cnt] = 1;
				c++;
			}
		}


		sort(sum, sum + 7);
		printf("%d\n", sum[6]);

		t--;
	}
	return 0;
}
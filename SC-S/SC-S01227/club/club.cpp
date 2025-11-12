#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct f{
	pair<int, int> b1, b2, b3;
};
bool cmp(f a, f b);
bool comp(pair<int, int> &a, pair<int, int> &b);
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int z = 1; z <= t; ++z) {
		int n;
		cin >> n;
		if (n == 2) {
			int x1, x2, x3, x4, x5, x6;
			cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
			int p = x1 + x5;
			p  = max(p, x1 + x6);
			p  = max(p, x2 + x4);
			p  = max(p, x2 + x6);
			p  = max(p, x3 + x4);
			p  = max(p, x3 + x5);
			if (z == t)	{
				cout << p;
			} else {
				cout << p << endl;
			}
		} else{
			vector<f> student(n + 1);
			for (int i = 1; i <= n; ++i) {
				student[i].b1.first = 1, student[i].b2.first = 2, student[i].b3.first = 3;
				cin >> student[i].b1.second >> student[i].b2.second >> student[i].b3.second;
				if (student[i].b1.second < student[i].b2.second) {
					swap(student[i].b1, student[i].b2);
				}
				if (student[i].b1.second < student[i].b3.second) {
					swap(student[i].b1, student[i].b3);
				}
				if (student[i].b2.second < student[i].b3.second) {
					swap(student[i].b2, student[i].b3);
				}
			}
			sort(student.begin() + 1,student.end(), cmp);
			int res = 0;
			vector<int> ans(4, 0);
			int n2 = n / 2;
			for (int i = 1; i <= n; ++i) {
				res = res + student[i].b1.second;
				ans[student[i].b1.first]++;
			}
			vector<pair<int, int>> d(n + 1);
			for (int i = 1; i <= n; ++i) {
				d[i].first = student[i].b1.first;
				d[i].second = student[i].b1.second - student[i].b2.second;
			}
			sort(d.begin() + 1, d.end(), comp);
			for (int i = 1; i <= 3; ++i) {
				if (ans[i] > n2) {
					int h = 0;
					for (int j = 1; j <= n; ++j) {
						if (d[i].first == i) {
							h++;
							res = res - d[i].second;
						}
						if (h == (ans[i] - n2)) break;
					}		
				}
			}
			if (z == t)	{
				cout << res;
			} else {
				cout << res << endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
bool cmp(f a, f b) {
	if (a.b1.second == b.b1.second) {
		if (a.b2.second == b.b2.second) {
			if (a.b3.second == b.b3.second) {
				return a.b3 > b.b3;
			} else {
				return a.b3 > b.b3; 
			}
		} else {
			return a.b2 > b.b2;
		}
	} else {
		return a.b1 > b.b1;
	}
}

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return a.second < b.second;
}
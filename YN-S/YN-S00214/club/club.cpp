#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct newstudent {
	int a1, a2, a3;
};

newstudent make_st(int a1a, int a2a, int a3a) {
	newstudent ns1;
	ns1.a1 = a1a;
	ns1.a2 = a2a;
	ns1.a3 = a3a;
	return ns1;
}
vector<newstudent> v;
int n, a, b, c;
vector<int> m, p;
int cnta, cntb, cntc;
int sum = 0;

void dfs(int i) {
	sum = 0;
	if (cnta > n / 2 || cntb > n / 2 || cntc > n / 2) {
		return;
	}
	if (i == n ) {

		for (int i1 = 0; i1 < m.size(); i1++) {
			sum = sum + m[i1];
			//cout << m[i1] << " ";
		}
		//cout << endl << sum << endl;
		p.push_back(sum);
		return;
	}
	m.push_back(v[i].a1);
	cnta++;
	dfs(i + 1);
	m.pop_back();
	cnta--;
	m.push_back(v[i].a2);
	cntb++;
	dfs(i + 1);
	m.pop_back();
	cntb--;
	m.push_back(v[i].a3);
	cntc++;
	dfs(i + 1);
	m.pop_back();
	cntc--;
	return;
}

void main1() {
	cnta = 0, cntb = 0, cntc = 0;
	for (; !m.empty();) {
		m.pop_back();
	}
	for (; !p.empty();) {
		p.pop_back();
	}
	for (; !v.empty();) {
		v.pop_back();
	}
	vector<int> aaa;
	vector<int> bbb;
	vector<int> ccc;
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v.push_back(make_st(a, b, c));
	}
	if (n < 20) {
		dfs(0);
		int maxa = -1;
		for (int i = 0; i < p.size(); i++) {
			maxa = max(maxa, p[i]);
		}
		cout << maxa << endl;
	} else {
		for (int i = 0; i < n; i++) {
			a = v[i].a1;
			b = v[i].a2;
			c = v[i].a3;
			if (a > b && a > c) {
				aaa.push_back(i);
			} else if (b > a && b > c) {
				bbb.push_back(i);
			} else if (c > a && c > b) {
				ccc.push_back(i);
			} else if (a == b && c < b) {
				if (bbb.size() < aaa.size()) {
					bbb.push_back(i);
				} else {
					aaa.push_back(i);
				}
			} else if (a == c && c > b) {
				if (ccc.size() < aaa.size()) {
					ccc.push_back(i);
				} else {
					aaa.push_back(i);
				}
			} else if (b == c && c > a) {
				if (ccc.size() < bbb.size()) {
					ccc.push_back(i);
				} else {
					bbb.push_back(i);
				}
			} else {
				aaa.push_back(i);
			}
		}
		sort(aaa.begin(), aaa.end(), greater<int>());
		sort(bbb.begin(), bbb.end(), greater<int>());
		sort(ccc.begin(), ccc.end(), greater<int>());
		if (aaa.size() > n / 2) {
			for (; aaa.size() > n / 2;) {
				if (v[aaa.back()].a2 > v[aaa.back()].a3) {
					bbb.push_back(aaa.back());
					aaa.pop_back();
				} else {
					ccc.push_back(aaa.back());
					aaa.pop_back();
				}
			}
		}
		if (bbb.size() > n / 2) {
			for (; bbb.size() > n / 2;) {
				if (v[bbb.back()].a1 > v[bbb.back()].a3) {
					aaa.push_back(bbb.back());
					bbb.pop_back();
				} else {
					ccc.push_back(bbb.back());
					bbb.pop_back();
				}
			}
		}
		if (ccc.size() > n / 2) {
			for (; ccc.size() > n / 2;) {
				if (v[ccc.back()].a2 > v[ccc.back()].a1) {
					bbb.push_back(ccc.back());
					ccc.pop_back();
				} else {
					aaa.push_back(ccc.back());
					ccc.pop_back();
				}
			}

		}
		int sum = 0;
		for (int i = 0; i < aaa.size(); i++) {
			sum += v[aaa[i]].a1;
		}
		for (int i = 0; i < bbb.size(); i++) {
			sum += v[bbb[i]].a2;
		}
		for (int i = 0; i < ccc.size(); i++) {
			sum += v[ccc[i]].a3;
		}
		cout << sum << endl;
	}

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		main1();
	}
}
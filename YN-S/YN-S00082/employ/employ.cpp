#include <bits/stdc++.h>
using namespace std;
bool s1[10086], s2[100086];
string s;
int p1[10086], p2[10086];
long long ans = 0;
int n, m;

//cnt代表天数
//循环寻找人
//h代表放弃的人;
//d代表没通过的人+h
int zhao(long long cnt, int s, int h) {
	//int d = h + s2[cnt];
	//cout << cnt << " " << h << " " << d << " " << s << endl;
	if (s == m) {
		//cout << endl;
		ans++;
		return 0;
	}
	if (cnt > n) {
		return 0;
	}

	for (int i = 0; i < n; i++) {//寻找当前位置的人
		//cout << 1;
		//cout << i;
		if (p2[i] == -1) {//如果已经在前面了
			continue;
		}
		p2[i] = -1;//锁住当前的人)
		if (h >= p1[i]) {//放弃的
			zhao(cnt + 1, s, h + 1);
			//cout << cnt << "放" << endl;
		} else if (h < p1[i] && s1[cnt] == 1) { //通过的
			zhao(cnt + 1, s + 1, h);
			//cout << cnt << "通" << endl;
		} else if (h < p1[i] && s1[cnt] == 0) {//没通过的
			zhao(cnt + 1, s, h + 1);
			//cout << cnt << "败" << endl;
		}
		p2[i] = p1[i];
	}
	return 0;
}



int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < n; i++) {
		//cin >> s1[i];
		s1[i] = s[i] - '0';
		if (s1[i] == 0) {
			s2[i] = s2[i - 1] + 1;

		} else {
			s2[i] = s2[i - 1];
		}
		//cout << s2[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> p1[i];
		//cout << p1[i];
		p2[i] = p1[i];
	}
	zhao(0, 0, 0);
	cout <<   ans % 998244353;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
struct eyz {
	string s0, s1;
};
int n, q, ans;
eyz t[MAXN], a;
queue<eyz>que;

string f(string str, long front, long back) {
	string tmp = "";
	for (long long i = front; i <= back; i++) {
		tmp += str[i];
	}
	return tmp;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> t[i].s0 >> t[i].s1;
	for (int i = 1; i <= q; i++) {
		eyz tmp;
		cin >> tmp.s0 >> tmp.s1;
		que.push(tmp);
	}
end:
	ans = 0;
	a = que.front();
	que.pop();
	for (int k = 1; k <= n; k++) {
		for (long long i = 0; i + t[k].s0.size() <= a.s0.size() ; i++) {
			string tmp1 = "";
			tmp1 = f(a.s0, i, i + t[k].s0.size() - 1);
			if (tmp1 != t[k].s0) continue;
			string tmp2 = "";
			tmp2 = f(a.s0, 0, i - 1) + t[k].s1 + f(a.s0, i + t[k].s1.size(), a.s0.size()-1);
			//cout << "-将" << a.s0 << "替换为" << tmp2 << endl;
			if (tmp2 == a.s1) {
				ans++;
				//cout << "可以" << endl;
			}// else cout << "不可以-原来是" << a.s1 << endl;
		}
	}
	cout << ans << endl;
	if (!que.empty()) goto end;
	return 0;
}
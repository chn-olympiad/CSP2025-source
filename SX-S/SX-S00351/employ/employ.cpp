#include <bits/stdc++.h>
using namespace std;
int nx[100009], n, m;
int nxx[100009];//此位置需要的耐心值
priority_queue<int>q;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w".stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> nx[i];
		q.push(nx[i]);
	}
	int p = 0; //需求耐心值
	int l = s.size(); //记录s的长度
	vector<long long>ppq;//记录某位置能被几位用来面试
	for (int i = 0; i < l; i++) {
		if (s[i] == '1') {
			nxx[i] = p;
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				if (nx[i] > p) {
					sum++;
				}
			}
			ppq.push_back(sum);
		}
		if (s[i] == '0') {
			p++;
			nxx[i] = 1e9; //此位置不可能被面试成功
		}
	}
	long long cnt = 1;
	long long ans = 0;
	int flagans = 0;
	for (auto tmp : ppq) { //遍历所有能够面试成功的位置
		if (tmp != 0) {
			flagans = 1;
			cnt *= tmp;
		}

	}
	if (!flagans)
		cout << 0;
	else {
		cout << cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define endl '\n';
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
const int N = 5e5+10;
int nums[N];
int h[N][22];
int n, k;
int mb[22];
int cnt = 0;
vector<PII> thisjh;
vector<vector<PII>> jhqj;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	if (k == 0) {
		int cnt0 = 0;
		bool pei = 0;
		for (int i = 1; i <= n; i++) {
			cin >> nums[i];
			if (nums[i] == 0)
				cnt0++, pei = 0;
			else {
				if (nums[i] == nums[i - 1] && pei == 0) {
					cnt++;
					pei = 1;
				} else
					pei = 0;
			}
		}
		cnt += cnt0;
		cout << cnt << endl;
		return 0;
	} else if (k == 1) {
		//int cnt1==0;
		for (int i = 1; i <= n; i++) {
			cin >> nums[i];
			if (nums[i] == 1)
				cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	jhqj.push_back(thisjh);
	int kk = k, jjj = 1;
	while (kk) {
		mb[jjj] = (kk & 1);
		kk >>= 1;
		jjj++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		int j = 1;
		int u = nums[i];
		while (u) {
			h[i][j] = h[i - 1][j] + (u & 1);
			u >>= 1;
			j++;
		}
		for (int o = 1; o <= i; o++) {
			bool kt = true;
			for (int w = 1; w <= 21; w++) {
				if ((h[i][w] - h[o - 1][w]) % 2 != mb[w]) {
					kt = false;
					break;
				}
			}
			if (kt)
				thisjh.push_back({o, i});
		}
	}
	sort(thisjh.begin(), thisjh.end());
	if ((int)thisjh.size() > 0) {
		jhqj[0].push_back(thisjh[0]);
		jhqj[0].push_back(thisjh[0]);
		//cout << thisjh[0].fi << " " << thisjh[0].se << endl;
	}
	for (int i = 1; i < (int)thisjh.size(); i++) {
		bool kt = true;
		//cout << thisjh[i].fi << " " << thisjh[i].se << endl;
		for (int j = 0; j < (int)jhqj.size(); j++) {
			if (thisjh[i].se >= jhqj[j][0].fi && thisjh[i].fi <= jhqj[j][0].se) {
				jhqj[j][0].fi = min(jhqj[j][0].fi, thisjh[i].fi);
				jhqj[j][0].se = max(jhqj[j][0].se, thisjh[i].se);
				jhqj[j].push_back(thisjh[i]);
				kt = false;
				break;
			}
		}
		if (kt) {
			vector<PII> op;
			op.push_back(thisjh[i]);
			op.push_back(thisjh[i]);
			jhqj.push_back(op);
		}
	}
	cnt = (int)jhqj.size();
	cout << cnt;
	return 0;
}
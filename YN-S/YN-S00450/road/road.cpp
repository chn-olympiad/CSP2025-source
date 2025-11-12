#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e6 + 10;
const ll N = 1e4 + 5;
ll chengzhen[10 + 1][N];
ll f[N];

ll ffind(ll x) {
	if (f[x] != x) {
		return f[x] = ffind(f[x]);
	}
	return x;
}
ll n, m, k, cnt;
bool jiaru[10 + 5];

struct node {
	ll u, v, w;
};
node arr[M];

bool cmp(node a, node b) {
	return a.w < b.w;
}
ll jiaruhao = -1, ans;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &arr[i].u, &arr[i].v, &arr[i].w);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			scanf("%lld", &chengzhen[i][j]);
		}
	}
	sort(arr + 1, arr + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		bool flag = false;//是否使用小镇
		ll dis2 = 1e18 + 10;
		if (ffind(arr[i].u) == ffind(arr[i].v))
			continue;
		//cout << arr[i].u << " find：" << ffind(arr[i].u) << arr[i].v << " find: " << ffind(arr[i].v) << endl;
		jiaruhao = -1;
		for (int j = 1; j <= k; j++) {
			if (!jiaru[j]) {
				if (dis2 > chengzhen[j][ffind(arr[i].u)] + chengzhen[j][ffind(arr[i].v)] + chengzhen[j][0]) {
					dis2 = chengzhen[j][ffind(arr[i].u)] + chengzhen[j][ffind(arr[i].v)] + chengzhen[j][0];
					jiaruhao = j;
				}
			} else {
				if (dis2 > chengzhen[j][ffind(arr[i].u)] + chengzhen[j][ffind(arr[i].v)]) {
					dis2 = chengzhen[j][ffind(arr[i].u)] + chengzhen[j][ffind(arr[i].v)];
					jiaruhao = j;
				}
			}
		}
		//cout << "node 1: " << arr[i].u << " node2: " << arr[i].v << " dis2: " << dis2 << " yuan: " << arr[i].w << endl;
		if (dis2 <= arr[i].w) { //如果加上城镇距离会变小或者不变就加入
			flag = true;
			chengzhen[jiaruhao][ffind(arr[i].v)] = 0;
			jiaru[jiaruhao] = true;
			ans += dis2;
		} else {
			ans += arr[i].w;
		}
		cnt++;
		for (int j = 1; j <= k; j++) {
			//cout << "第" << j << "个小镇合并" << ffind(arr[i].u) << " 到 " << ffind(arr[i].v) << " 取" << chengzhen[j][ffind(
			//arr[i].v)] << "和 " << chengzhen[j][ffind(arr[i].u)] << "最小值" << endl;
			chengzhen[j][ffind(arr[i].v)] = min(chengzhen[j][ffind(arr[i].v)], chengzhen[j][ffind(arr[i].u)]);
			//cout << "结果: " << chengzhen[j][ffind(arr[i].v)] << endl;
		}/*
		if (flag)
			chengzhen[jiaruhao][ffind(arr[i].v)] = 0;//因为道路已建设，无需再额外花费*/
		f[ffind(arr[i].u)] = ffind(arr[i].v);
		if (cnt == n - 1) {
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
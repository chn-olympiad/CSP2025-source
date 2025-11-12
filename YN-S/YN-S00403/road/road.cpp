#include <bits/stdc++.h>
using namespace std;

//pts20 or 100?;
struct node {
	long long fom, to, val, kj;

} edge[2000002];
int fa[2000002];
int tist;
int n, m, k;
bool kaze = 0;
map<int, int>mp;
long long ans = 0, el, ev, cnt = 0;
int cop_n;

bool cmp(node a, node b) {
	return a.val < b.val;
}

int find(int x) {
	if (x == fa[x]) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}

void kruskal() {
	sort(edge + 1, edge + m + n * k + 1, cmp);

	/*	for(int i=1;i<=m+n*k;i++){
			printf("%d %d %d\n",edge[i].fom,edge[i].to,edge[i].val);
		}*/
	for (int i = 1; i <= m + n * k; i++) {

		if (mp[edge[i].fom] == 1) {
			kaze = 1;
		}

		if (mp[edge[i].to] == 1) {
			kaze = 1;
		}

		if (edge[i].fom > n && mp[edge[i].fom] != 1) {
			mp[edge[i].fom] = 1;
			cop_n++;
			//	kaze=1;
		}

		if (edge[i].to > n && mp[edge[i].to] != 1) {
			mp[edge[i].to] = 1;
			cop_n++;
			//kaze=1;
		}

		el = find(edge[i].fom);
		ev = find(edge[i].to);

		//	printf("El:%d EV:%d ",el,ev);
		if (el == ev) {
			kaze = 0;
			continue;
		}

		fa[ev] = el;
		ans += edge[i].val;

		//	cout<<"KAZE:"<<kaze<<" "<<cop_n<<endl;
		if (kaze) {
			ans -= edge[i].kj;
			kaze = 0;
		}

		if (++cnt == cop_n - 1) {
			return;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);

	cop_n = n;

	for (int i = 1; i <= n * k + m; i++) {

		fa[i] = i;
	}

//	return 0;
	//int kis;
	for (int i = 1; i <= m; i++) {

		scanf("%lld%lld%lld", &edge[i].fom, &edge[i].to, &edge[i].val);
	}

	for (int i = 1; i <= k; i++) {

		scanf("%d", &tist);

		for (int j = m + (i - 1) * n + 1; j <= m + n * i; j++) {

			scanf("%lld", &edge[j].val);
			edge[j].kj = tist;
			edge[j].val += tist;
			edge[j].fom = n + i;
			edge[j].to = j - m - (i - 1) * n;
			/*	if(edge[j].fom>edge[j].to){
					kis=edge[j].fom;
					edge[j].fom=edge[j].to;
					edge[j].to=kis;

				}*/
		}

	}

	kruskal();
	printf("%lld", ans);
	return 0;
}

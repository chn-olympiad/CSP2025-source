#include <bits/stdc++.h>
using namespace std;
int T, n;

struct st {
	int a, b, c;
} e[100005];
int xa[500001], xb[500001], xc[500001];

bool cmp(st x, st y) {
	return x.a > y.a;
}
long long maxx = -1;

void dfs(int x, int na, int nb, int nc, long long sum) {
	if (x > n) {
		//	cout << 1;
		maxx = max(maxx, sum);
		return;
	}
	if (na < n / 2) {
		//	cout << 1;
		dfs(x + 1, na + 1, nb, nc, sum + e[x].a);
	}
	if (nb < n / 2) {
		//	cout << 2;
		dfs(x + 1, na, nb + 1, nc, sum + e[x].b);
	}
	if (nc < n / 2) {
//		cout << 3;
		dfs(x + 1, na, nb, nc + 1, sum + e[x].c);
	}
	return;
}

/*
1
2
10 9 8
4 0 0
10*/
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		bool A = 0, B = 0;
		for (int i = 1; i <= n; i++) {
			cin >> e[i].a >> e[i].b >> e[i].c;
			if (e[i].b != e[i].c) {
				A = 1;
			}
			if (e[i].c != 0) {
				B = 1;
			}
		}
		if (!A) {
			//	cout << 1;
			sort(e + 1, e + n + 1, cmp);
			int cnt = 1;
			long long sum = 0;
			while (cnt <= (n / 2)) {
				sum += e[cnt].a;
				cnt++;
				//cout << e[cnt].a << endl;
			}
			cout << sum << endl;
			//}else if(!B){
//			for(int i = 1;i<=n;i++){
//
//			}
		} else {
			dfs(1, 0, 0, 0, 0);
			cout << maxx << endl;
			maxx = -1;
		}

		/*
		1 6
		1 0 0
		2 0 0
		3 0 0
		4 0 0
		5 0 0
		6 0 0*/
		/*
		int cnta = 0,cntb = 0,cntc = 0;

		long long xa = 0,xb = 0,xc = 0;
		long long ya = 0,yb = 0,yc = 0;
		int n2 = n/2;
		for(int i = 1;i<=n;i++){
			if(e[i].a>e[i].b and e[i].a>e[i].c){
				if(ya<=n2){
					xa+=e[i].a;
				}else if(yb<=n2){
					xb+=e[i].b;
				}else{
					xc+=e[i].c;
				}
			}else if(e[i].b>e[i].c and e[i].)
		}
		long long sum = 0;
		for(int i = 1;i<=n;i++){
			if(e[i].a>e[i].b and e[i].a>e[i].c){
				if(cnta<n2){
					xa[++cnta] = i;
				}else{
					int nnow = max(e[i].b,e[i].c);
					int cg = 0,boolcg = 0;
					for(int j = 1;j<=cnta;j++){
						//判断转移后哪个大
						if(sum-e[xa[j]].a+e[xa[j]].b>sum-e[xa[j]].a+e[xa[j]].c){
							cg = 2;
						}else{
							cg = 3;
						}
						if(cg==2){
							if(sum-e[xa[j]].a+e[xa[j]].b+noww>sum){
								boolcg = j;
								nnnow = sum-e[xa[j]].a+e[xa[j]].b+noww;
							}
						}else{
							if(sum-e[xa[j]].a+e[xa[j]].c+noww>sum){
								boolcg = j;
								nnnow = sum-e[xa[j]].a+e[xa[j]].c+noww;
							}
						}
					}
					if(!boolcg){
						if(nnow = e[i].b){
							xb[++cntb] = i;
							sum+=e[i].b;
						}
					}else{
						sum = sum-e[xa[boolcj]].a+max(e[xa[boolcj]].b,xa[boolcj]].c)+e[i].a;
						if()
					}
				}
			}else if(e[i].b>e[i].c and e[i].b>e[i].a){
				if(cntb<n2){
					xb[++cnt] = i;
					sum+=e[i].b;
				}
			}
		}*/
	}
	return 0;
}

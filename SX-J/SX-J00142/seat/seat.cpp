#include<bits/stdc++.h>

using namespace std;

int n, m;

struct _{ int id, v; } a[1010];

bool cmp(const _ &a, const _ &b){
	return a.v > b.v;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++) scanf("%d", &a[(i - 1) * m + j].v), a[(i - 1) * m + j].id = ((i - 1) * m + j == 1 ? 1 : 0);
	}
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 0;
	for(int i = 1; i <= m; i ++){
		if(i & 1){
			for(int j = 1; j <= n; j ++){
				if(a[++ cnt].id == 1) {
					printf("%d %d\n", i, j);
				}
			}
		} else {
			for(int j = n; j; j --){
				if(a[++ cnt].id == 1) {
					printf("%d %d\n", i, j);
				}
			}
		}
	}
	return 0;
}
/*
-------------------------hty111-------------------------
T2: 纯模拟
时间复杂度: $\mathcal O(nm)$
Expect: 100pts
对拍：10000组 with O(nm)[数学]
-------------------------hty111-------------------------
*/
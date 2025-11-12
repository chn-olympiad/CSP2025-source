//SN-J01212 Æë¾ýºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 110;

int n, m, a[N], cj;
pair<int, int> id[N];

bool cmp(const int &A, const int &B) {
	return A > B;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	cj = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int j = 1; j <= m; j++) {
		if(j & 1) {
			for(int i = 1; i <= n; i++)
				id[a[n * (j - 1) + i]] = {i, j};
		} else {
			for(int i = 1; i <= n; i++)
				id[a[n * (j - 1) + i]] = {n - i + 1, j};
		}
	}
	printf("%d %d\n", id[cj].second, id[cj].first);
	return 0;
}


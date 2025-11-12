#include <cstdio>
#include <algorithm>
#include <cstring>
#define DEBUG 1
using namespace std;

const int N = 1e5+5;

int t;
int n;
int a[N][5];
int mx_limt;
int ans;
int cnt[5];
int sa_limt[N];

void pre_set();

void init() {
	ans = 0;
	memset(a, 0, sizeof a);
	memset(cnt, 0, sizeof cnt);
	memset(sa_limt, 0, sizeof sa_limt);
}

void pre_set()
{
	for(int i = n; i >= 1; i--) {
		int mx = max(a[i][1], max(a[i][2], a[i][3]));
		sa_limt[i] =  sa_limt[i+1]+mx;
	}
}

void solve();
void dfs(int i, int j, int k);

int main(){
	freopen("club.in", "r", stdin);
#if DEBUG
	freopen("club.out", "w", stdout);
#endif
	
	scanf("%d", &t);
	while(t--){
		init();
		solve();
	}
	fclose(stdin);
#if DEBUG
	fclose(stdout);
#endif
	return 0;
}

void solve()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for (int j = 1; j<=3; j++)
			scanf("%d", &a[i][j]);
	pre_set();
	mx_limt = n / 2;
	for (int i = 1; i <= 3; i++) {
		dfs(1, i, 0);
	}
	printf("%d\n", ans);
}

void debug(int club, int v)
{
	for (int i = 1; i<=3; i++)
	 printf("debug:%d \n", cnt[i]);
}

void dfs(int cur, int club, int v) {
	if (cnt[club]>=mx_limt)
		return;
	if (v+sa_limt[cur] <= ans)
		{return;}
	if (cur == n){
//		if (ans < v+a[n][club])
//		debug(club, v);
		ans = max(ans, v+a[n][club]);
	}
	cnt[club]++;
	for (int i = 1; i <= 3; i++) {
		dfs(cur+1, i, v+a[cur][club]);
	}
	cnt[club]--;
}

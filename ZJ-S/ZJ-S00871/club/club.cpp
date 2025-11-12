#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct P{
	int v[4], id;
}a[N];
int n, ans, s[4];
bool b[N];
bool cmp(const P A, const P B){
	return A.v[1] > B.v[1];
}
bool cmp1(const P A, const P B){
	return abs(A.v[1] - A.v[2]) > abs(B.v[1] - B.v[2]);
}
inline void dfs(int i, int sum){
	if(i == n + 1){
		ans = max(ans, sum);
		return;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 3; j++)
			if(s[j] < n / 2 && !b[i]){
				b[i] = true;
				s[j]++;
				dfs(i + 1, sum + a[i].v[j]);
				b[i] = false;
				s[j]--;
			}
}
void solve(){
	scanf("%d", &n);
	bool ok = true, ok1 = true;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &a[i].v[1], &a[i].v[2], &a[i].v[3]);
		if(a[i].v[3] != 0) ok = false;
		if(a[i].v[2] != 0) ok1 = false;
	}
	if(ok && ok1){
		sort(a + 1, a + n + 1, cmp);
		int sum = 0;
		for(int i = 1; i <= n / 2; i++)
			sum += a[i].v[1];
		printf("%d\n", sum);
		return;
	}
	if(ok){
		int l1 = 0, l2 = 0;
		sort(a + 1, a + n + 1, cmp1);
		//for(int i = 1; i <= n; i++)
		//	printf("%d %d\n", a[i].v[1], a[i].v[2]);
		for(int i = 1; i <= n / 2; i++){
			if(a[i].v[1] > a[i].v[2]){
				ans += a[i].v[1];
				l1++;
			}
			else{
				ans += a[i].v[2];
				l2++;
			}
			//printf("%d %d %d\n", l1, l2, ans);
		}
		for(int i = n / 2 + 1; i <= n; i++){
			if(l1 == n / 2){
				ans += a[i].v[2];
				l2++;
			}
			else if(l2 == n / 2){
				ans += a[i].v[1];
				l1++;
			}
			else{
				if(a[i].v[1] > a[i].v[2]){
					ans += a[i].v[1];
					l1++;
				}
				else{
					ans += a[i].v[2];
					l2++;
				}
			}
			//printf("%d %d %d\n", l1, l2, ans);
		}
		printf("%d\n", ans);
		return;
	}
	dfs(1, 0);
	printf("%d\n", ans);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
		solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//我很生气。打了3个小时只有40points。 

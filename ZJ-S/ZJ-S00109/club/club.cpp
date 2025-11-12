#include <bits/stdc++.h>
using namespace std;
int t, n, cnt[5], ans = 0;
struct node{
	int x, y, z;
}a[100005];
int b[100005], c[100005];
void dfs(int x, int sum){
	if (x == n+1){
		ans = max(ans, sum);
		return ;
	}
	if (cnt[1] < n/2){
		cnt[1] ++;
		dfs(x+1, sum+a[x].x);
		cnt[1] --;
	}
	if (cnt[2] < n/2){
		cnt[2] ++;
		dfs(x+1, sum+a[x].y);
		cnt[2] --;
	}
	if (cnt[3] < n/2){
		cnt[3] ++;
		dfs(x+1, sum+a[x].z);
		cnt[3] --;
	}
	return ;
}
bool cmp(node x, node y){
	return x.x > y.x;
}
int check(int x, int y){
	if (x > n/2)  return 1;
	if (y > n/2)  return 2;
	return 0;
}
bool cmp1(int x, int y){
	return a[x].x - a[x].y > a[y].x - a[y].y;
}
bool cmp2(int x, int y){
	return a[x].y - a[x].x > a[y].y - a[y].x;
}
void solve(int x){
	if (x == 0){
		for (int i=1; i <= cnt[1]; i++)  ans += a[b[i]].x;
		for (int i=1; i <= cnt[2]; i++)  ans += a[c[i]].y;
		return ;
	}
	if (x == 1){
		sort(b+1, b+cnt[1]+1, cmp1);
		while (cnt[1] > n/2){
			c[++cnt[2]] = b[cnt[1]];
			cnt[1] --;
		}
		solve(0);
	}
	else if (x == 2){
		sort(c+1, c+cnt[2]+1, cmp2);
		while (cnt[2] > n/2){
			b[++cnt[1]] = c[cnt[2]];
			cnt[2] --;
		}
		solve(0);
	}
	return ;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--){
		ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		cin >> n;
		for (int i=1; i <= n; i++)  cin >> a[i].x >> a[i].y >> a[i].z;
		if (n <= 30){
			dfs(1, 0);
			cout << ans << "\n";
		}
		else {
			bool flag2 = 1, flag3 = 1;
			for (int i=1; i <= n; i++){
				if (a[i].y){
					flag2 = 0;
				}
				if (a[i].z){
					flag3 = 0;
					break;
				}
			}
			if (flag2 && flag3){
				sort(a+1, a+n+1, cmp);
				for (int i=1; i <= n/2; i++)  ans += a[i].x;
				cout << ans << "\n";
			}
			else if (flag3){
				for (int i=1; i <= n; i++){
					if (a[i].x >= a[i].y)  b[++cnt[1]] = i;
					else  c[++cnt[2]] = i;
				}
				solve(check(cnt[1], cnt[2]));
				cout << ans << "\n";
			}
		}
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
struct node{
	int val[5], d;
	int pos;
}a[N];
int n, vis[N];
ll dp[5];
bool cmp1(node x, node y){
	if(x.val[1] == y.val[1]){
		if(x.val[2] == y.val[2]) return x.val[3] < y.val[3];
		else return x.val[2] < y.val[2];
	}else return x.val[1] < y.val[1];
}
bool cmp2(node x, node y){
	if(x.val[1] == y.val[1]){
		if(x.val[2] == y.val[2]) return x.val[3] > y.val[3];
		else return x.val[2] > y.val[2];
	}else return x.val[1] > y.val[1];
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bool flag1 = true, flag2 = true, flag3 = true;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= 3;j ++){
				scanf("%d", &a[i].val[j]);
				if(j == 1 && a[i].val[j] != 0) flag1 = false;
				if(j == 2 && a[i].val[j] != 0) flag2 = false;
				if(j == 3 && a[i].val[j] != 0) flag3 = false;
			}
		}
		if(flag1 == false && flag2 == true && flag3 == true){
			sort(a+1, a+n+1, cmp2);
			ll ans = 0;
			for(int i = 1;i <= n/2;i ++){
				ans += a[i].val[1];
			}
			printf("%lld\n", ans);
			for(int i = 1;i <= n + 3;i ++){
				for(int j = 1;j <= 3;j ++){
					a[i].val[j] = 0;
				}
				a[i].d = 0;
				vis[i] = 0;
			}
			continue;
		}
		if(flag1 == true && flag2 == false && flag3 == true){
			sort(a+1, a+n+1, cmp2);
			ll ans = 0;
			for(int i = 1;i <= n/2;i ++){
				ans += a[i].val[2];
			}
			printf("%lld\n", ans);
			for(int i = 1;i <= n + 3;i ++){
				for(int j = 1;j <= 3;j ++){
					a[i].val[j] = 0;
				}
				a[i].d = 0;
				vis[i] = 0;
			}
			continue;
		}
		if(flag1 == true && flag2 == true && flag3 == false){
			sort(a+1, a+n+1, cmp2);
			ll ans = 0;
			for(int i = 1;i <= n/2;i ++){
				ans += a[i].val[2];
			}
			printf("%lld\n", ans);
			for(int i = 1;i <= n + 3;i ++){
				for(int j = 1;j <= 3;j ++){
					a[i].val[j] = 0;
				}
				a[i].d = 0;
				vis[i] = 0;
			}
			continue;
		}
		sort(a+1, a+n+1, cmp1);
		ll sum = 0;
		int k[5] = {0, 1, 1, 1};
		for(int j = 1;j <= 3;j ++){
			for(int i = 1;i <= n;i ++){
				sum = max(sum, dp[1] + dp[2] + dp[3]);
//				for(int k = 1;k <= n/2;k ++){
					if(vis[i] == 0 && dp[j] < dp[j] + a[i].val[j] && k[j] <= n/2){
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						k[j] ++;
						vis[i] = 1;
					}else if(vis[i] == 1 && dp[a[i].pos] < a[i].val[j] && k[j] <= n/2){
						dp[a[i].pos] -= a[i].val[a[i].pos];
						k[a[i].pos] --;
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						k[j] ++;
					}
//              }
			}
		}
		for(int i = 1;i <= n;i ++) vis[i] = 0;
		for(int i = 1;i <= 5;i ++){
			for(int j = 1;j <= n/2 + 3;j ++){
				dp[i] = 0;
			}
		}
		k[1] = k[2] = k[3] = 1;
		for(int j = 1;j <= 3;j ++){
			for(int i = 1;i <= n;i ++){
				sum = max(sum, dp[1] + dp[2] + dp[3]);
//				for(int k = 1;k <= n/2;k ++){
					if(vis[i] == 0 && dp[j] < dp[j] + a[i].val[j] && k[j] <= n/2){
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						k[j] ++;
						vis[i] = 1;
					}else if(vis[i] == 1 && dp[a[i].pos] < a[i].val[j] && k[j] <= n/2){
						dp[a[i].pos] -= a[i].val[a[i].pos];
						k[a[i].pos] --;
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						k[j] ++;
					}if(vis[i] == 0 && dp[j] < dp[j] + a[i].val[j] && k[j] <= n/2){
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						k[j] ++;
						vis[i] = 1;
					}else if(vis[i] == 1 && dp[a[i].pos] < a[i].val[j] && k[j] <= n/2){
						dp[a[i].pos] -= a[i].val[a[i].pos];
						k[a[i].pos] --;
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						k[j] ++;
					}else if(vis[i] == 0 && dp[j] < a[i].val[j] && k[j] >= n/2){
						int s;
						for(s = 1;s <= n;s ++){
							if(a[s].pos == j) break;
						}
						dp[j] -= a[s].val[j];
						vis[s] = 0;
						dp[j] = dp[j] + a[i].val[j];
						a[i].pos = j;
						vis[i] = 1;
					}
//              }
			}
		}
		printf("%lld\n", sum);
		for(int i = 1;i <= n + 3;i ++){
			for(int j = 1;j <= 3;j ++){
				a[i].val[j] = 0;
			}
			a[i].d = 0;
			vis[i] = 0;
		}
		for(int i = 1;i <= 5;i ++){
			for(int j = 1;j <= n/2 + 3;j ++){
				dp[i] = 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

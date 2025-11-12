#include <iostream>
#include <cstdio>
using namespace std;
int a[100005][3], order[100005][3], cnt[3], dis[3][20005];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--){
		for (int i = 0; i < 3; ++i){
			cnt[i] = 0;
			for (int j = 0; j < 20005; ++j){
				dis[i][j] = 0;
			}
		}
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i){
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
				cnt[0]++;
				order[i][0] = 0;
				if (a[i][1] >= a[i][2]){
					order[i][1] = 1;
					order[i][2] = 2;
					dis[0][a[i][0] - a[i][1]]++;
				}
				else{
					order[i][1] = 2;
					order[i][2] = 1;
					dis[0][a[i][0] - a[i][2]]++;
				}
			}
			else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
				cnt[1]++;
				order[i][0] = 1;
				if (a[i][0] >= a[i][2]){
					order[i][1] = 0;
					order[i][2] = 2;
					dis[1][a[i][1] - a[i][0]]++;
				}
				else{
					order[i][1] = 2;
					order[i][2] = 0;
					dis[1][a[i][1] - a[i][2]]++;
				}
			}
			else{
				cnt[2]++;
				order[i][0] = 2;
				if (a[i][1] >= a[i][0]){
					order[i][1] = 1;
					order[i][2] = 0;
					dis[2][a[i][2] - a[i][1]]++;
				}
				else{
					order[i][1] = 0;
					order[i][2] = 1;
					dis[2][a[i][2] - a[i][0]]++;
				}
			}
			ans += a[i][order[i][0]];
			//cout << order[i][0] <<  order[i][1] <<  order[i][2] << endl;
		}
		int k = 0;
		for (int i = 0; i < 3; ++i){
			if (cnt[i] > n / 2){
				k = i;
				break;
			}
		}
		//printf("%d\n", ans);
		int dhnum = cnt[k] - n / 2;
		for (int i = 0; i <= 20000; ++i){
			if (dhnum <= 0) break;
			if (dis[k][i] == 0) continue;
			int num = dis[k][i];
			if (dhnum < num) num = dhnum;
			dhnum -= num;
			ans -= num * i;
			
		}
		printf("%d\n", ans);
	}
	return 0;
}
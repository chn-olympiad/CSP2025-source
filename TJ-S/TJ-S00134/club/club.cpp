#include<bits/stdc++.h>
using namespace std;

int n, m, k, l;
pair<int, int> a[100011][5];

bool cmp(pair<int, int> x, pair<int, int> y){
	return x.first > y.first;
}

int check(int x, int y, int z){
	if(x > y){if(x > z){return 1;}return 3;}
	if(y > z){return 2;}
	return 3;
}

int main(){
	freopen("club.in",  "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		scanf("%d", &n);
		int num[5];
		memset(num, 0, sizeof(num));
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d", &a[i][1].first, &a[i][2].first, &a[i][3].first);
			a[i][1].second = 1, a[i][2].second = 2, a[i][3].second = 3;
			sort(a[i] + 1, a[i] + 4, cmp);
		}
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			ans += a[i][1].first;
			num[a[i][1].second]++;
		}
		int uu = check(num[1], num[2], num[3]);
		if(num[uu] <= n / 2){
			printf("%lld\n", ans);
			continue;
		}
		int sum[100001];
		if(n % 2 == 0){
			k = 0;
			for(int i = 1;i <= n;i++){
				if(a[i][1].second == uu){
					sum[++k] = min(a[i][1].first - a[i][2].first, a[i][1].first - a[i][3].first);
				}
			}
			sort(sum + 1, sum + k + 1);
			int x = num[uu] - n / 2;
			for(int i = 1;i <= x;i++){
				ans -= sum[i];
			}
			printf("%lld\n", ans);
		}
	}
}

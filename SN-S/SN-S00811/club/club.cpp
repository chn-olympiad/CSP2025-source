#include<bits/stdc++.h>
using namespace std;

const int N = 200001;
int T, n, a[4][N], b[4][N], cnt[4], ans, vis[4], sum[4];

int main(){
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1;i <= 3;i++){
			for(int j = 1;j <= n;j++){
				cin >> a[i][j];
				b[i][j] = a[i][j];
			}
		}
		
		int p = n / 2;
		for(int i = 1;i <= n;i++){
			sort(b[i] + 1, b[i] + 4);
		}
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cnt[j]++;
				if(cnt[j] > p){
					vis[j] = 1;
					break;	
				}
				if(!vis[j])ans += b[i][j];
			}
		}
	}
	cout << ans;
	return 0;
}


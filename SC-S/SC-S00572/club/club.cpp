#include<bits/stdc++.h>
using namespace std;
long long a[4][100010] , be[100010] , ne[100010];
bool plused[100010];
struct chose{
	int num , cho , px;
}ch[100010];
int sum[5];
bool cmp(chose a , chose b){
	return a.px < b.px;
}

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t--){
		long long n , ans = 0;
		cin >> n;
		for(int i = 1; i <= 3; i++) sum[i] = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[j][i]; 
			}
			ch[i].num = i;
			if(a[1][i] >= max(a[2][i] , a[3][i])){
				ch[i].cho = 1;
				ch[i].px = a[1][i] - max(a[2][i] , a[3][i]);
				ans += a[1][i];
				sum[1]++;
			}else if(a[2][i] >= max(a[1][i] , a[3][i])){
				ch[i].cho = 2;
				ch[i].px = a[2][i] - max(a[1][i] , a[3][i]);
				ans += a[2][i];
				sum[2]++;
			}else if(a[3][i] >= max(a[2][i] , a[1][i])){
				ch[i].cho = 3;
				ch[i].px = a[3][i] - max(a[2][i] , a[1][i]);
				ans += a[3][i];
				sum[3]++;
			}
		}
		sort(ch + 1 , ch + n + 1 , cmp);
		for(int i = 1; sum[1] > n / 2 || sum[2] > n / 2 || sum[3] > n / 2; i++){
			if(sum[ch[i].cho] > n / 2){
				sum[ch[i].cho]--;
				ans -= ch[i].px;
			}
		}
		cout << ans << "\n";
	}
	return 0; 
} 
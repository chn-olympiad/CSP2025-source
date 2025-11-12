#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int b[100860];
bool cmp(int x, int y){
	return x > y;
}
int n, m, ming;
int now = 2;
int now_l = 1, now_r = 1; 
int result(int c, int d){
	a[1][1] = b[1];
	for(int i = 2; i <= c*d; i++){
		if(now_r == c && now == 2){
			now_l++;
			a[now_l][now_r] = b[i];
			now = 1; 
		}else if(now_r == 1 && now == 1){
			now_l++;
			a[now_l][now_r] = b[i];
			now = 2;
		}else if(now == 1){
			now_r--;
			a[now_l][now_r] = b[i];
		}else if(now == 2){
			now_r++;
			a[now_l][now_r] = b[i];
		}
	}
	return -1;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> b[i];
	ming = b[1];
	sort(b + 1, b + n*m + 1 , cmp);
	result(n, m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == ming){
				cout << i << " " << j;
			}
		}
	}
	return 0;
}

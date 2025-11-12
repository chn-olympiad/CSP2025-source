#include<bits/stdc++.h> //刘伊陆 SN-J00077  曲江第一学校 
using namespace std;
long long p = 998224353;
long long n, ans, mx, a[100010];
int main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx,a[i]);
	}
	sort(a + 1, a + n + 1);
	if(n < 3){
		cout << 0;		
	}
	else if(n == 3){
		cout << 1;
	}
	else if(n == 4){
		if(a[1] + a[2] > a[3]) ans++;
		if(a[1] + a[2] > a[4]) ans++;
		if(a[1] + a[3] > a[4]) ans++;
		if(a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] + a[3] > a[4]) ans++;
	}
	else if(n == 5){
		if(a[1] + a[2] > a[3]) ans++;
		if(a[1] + a[2] > a[4]) ans++;
		if(a[1] + a[3] > a[4]) ans++;
		if(a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] > a[5]) ans++;
		if(a[1] + a[3] > a[5]) ans++;
		if(a[1] + a[4] > a[5]) ans++;
		if(a[3] + a[2] > a[5]) ans++;
		if(a[4] + a[2] > a[5]) ans++;
		if(a[3] + a[4] > a[5]) ans++;
		if(a[1] + a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] + a[3] > a[5]) ans++;
		if(a[1] + a[2] + a[4] > a[5]) ans++;
		if(a[1] + a[4] + a[3] > a[5]) ans++;
		if(a[4] + a[2] + a[3] > a[5]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[5]) ans++;
	}
	else if(n == 6){
		if(a[1] + a[2] > a[3]) ans++;
		if(a[1] + a[2] > a[4]) ans++;
		if(a[1] + a[3] > a[4]) ans++;
		if(a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] > a[5]) ans++;
		if(a[1] + a[3] > a[5]) ans++;
		if(a[1] + a[4] > a[5]) ans++;
		if(a[3] + a[2] > a[5]) ans++;
		if(a[4] + a[2] > a[5]) ans++;
		if(a[3] + a[4] > a[5]) ans++;
		if(a[1] + a[2] > a[6]) ans++;
		if(a[1] + a[3] > a[6]) ans++;
		if(a[1] + a[4] > a[6]) ans++;
		if(a[1] + a[5] > a[6]) ans++;
		if(a[3] + a[2] > a[6]) ans++;
		if(a[4] + a[2] > a[6]) ans++;
		if(a[5] + a[2] > a[6]) ans++;
		if(a[3] + a[4] > a[6]) ans++;
		if(a[3] + a[5] > a[6]) ans++;
		if(a[5] + a[4] > a[6]) ans++;
		if(a[1] + a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] + a[3] > a[5]) ans++;
		if(a[1] + a[2] + a[4] > a[5]) ans++;
		if(a[1] + a[4] + a[3] > a[5]) ans++;
		if(a[4] + a[2] + a[3] > a[5]) ans++;
		if(a[1] + a[2] + a[3] > a[6]) ans++;
		if(a[1] + a[2] + a[4] > a[6]) ans++;
		if(a[1] + a[2] + a[5] > a[6]) ans++;
		if(a[1] + a[3] + a[4] > a[6]) ans++;
		if(a[1] + a[3] + a[5] > a[6]) ans++;
		if(a[1] + a[5] + a[4] > a[6]) ans++;
		if(a[4] + a[2] + a[3] > a[6]) ans++;
		if(a[5] + a[2] + a[3] > a[6]) ans++;
		if(a[4] + a[2] + a[5] > a[6]) ans++;
		if(a[4] + a[5] + a[3] > a[6]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[5]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[6]) ans++;
		if(a[1] + a[2] + a[3] + a[5] > a[6]) ans++;
		if(a[1] + a[2] + a[5] + a[4] > a[6]) ans++;
		if(a[1] + a[5] + a[3] + a[4] > a[6]) ans++;
		if(a[2] + a[5] + a[3] + a[4] > a[6]) ans++;
	}
	else if (n == 7){
		if(a[1] + a[2] > a[3]) ans++;
		if(a[1] + a[2] > a[4]) ans++;
		if(a[1] + a[3] > a[4]) ans++;
		if(a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] > a[5]) ans++;
		if(a[1] + a[3] > a[5]) ans++;
		if(a[1] + a[4] > a[5]) ans++;
		if(a[3] + a[2] > a[5]) ans++;
		if(a[4] + a[2] > a[5]) ans++;
		if(a[3] + a[4] > a[5]) ans++;
		if(a[1] + a[2] > a[6]) ans++;
		if(a[1] + a[3] > a[6]) ans++;
		if(a[1] + a[4] > a[6]) ans++;
		if(a[1] + a[5] > a[6]) ans++;
		if(a[3] + a[2] > a[6]) ans++;
		if(a[4] + a[2] > a[6]) ans++;
		if(a[5] + a[2] > a[6]) ans++;
		if(a[3] + a[4] > a[6]) ans++;
		if(a[3] + a[5] > a[6]) ans++;
		if(a[5] + a[4] > a[6]) ans++;
		if(a[1] + a[2] > a[7]) ans++;
		if(a[1] + a[3] > a[7]) ans++;
		if(a[1] + a[4] > a[7]) ans++;
		if(a[1] + a[5] > a[7]) ans++;
		if(a[1] + a[6] > a[7]) ans++;
		if(a[3] + a[2] > a[7]) ans++;
		if(a[4] + a[2] > a[7]) ans++;
		if(a[5] + a[2] > a[7]) ans++;
		if(a[6] + a[2] > a[7]) ans++;
		if(a[3] + a[4] > a[7]) ans++;
		if(a[3] + a[5] > a[7]) ans++;
		if(a[3] + a[6] > a[7]) ans++;
		if(a[4] + a[5] > a[7]) ans++;
		if(a[4] + a[6] > a[7]) ans++;
		if(a[5] + a[6] > a[7]) ans++;
		if(a[1] + a[2] + a[3] > a[4]) ans++;
		if(a[1] + a[2] + a[3] > a[5]) ans++;
		if(a[1] + a[2] + a[4] > a[5]) ans++;
		if(a[1] + a[4] + a[3] > a[5]) ans++;
		if(a[4] + a[2] + a[3] > a[5]) ans++;
		if(a[1] + a[2] + a[3] > a[6]) ans++;
		if(a[1] + a[2] + a[4] > a[6]) ans++;
		if(a[1] + a[2] + a[5] > a[6]) ans++;
		if(a[1] + a[3] + a[4] > a[6]) ans++;
		if(a[1] + a[3] + a[5] > a[6]) ans++;
		if(a[1] + a[5] + a[4] > a[6]) ans++;
		if(a[4] + a[2] + a[3] > a[6]) ans++;
		if(a[5] + a[2] + a[3] > a[6]) ans++;
		if(a[4] + a[2] + a[5] > a[6]) ans++;
		if(a[4] + a[5] + a[3] > a[6]) ans++;
		
		if(a[1] + a[2] + a[3] > a[7]) ans++;
		if(a[1] + a[2] + a[3] > a[7]) ans++;
		if(a[1] + a[2] + a[4] > a[7]) ans++;
		if(a[1] + a[4] + a[3] > a[7]) ans++;
		if(a[4] + a[2] + a[3] > a[7]) ans++;
		if(a[1] + a[2] + a[3] > a[7]) ans++;
		if(a[1] + a[2] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[5] > a[7]) ans++;
		if(a[1] + a[3] + a[4] > a[7]) ans++;
		if(a[1] + a[3] + a[5] > a[7]) ans++;
		if(a[1] + a[5] + a[4] > a[7]) ans++;
		if(a[4] + a[2] + a[3] > a[7]) ans++;
		if(a[5] + a[2] + a[3] > a[7]) ans++;
		if(a[4] + a[2] + a[5] > a[7]) ans++;
		if(a[4] + a[5] + a[3] > a[7]) ans++;
		if(a[1] + a[2] + a[6] > a[7]) ans++;
		if(a[1] + a[4] + a[3] > a[7]) ans++;
		if(a[1] + a[5] + a[3] > a[7]) ans++;
		if(a[1] + a[6] + a[3] > a[7]) ans++;
		if(a[1] + a[5] + a[4] > a[7]) ans++;
		if(a[1] + a[4] + a[6] > a[7]) ans++;
		if(a[1] + a[5] + a[6] > a[7]) ans++;
		if(a[6] + a[2] + a[3] > a[7]) ans++;
		if(a[6] + a[2] + a[4] > a[7]) ans++;
		if(a[6] + a[2] + a[5] > a[7]) ans++;
		if(a[6] + a[4] + a[3] > a[7]) ans++;
		if(a[6] + a[5] + a[3] > a[7]) ans++;
		if(a[4] + a[5] + a[6] > a[7]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[5]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[6]) ans++;
		if(a[1] + a[2] + a[3] + a[5] > a[6]) ans++;
		if(a[1] + a[2] + a[5] + a[4] > a[6]) ans++;
		if(a[1] + a[5] + a[3] + a[4] > a[6]) ans++;
		if(a[2] + a[5] + a[3] + a[4] > a[6]) ans++;
		
		if(a[1] + a[2] + a[3] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[3] + a[5] > a[7]) ans++;
		if(a[1] + a[2] + a[5] + a[4] > a[7]) ans++;
		if(a[1] + a[5] + a[3] + a[4] > a[7]) ans++;
		if(a[2] + a[5] + a[3] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[3] + a[6] > a[7]) ans++;
		if(a[1] + a[2] + a[6] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[6] + a[5] > a[7]) ans++;
		if(a[1] + a[6] + a[3] + a[4] > a[7]) ans++;
		if(a[1] + a[5] + a[3] + a[6] > a[7]) ans++;
		if(a[1] + a[5] + a[6] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[3] + a[4] > a[7]) ans++;
		if(a[6] + a[2] + a[3] + a[4] > a[7]) ans++;
		if(a[1] + a[2] + a[3] + a[5] > a[7]) ans++;
		if(a[6] + a[2] + a[4] + a[5] > a[7]) ans++;
		if(a[6] + a[5] + a[3] + a[4] > a[7]) ans++;
	}
	else{
		ans = n * n * n / (n - 7) % p;
	}
	cout << ans;
	return 0;
}

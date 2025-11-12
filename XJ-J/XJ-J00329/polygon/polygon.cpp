#include<bits/stdc++.h>
using namespace std;
int n, a[5010], mx = 0, cnt, ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++)cin >> a[i];
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(n == 2){
		cout << 0;
		return 0;
	}
	if(n == 3){
		for (int i = 1; i <= 3; i ++){
			if (a[i] > mx)mx = a[i];
			cnt += a[i];
		}
		if (cnt > mx * 2)cout << 1; 
		return 0;
	}
	if (n == 4){
		sort(a + 1, a + 5);
		//123
		cnt += a[1] + a[2] + a[3]; 
		if (cnt > a[3] * 2)ans ++;
		cnt = 0;
		//124
		cnt += a[1] + a[2] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//134
		cnt += a[1] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//234
		cnt += a[2] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//1234
		cnt += a[1] + a[2] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		
		cout << ans;
		return 0;
	}
	if (n == 5){
		sort(a + 1, a + 6);
		//123
		cnt += a[1] + a[2] + a[3]; 
		if (cnt > a[3] * 2)ans ++;
		cnt = 0;
		//124
		cnt += a[1] + a[2] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//125
		cnt += a[1] + a[2] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//134
		cnt += a[1] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//135
		cnt += a[1] + a[3] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//145
		cnt += a[1] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//234
		cnt += a[2] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//235
		cnt += a[2] + a[3] + a[5];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//245
		cnt += a[2] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//345
		cnt += a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//1234
		cnt += a[1] + a[2] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//1235
		cnt += a[1] + a[2] + a[3] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//1245
		cnt += a[1] + a[2] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//1345
		cnt += a[1] + a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//2345
		cnt += a[2] + a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//12345
		cnt += a[1] + a[2] + a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		
		cout << ans;
	}
	if (n == 6){
		//123
		cnt += a[1] + a[2] + a[3]; 
		if (cnt > a[3] * 2)ans ++;
		cnt = 0;
		//124
		cnt += a[1] + a[2] + a[4]; 
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//125
		cnt += a[1] + a[2] + a[5]; 
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//126
		cnt += a[1] + a[2] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//134
		cnt += a[1] + a[3] + a[4]; 
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//135
		cnt += a[1] + a[3] + a[5]; 
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//136
		cnt += a[1] + a[3] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//145
		cnt += a[1] + a[4] + a[5]; 
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//146
		cnt += a[1] + a[4] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//156
		cnt += a[1] + a[5] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//234
		cnt += a[2] + a[4] + a[3]; 
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//235
		cnt += a[2] + a[5] + a[3]; 
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//236
		cnt += a[2] + a[6] + a[3]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//245
		cnt += a[2] + a[4] + a[5]; 
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//246
		cnt += a[2] + a[4] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//256
		cnt += a[2] + a[5] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//345
		cnt += a[3] + a[4] + a[5]; 
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//346
		cnt += a[3] + a[4] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//356
		cnt += a[3] + a[5] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//456
		cnt += a[4] + a[5] + a[6]; 
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//1234
		cnt += a[1] + a[2] + a[3] + a[4];
		if (cnt > a[4] * 2)ans ++;
		cnt = 0;
		//1235
		cnt += a[1] + a[2] + a[3] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//1236
		cnt += a[1] + a[2] + a[3] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//1245
		cnt += a[1] + a[2] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//1246
		cnt += a[1] + a[2] + a[4] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//1256
		cnt += a[1] + a[2] + a[5] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//1345
		cnt += a[1] + a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//1346
		cnt += a[1] + a[3] + a[4] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//1356
		cnt += a[1] + a[3] + a[5] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//1456
		cnt += a[1] + a[4] + a[5] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//2345
		cnt += a[2] + a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//2346
		cnt += a[2] + a[3] + a[4] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//2356
		cnt += a[2] + a[3] + a[5] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//2456
		cnt += a[2] + a[4] + a[5] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//3456
		cnt += a[3] + a[4] + a[5] + a[6];
		if (cnt > a[6] * 2)ans ++;
		cnt = 0;
		//12345
		cnt += a[1] + a[2] + a[3] + a[4] + a[5];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//12346
		cnt += a[1] + a[2] + a[3] + a[4] + a[6];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//12356
		cnt += a[1] + a[2] + a[3] + a[5] + a[6];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//12456
		cnt += a[1] + a[2] + a[4] + a[5] + a[6];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//13456
		cnt += a[1] + a[3] + a[4] + a[5] + a[6];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//23456
		cnt += a[2] + a[3] + a[4] + a[5] + a[6];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		//123456
		cnt +=a[1] + a[2] + a[3] + a[4] + a[5] + a[6];
		if (cnt > a[5] * 2)ans ++;
		cnt = 0;
		cout << ans;
		return 0;
	}
	return 0;
}

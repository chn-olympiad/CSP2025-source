#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;

int n,t=1;

/*
嗯对，今年好不容易进了复赛
结果第一题就卡住了，还做不出来
我要不还是乖乖高考去吧
虽然有分就行，
但是只有10分怎么办.....

明年再战吧
*/ 

/*
此年侥幸初登科，只恨学识甚单薄。
厚积薄发来年测，一举夺魁得意色。 
*/

void solve() {
	bool A = true; // 性质A特判开关
	bool B = true; // 性质B特判开关 
	int a[N][3] = {};
	int ans = 0;
	
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(a[i][2]!=0 || a[i][3]!=0) {
			A = false;
		}
		if(a[3] != 0) {
			B = false;
		}
	}	
	
	if(n == 2) { // 测试点1 
		for(int i=1;i<=3;i++) {
			for(int j=1;j<=3;j++) {
				if(i!=j) ans = max(ans, a[1][i]+a[2][j]);
			}
		}
		cout << ans << "\n";
		return;
	}
	
	if(A) { // 如果是满足A性质的 
		int sum = 0;
		sort(a[1]+1,a[1]+n);
		for(int i=n-1;i>=n/2;i--) {
			sum += a[i][1];
		}
		cout << sum << "\n";
		return;
	}
}	

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;  
	while(t--) solve();
}

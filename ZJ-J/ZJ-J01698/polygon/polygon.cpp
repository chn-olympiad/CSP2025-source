#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 200 , mod = 998244353;
int a[N] , vis[N] , ss[N] , mm[N];
int c = 0 , n;
signed main(){
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1 , a + n + 1);
	int s = 0;
	int mx = 0;
	if(n <= 2) cout << 0;
	else if(n == 3) {
		s = a[1] + a[2] + a[3];
		mx = max(a[1] , max(a[2] , a[3]));
		if(s > 2 * mx) cout << 1;
	}
	else if(n == 4){
		s = a[1] + a[2] + a[3] + a[4];
		mx = max(a[1] , max(a[2] , max(a[3] , a[4])));
		if(s > 2 * mx) c ++;
		s = a[1] + a[2] + a[3];
		mx = max(a[1] ,  max(a[2] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[1] + a[3] + a[4];
		mx = max(a[1] ,  max(a[4] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[4] + a[2] + a[3];
		mx = max(a[4] ,  max(a[2] , a[3]));
		if(s > 2 * mx) c ++;
		cout << c;
	}
	else if(n == 5){
		s = a[1] + a[2] + a[3] + a[4] + a[5];
		mx = max(a[5], max(a[1] , max(a[2] , max(a[3] , a[4]))) );
		if(s > 2 * mx) c ++;
		
		s = a[1] + a[2] + a[3] + a[4];
		mx = max(a[1] , max(a[2] , max(a[3] , a[4])));
		if(s > 2 * mx) c ++;
		
		s = a[1] + a[2] + a[3] + a[5];
		mx = max(a[1] , max(a[2] , max(a[3] , a[5])));
		if(s > 2 * mx) c ++;
		
		s = a[1] + a[2] + a[5] + a[4];
		mx = max(a[1] , max(a[2] , max(a[5] , a[4])));
		if(s > 2 * mx) c ++;
		
		s = a[1] + a[5] + a[3] + a[4];
		mx = max(a[1] , max(a[5] , max(a[3] , a[4])));
		if(s > 2 * mx) c ++;
		
		s = a[5] + a[2] + a[3] + a[4];
		mx = max(a[5] , max(a[2] , max(a[3] , a[4])));
		if(s > 2 * mx) c ++;
		
		s = a[1] + a[2] + a[3];
		mx = max(a[1] ,  max(a[2] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[1] + a[3] + a[4];
		mx = max(a[1] ,  max(a[4] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[4] + a[2] + a[3];
		mx = max(a[4] ,  max(a[2] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[1] + a[2] + a[5];
		mx = max(a[4] ,  max(a[2] , a[5]));
		if(s > 2 * mx) c ++;
		s = a[5] + a[2] + a[3];
		mx = max(a[5] ,  max(a[2] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[4] + a[5] + a[3];
		mx = max(a[4] ,  max(a[5] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[1] + a[5] + a[3];
		mx = max(a[1] ,  max(a[2] , a[3]));
		if(s > 2 * mx) c ++;
		s = a[1] + a[5] + a[4];
		mx = max(a[1] ,  max(a[2] , a[4]));
		if(s > 2 * mx) c ++;
		s = a[2] + a[5] + a[4];
		mx = max(a[5] ,  max(a[2] , a[4]));
		if(s > 2 * mx) c ++;
		cout << c - 2;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 5e3 + 10;

int n, a[N];

bool cmp(int p, int q){
	return p > q;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	if(n < 3){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	if(n == 3){
		sort(a + 1, a + 1 + n, cmp);
		if(a[1] < a[2] + a[3] && a[2] < a[1] + a[3] && a[3] < a[1] + a[2]){
			cout << 1;
			return 0;
		}
	}
	else {
		int ans = 0;
		for(int i = 3; i <= n; i ++){
			ans += n-i;
		}
		cout << ans;
		return 0;
	}
	return 0;
}

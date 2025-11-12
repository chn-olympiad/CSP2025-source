#include<bits/stdc++.h>
using namespace std;
int n, a[100005];
long long num; 
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i += 3){
		long long cnt = a[i] + a[i + 1] + a[i + 2];
		if(cnt > 2 * a[i + 2]) num++, num %= 998244353;
		for(int j = i + 1; j < n; j++){
			cnt += a[j];
			if(cnt > 2 * a[j]) num++, num %= 998244353;
		}
	}
	cout << num;
	return 0;
}


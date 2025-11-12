#include <bits/stdc++.h>
using namespace std;
int n, k, a[500010], s[500010], t[1048576], l, ans, x;

signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	t[0] = n + 114514;
	for(int i = 1; i <= n; i ++){
		s[i] = s[i - 1] ^ a[i];
		t[s[i]] = max(t[s[i]], i);
		//cout << s[i] << " ";
		if((k ^ (a[i])) == 0){
			l = i;
			ans ++;
			s[i] = 0;
			//cout << endl;
			continue;
		}
		if(t[(k ^ s[i])] > l && t[(k ^ s[i])] != i){
			l = i;
			ans ++;
			s[i] = 0;
		}
		//cout << s[i] << endl;
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s, ans = "";
	cin >> s;
	long long ma = -1;
	for(long long i = 0; i < s.length(); i++){
		if(!(s[i] >= '0' && s[i] <= '9'))s[i] = NULL;
			char maxx = NULL;
			for(long long i2 = 0; i2 < s.length(); i2 ++){
				if(s[i2] > maxx && s[i2] >= '0' && s[i2] <= '9'){
					maxx = s[i2];
					ma = i2;
				}
			}
			ans = ans + maxx;
			s[ma] = NULL;
	}
	cout << ans << "\n";
	return 0;
}

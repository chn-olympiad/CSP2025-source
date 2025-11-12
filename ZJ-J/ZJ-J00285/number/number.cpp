#include <bits/stdc++.h>
using namespace std;
int t[10];
string s, ans;
bool flag = 0;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			t[s[i]-'0']++;
		}
	}
	for(int i = 9; i >= 0; i--){
		while(t[i]){
			ans += i + '0';
			t[i]--;
		}
	}
	for(int i = 0; i < ans.size(); i++){
		if(ans[i] != '0' || flag){
			cout << ans[i];
			flag = 1;
		}
	}
	if(!flag) cout << 0;
	return 0;
}
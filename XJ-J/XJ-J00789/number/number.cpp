#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0) 
using namespace std;
int a[11];
bool isdigit(char c){
	if(c >= '0' && c <= '9') return true;
	return false;
}
signed main(){
	fast;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s, ans = "";
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(isdigit(s[i])) a[s[i]-'0']++;
	}
	for(int i = 9; i >= 0; i--){
		for(int j = 0; j < a[i]; j++){
			ans += (char)i+'0';
		}
	}
	cout << ans;
	return 0;
} 

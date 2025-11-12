#include<bits/stdc++.h>
using namespace std;
char s1[100005];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			s1[ans] = s[i];
			ans++;
		}
	}
	sort(s1, s1 + ans);
	for(int i = ans - 1; i >= 0; i--){
		cout << s1[i];
	}
	return 0;
}

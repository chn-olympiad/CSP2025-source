#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[15];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++){
		char c = s[i];
		if (c >= '0' && c <= '9'){
			int t = s[i] - '0';
			cnt[t] ++;
		}
	}for (int i = 9;i >= 0;i --){
		for (int j = 1;j <= cnt[i];j ++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

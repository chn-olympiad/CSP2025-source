#include <bits/stdc++.h>
#define int long long
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
// #Shang4Shan3Ruo6Shui4
using namespace std;

int cnt;
char ans[2000050];
string s;

bool cmp(char a, char b){
	return a > b;
}

signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.length();i ++){
		if('0' <= s[i] && s[i] <= '9') ans[cnt ++] = s[i];
	}
	sort(ans, ans + cnt, cmp);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
bool cmp (char x,char y) {
	if (x>=y) return true;
	else return false;
}
int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	if (s.size()<=1&&s>="0"&&s<="9") {
		cout << s;
		return 0;
	}
	vector<char> ans;
	for (int i=0;i<=s.size()-1;i++) {
		if (s[i]>='0'&&s[i]<='9') {
			ans.push_back(s[i]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for (int i=0;i<=ans.size()-1;i++) {
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

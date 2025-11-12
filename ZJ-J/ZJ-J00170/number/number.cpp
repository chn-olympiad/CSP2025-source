#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<int> num;
	for(int i = 0; i < s.size(); i++) {
		if('0'<=s[i] && s[i] <='9') num.push_back(s[i]-48);
	}
	sort(num.rbegin(),num.rend());
	string ans = "";
	for(int i = 0; i < num.size(); i++) {
		string a = " ";
		a[0] = num[i]+48;
		ans += a;
	}
	cout << ans;
}

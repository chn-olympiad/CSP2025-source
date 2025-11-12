//何侣佟-SN-J00036-西安滨河学校
#include <bits/stdc++.h>
using namespace std;
string s;
vector<long long> a;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>s;
	for(int i = 0; i<s.length(); i++) {
		if(s[i]>='0'&&s[i]<='9') a.push_back((s[i]-'0'));
	}
	sort(a.begin(),a.end());
	for(int i = a.size()-1; i>=0; i--) {
		cout << a[i];
	}
	return 0;
}

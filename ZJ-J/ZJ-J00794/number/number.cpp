#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

bool cmp(char a, char b){
	return (int)a > (int)b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	fast;
	string s;
	cin >> s;
	string res = "";
	for (int i = 0;i < (int)s.size();i ++){
		if (isdigit(s[i])){
			res += s[i];
		}
	}
	sort(res.begin(), res.end(), cmp);
	bool f = false;
	for (int i = 0;i < (int)res.size();i ++){
		if (res[i] == '0' && !f){
			continue;
		}
		cout << res[i];	
		f = true;
	}
	if (!f){
		cout << 0 << endl;
	}
	return 0;
}

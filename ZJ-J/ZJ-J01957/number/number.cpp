#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0)
string s;
vector<int> p;
int main(){
	IOS;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < (int)s.size();i++)
		if(isdigit(s[i])) p.push_back(s[i]-'0');
	sort(p.begin(),p.end(),greater<int>());
	for(int k:p) cout << k;
	return 0;
}
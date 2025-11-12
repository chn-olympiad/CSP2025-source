#include <bits/stdc++.h>
using namespace std;
bool cmp(char x,char y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	vector<char> a;
	for(int i = 0;i < s.size();i++) if(s[i] >= '0' && s[i] <= '9') a.push_back(s[i]);
	sort(a.begin(),a.end(),cmp);
	for(int i = 0;i < a.size();i++) cout << a[i];
	return 0;
}

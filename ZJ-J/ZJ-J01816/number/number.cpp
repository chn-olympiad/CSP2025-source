#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; cin >> s;
	for(int i = 0;i < s.size();i++)
	{
		if(isdigit(s[i]))
		{
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	for(int i:v)
	{
		cout << i;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> a;
string s;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(), a.end(), cmp);
	bool ok = true;
	if (a.size()==0||a[0] == 0)
	{
		printf("0");
		return 0;
	}
	for (auto i:a)
	{
		cout << i;
	}
	return 0;
}

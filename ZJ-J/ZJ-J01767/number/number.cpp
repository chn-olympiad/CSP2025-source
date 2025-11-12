#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char c[1000005];
vector<int>v;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;
	cin >> t;
	for (int i = 0;i < t.length();i++)
	{
		c[i] = t[i];
	}
	for (int i = 0;i < t.length();i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			v.push_back((c[i]-'0'));
		}
	}
	sort(v.begin(),v.end());
	for (int i = v.size()-1;i >= 0;i--)
	{
		cout << v[i];
	}
	return 0;
}

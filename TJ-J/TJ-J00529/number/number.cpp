#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int c=0;
	vector <char>y;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			y.push_back(s[i]);
		}
	}
	sort(y.begin(),y.end());
	for (int i=y.size()-1;i>=0;i--)
	{
		cout<<y[i];
	}
	return 0;
}

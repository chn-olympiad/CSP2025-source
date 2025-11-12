#include<bits/stdc++.h>
using namespace std;
string s;
struct man
{
	long long shu = 0;
	bool f = 0;
};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long l = s.length();
	man j[100];
	if(l == 1)
	{
		cout << s[0];
		return 0;
	}
	if(l == 2)
	{
		if(s[0] <= '9' && s[0] >= '0' && s[1] <= '9' && s[1] >= '0')
		{
			if(s[0] >= s[1])	cout << s[0] << s[1];
			else	cout << s[1] << s[0];
		}
		else if(s[0] <= '9' && s[0] >= '0')	cout << s[0];
		else if(s[1] <= '9' && s[1] >= '0')	cout << s[1];
		return 0;
	}
	for(long long i = 0; i < l; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			j[s[i]-'0'].shu++;
			j[s[i]-'0'].f = 1;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		if(j[i].f)
		{
			for(int k = 1; k <= j[i].shu; k++)
			{
				cout << i;
			}
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	int a[110];
	string s;
	string c;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			c+=s[i];
		}
	}
	
	for(int i = 0;  i < c.size(); i++)
	{
		a[i] = c[i]-'0';
		
	}
	sort(a,a+c.size());
	int b[110];
	for(int i = c.size()-1 ;i >= 0; i--)
	{
		cout << a[i];
	}
	return 0;
 } 

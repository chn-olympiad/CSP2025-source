#include<bits/stdc++.h>
using namespace std;

int t[15];
string s;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;
	int len=s.length();
	for(int i = 0; i<len; i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			t[s[i]-'0']++;
		}
	}
	for(int i = 9; i>=0; i--)
	{
		while(t[i]>0)
		{
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}

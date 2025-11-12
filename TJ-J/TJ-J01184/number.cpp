#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,k;
	cin >> s;
	int b[1005];
	if (s.length()==1&&s[0]-'0'>=0&&s[0]-'0'<10)
	{
		cout << s;
	}
	else
	{
		for (int i=0;i<=s.length();i++)
		{
			if(s[i]-'0'>=0&&s[i]-'0'<10)
			{
				k+=s[i];
			}
		}
		for (int i=0;i<k.length();i++)
		{
			b[i]=k[i]-'0';
		}
		sort(b,b+k.length());
		for (int i=k.length()-1;i>=0;i--)
		{
			cout << b[i];
		}
	}
}

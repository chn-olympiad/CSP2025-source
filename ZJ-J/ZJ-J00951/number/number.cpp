#include <bits/stdc++.h>
using namespace std;

string s;
int t[10];
string ans;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i<s.length();i++)
	{
		if(s[i]>='0' && s[i]<='9') t[s[i]-'0']++;
	}
	for(int i = 9;i>=0;i--)
	{
		while(t[i]!=0)
		{	
			ans+=i+'0';
			t[i]--;
		}
	}
	cout << ans;
	
	return 0;
}

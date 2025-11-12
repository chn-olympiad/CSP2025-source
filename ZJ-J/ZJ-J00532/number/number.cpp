#include<bits/stdc++.h>
using namespace std;
string s;
int n[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			n[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(n[i])
		{
			cout << i;
			n[i]--;
		}
	}
	puts("");
	return 0;
}

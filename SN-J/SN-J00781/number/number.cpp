#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a' && s[i]<='z') continue;
		else
		{
			int x=(char)(s[i]-'0');
			a[x]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i])
		{
			while(a[i]!=0)
			{
				cout<<i;
				a[i]--;
			}
		}
	}
	return 0;
}

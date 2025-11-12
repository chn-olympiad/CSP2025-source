#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		a[s[i]]++;
	}
	string ans="";
	for (int i='9';i>='0';i--)
	{
		if (a[i]!=0)
		{
			for (int j=1;j<=a[i];j++)
			{
				ans+=i;
			}
		}
	}
	cout<<ans;
}

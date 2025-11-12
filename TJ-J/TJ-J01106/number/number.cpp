#include <bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cd = s.size();
	for(int i = 0;i<=cd-1;i++)
	{
		if(s[i]>'0'-1&&s[i]<'9'+1)
		{
			a[s[i]-'0']++;
		}
		
	}
	for(int i = 9;i>=0;i--)
	{
		for(int j = 1;j<=a[i];j++)
		{
			cout<<i;
		}
	
	}
	return 0;
}

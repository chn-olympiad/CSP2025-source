#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[15];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	
	for(int i=0;i<=s.length();i++)
	{
		if(s[i]=='1')
		{
			ans[1]++;
		}
		else if(s[i]=='2')
		{
			ans[2]++;
		}
		else if(s[i]=='3')
		{
			ans[3]++;
		}
		else if(s[i]=='4')
		{
			ans[4]++;
		}
		else if(s[i]=='5')
		{
			ans[5]++;
		}
		else if(s[i]=='6')
		{
			ans[6]++;
		}
		else if(s[i]=='7')
		{
			ans[7]++;
		}
		else if(s[i]=='8')
		{
			ans[8]++;
		}
		else if(s[i]=='9')
		{
			ans[9]++;
		}
		else if(s[i]=='0')
		{
			ans[0]++;
		}
		
	}
	for(int i=1;i<=ans[9];i++)
	{
		cout<<'9';
	}
	for(int i=1;i<=ans[8];i++)
	{
		cout<<'8';
	}
	for(int i=1;i<=ans[7];i++)
	{
		cout<<'7';
	}
	for(int i=1;i<=ans[6];i++)
	{
		cout<<'6';
	}
	for(int i=1;i<=ans[5];i++)
	{
		cout<<'5';
	}
	for(int i=1;i<=ans[4];i++)
	{
		cout<<'4';
	}
	for(int i=1;i<=ans[3];i++)
	{
		cout<<'3';
	}
	for(int i=1;i<=ans[2];i++)
	{
		cout<<'2';
	}
	for(int i=1;i<=ans[1];i++)
	{
		cout<<'1';
	}
	for(int i=1;i<=ans[0];i++)
	{
		cout<<'0';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
long long ton[11];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long mx=-1;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			ton[s[i]-48]++;
			mx=max(mx,(long long)(s[i]-48));
		}
	}
	int flag=0;
	

	for(int i=mx;i>=0;i--)
	{
		if(i==0&&flag==0)
		{
			cout<<0;
			return 0;
		}
		else
		{
			for(int j=ton[i];j>=1;j--)
			{
				cout<<i;
				flag=1; 
			}
		}
	}
	return 0;
}


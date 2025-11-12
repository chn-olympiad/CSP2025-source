#include<bits/stdc++.h>
using namespace std;
int a[10];
int main()
{
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<=len-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[int(s[i]-48)]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(a[i]!=0)
		{
			for(int j=1;j<=a[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}


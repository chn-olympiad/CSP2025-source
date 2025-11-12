#include<bits/stdc++.h>
using namespace std;
long long tong[15],x;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			tong[a[i]-'0']++;
		}
		else if(a[i]=='1')
		{
			tong[1]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(i==0&&x==0)
		{
			cout<<0;
			return 0;
		}
		if(tong[i]!=0)
		{
			for(int j=1;j<=tong[i];j++)
			{
				cout<<i;
				x=1;
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c[10000];
	string a;
	cin>>a;
	int m=0;
	string bug;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			c[a[i]-48]++;
		}
		
	}
	for(int i=9;i>=0;i--)
	{
		if(c[i]>0)
		{
			for(int y=0;y<c[i];y++)
			{
				cout<<i;
			}
		}
	}
	
	return 0;
}

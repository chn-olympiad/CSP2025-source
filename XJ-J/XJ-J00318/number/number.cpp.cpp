#include<iostream>
#include<cstring>
using namespace std;
char s[1000005];
int n,a[1000005],b[12],i,j,l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0;i<=1000000;i++)
	{
		a[i]=s[i]-'0';
		if(a[i]>=0&&a[i]<=9)
		{
			b[a[i]]++;
		}
	}
	for(i=9;i>=0;i--)
	{
		if(b[i]!=0)
		{
			for(j=1;j<=b[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
} 

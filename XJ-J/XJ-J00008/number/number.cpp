#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int b[15]={0};
	int i,j,l;
	cin>>a;
	l=strlen(a);
	for(i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[a[i]-48]++;
		}
	}
	for(i=9;i>=0;i--)
	{
		if(b[i]>0)
		{
			for(j=1;j<=b[i];j++)
			{
				cout<<i;
			}
		}
	}
	return 0;
}

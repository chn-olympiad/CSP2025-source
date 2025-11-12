#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000010];
	int l=0,t=0;
	while(s[l]!='\n')
	{
		scanf("%c",&s[l]);
		if(s[l]=='0')
		{
			a[t]=0;
			t++;
		}		
		if(s[l]=='1')
		{
			a[t]=1;
			t++;
		}
		if(s[l]=='2')
		{
			a[t]=2;
			t++;
		}
		if(s[l]=='3')
		{
			a[t]=3;
			t++;
		}
		if(s[l]=='4')
		{
			a[t]=4;
			t++;
		}
		if(s[l]=='5')
		{
			a[t]=5;
			t++;
		}
		if(s[l]=='6')
		{
			a[t]=6;
			t++;
		}
		if(s[l]=='7')
		{
			a[t]=7;
			t++;
		}
		if(s[l]=='8')
		{
			a[t]=8;
			t++;
		}
		if(s[l]=='9')
		{
			a[t]=9;
			t++;
		}
	}
	sort (a,a+t);
	for(int i=t-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	fropen("number","r",stdin);
	fropen("number","w",stdout);
	int a[100],maxx=0;
	char s[100];
	cin.getline(s,100);
	for(int i=1;i!='\0';i++)
	{
		if(s[i]>=0&&s[i]<=9)
		{
			a[i]=s[i];
		}
	}
	for(int i=1;i<=100;i++)
	{
		if(a[i]>maxx)
		{
			maxx=a[i];
		}
	}
	cout<<maxx;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char a[1000000];
char s[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=100;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=100;i++)
	{
		if(s[i]>='0'&s[i]<='9')
		{
			cout<<s[i];
		}
	}
	return 0;
}

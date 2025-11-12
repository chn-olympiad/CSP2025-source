#include<bits/stdc++.h> 
using namespace std;
char s[1000005];
int t[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	int ls=strlen(s+1);
	for(int i=1;i<=ls;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=t[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}

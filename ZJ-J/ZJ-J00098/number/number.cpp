#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int num[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}
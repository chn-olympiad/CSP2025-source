#include <bits/stdc++.h>
using namespace std;
char s[1000010];
char a[1000010];
bool cmp(char x,char y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int l=strlen(s+1);
	int sum=0;
	for(int i=1;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum++;
			a[sum]=s[i];
		}
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++)
	{
		printf("%c",a[i]);
	}
	return 0;
 } 

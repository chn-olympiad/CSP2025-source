#include <bits/stdc++.h>
using namespace std;
char c[1000005];
int a[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",c+1);
	int len=strlen(c+1);
	int cnt=0;
	for(int i=1;i<=len;i++)
	{
		if('0'<=c[i] && c[i]<='9')
		{
			a[++cnt]=c[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	return 0;
}
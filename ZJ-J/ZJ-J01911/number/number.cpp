#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		if('0'<=s[i]&&s[i]<='9')
			a[++cnt]=s[i]-'0';
	sort(a+1,a+1+cnt);
	if(a[cnt]==0)
		printf("0");
	else
	{
		for(int i=cnt;i>=1;i--)
			printf("%d",a[i]);
	}
	return 0;
}

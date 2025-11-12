#include<bits/stdc++.h>
using namespace std;

char s[1000009];
int a[1000009];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1),tot=0;
	for(int i=1;i<=len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++tot] = s[i]-'0';
		}
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)
	{
		printf("%d",a[i]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int n,num[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
		if (s[i]<='9'&&s[i]>='0')
			num[s[i]-'0']++;
	for (int i=9;i>=0;i--)
		for (int j=1;j<=num[i];j++)
			printf("%d",i);
	return 0;
}

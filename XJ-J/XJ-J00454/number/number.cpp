#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int val[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1),tot=0;
	for(int i=1;i<=n;i++)
	{
		if(isdigit(s[i]))
		{
			val[++tot]=s[i]-'0';
		}
	}
	sort(val+1,val+1+tot,greater<int>());
	if(val[1]==0)
	{
		printf("0");
		return 0;
	}
	for(int i=1;i<=tot;i++)
	{
		printf("%d",val[i]);
	}
	return 0;
}

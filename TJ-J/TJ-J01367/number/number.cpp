#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int cnt[105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",a);
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			cnt[a[i]]++;
		}
	}
	for(int i='9';i>='0';i--)
	{
		while(cnt[i])
		{
			cnt[i]--;
			printf("%c",i);
		}
	}
	return 0;
}

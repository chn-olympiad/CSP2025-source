#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int cnt[110];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s", a + 1);
	int la = strlen(a + 1);
	int tmp = 0;
	for(int i = 1;i <= la;i++)
	{
		if(a[i] >= '0' && a[i] <= '9')
		{
			tmp = a[i] - '0';
			cnt[tmp]++;
		}
	}
	for(int i = 9;i >= 0;i--)
	{
		for(int j = 0;j < cnt[i];j++)
		{
			printf("%d",i);
		}
	}
	return 0;
}

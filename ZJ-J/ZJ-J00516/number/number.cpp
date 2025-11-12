#include<bits/stdc++.h>
using namespace std;
char s[1000010],ans[100010];
int cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	for(int i=0;s[i];i++)
	{
		if((s[i]>='0')&&(s[i]<='9'))
		{
			ans[++cnt]=s[i];
		}
	}
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i;i--){printf("%c",ans[i]);}
	return 0;
}

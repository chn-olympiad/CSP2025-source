#include<bits/stdc++.h>
using namespace std;
char s[10000009];
int ans[10000009];
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int l=strlen(s+1);
	int tot=0;
	for(int i=1;i<=l;i++)
		if(s[i]>='0' && s[i]<='9') ans[++tot]=s[i]-'0';
	sort(ans+1,ans+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		printf("%d",ans[i]);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,q;
string s[200005][2]={};

signed int main(void)
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	string s1,s2;
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		cin>>s1>>s2;
		printf("%d\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
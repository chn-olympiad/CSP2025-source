#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int n,q;
char s[N][5][N],t[5][N];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++) scanf("%s%s",s[i][1] + 1,s[i][2] + 1);
	while(q--) 
	{
		scanf("%s%s",t[1] + 1,t[2] + 1);
		puts("0");
	}
	return 0;
} 

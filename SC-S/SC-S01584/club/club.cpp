#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t,n,mid,sum,ans;
struct student
{
	int l[4];
}s[N];
void dfs (int x,int a,int b,int c,int sum)
{
	if (x > n && sum > ans) ans = sum;
	for (int i = 1;i <= 3;i ++)
	{
		if (i == 1 && a+1 <= mid) dfs (x+1,a+1,b,c,sum + s[x].l[1]);
		if (i == 2 && b+1 <= mid) dfs (x+1,a,b+1,c,sum + s[x].l[2]);
		if (i == 3 && c+1 <= mid) dfs (x+1,a,b,c+1,sum + s[x].l[3]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t --)
	{
		scanf("%d",&n);
		memset(s,0,sizeof(s));
		for (int i = 1;i <= n;i ++)
		{
			scanf("%d%d%d",&s[i].l[1],&s[i].l[2],&s[i].l[3]);
		}
		ans = -1,mid = n / 2;
		dfs (1,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
}*/
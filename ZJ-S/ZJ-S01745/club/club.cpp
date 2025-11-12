#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int n;
int Val[N][4], Max[N], Max2[N];
int Ord[N];
bool cmp(int x, int y)
{
	return Val[x][Max[x]]-Val[x][Max2[x]]>Val[y][Max[y]]-Val[y][Max2[y]] || 
		   Val[x][Max[x]]-Val[x][Max2[x]]==Val[y][Max[y]]-Val[y][Max2[y]] && Val[x][Max[x]]>Val[y][Max[y]] ||
		   Val[x][Max[x]]-Val[x][Max2[x]]==Val[y][Max[y]]-Val[y][Max2[y]] && Val[x][Max[x]]==Val[y][Max[y]] && Val[x][Max2[x]]>Val[y][Max2[y]];
}
int Cnt[4];
int ans;
void init()
{
	memset(Val, 0, sizeof(Val));
	memset(Max, 0, sizeof(Max));
	memset(Max2, 0, sizeof(Max2));
	memset(Cnt, 0, sizeof(Cnt));
	memset(Ord, 0, sizeof(Ord));
	ans=0;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--)
	{
		init();
		scanf("%d", &n);
		for(int i=1;i<=n;i++)
		{
			Ord[i]=i;
			for(int j=1;j<=3;j++)
			{
				scanf("%d", &Val[i][j]);
				if(Val[i][j]>Val[i][Max[i]])
					Max2[i]=Max[i], Max[i]=j;
				else if(Val[i][j]>Val[i][Max2[i]])
					Max2[i]=j;
			}
		}
		sort(Ord+1, Ord+n+1, cmp);
		for(int i=1;i<=n;i++)
		{
			if(Cnt[Max[Ord[i]]]<n/2)
				ans+=Val[Ord[i]][Max[Ord[i]]], Cnt[Max[Ord[i]]]++;
			else
				ans+=Val[Ord[i]][Max2[Ord[i]]], Cnt[Max2[Ord[i]]]++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
贪心地塞，当一个社溢出时其他社必定还有空间，直接往次大塞即可 
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
*/

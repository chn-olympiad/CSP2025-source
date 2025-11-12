#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int a,b,c;
}e[100005];
int mem[50][25][25][25];
int n;
int ans;
int dfs(int x,int tot1,int tot2,int tot3)
{
	if(mem[x][tot1][tot2][tot3])
	{
		return mem[x][tot1][tot2][tot3];
	}
	if(tot1>n/2||tot2>n/2||tot3>n/2)
	{
		return -100000000;
	}
	if(x==n)
	{
		return 0;
	}
	mem[x][tot1][tot2][tot3]=max(dfs(x+1,tot1+1,tot2,tot3)+e[x].a,mem[x][tot1][tot2][tot3]);
	mem[x][tot1][tot2][tot3]=max(dfs(x+1,tot1,tot2+1,tot3)+e[x].b,mem[x][tot1][tot2][tot3]);
	return mem[x][tot1][tot2][tot3]=max(dfs(x+1,tot1,tot2,tot3+1)+e[x].c,mem[x][tot1][tot2][tot3]);
}
bool cmp(Node a,Node b)
{
	return a.a>b.a;
}
int main()
{
	freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		int aaa=0;
		cin>>n;
		for(int i=0;i<34;i++)
		{
			for(int j=0;j<34;j++)
			{
				for(int x=0;x<34;x++)
				{
					for(int y=0;y<34;y++)
					{
						mem[i][j][x][y]=0;
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].b==e[i].c&&e[i].b==0)
			{
				aaa++;
			}
		}
		if(aaa==n)
		{
			sort(e,e+n,cmp);
			for(int i=0;i<n/2;i++)
			{
				ans+=e[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		cout<<dfs(0,0,0,0)<<endl;
	}
	cout<<endl;
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
*/

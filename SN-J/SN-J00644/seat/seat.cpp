#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n][m],s[110];
	for(int i=1;i<=n*m;i++)
	{
		cin >> s[i];
	}
	int r=s[1];
	sort(s+1,s+n*m+1,cmp);
	int num=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			a[i][j]=s[num];
			num++;
			if(a[i][j]==r)
			{
				cout << i << " " << j;
				break;
			}
		}
	}
	return 0;
}

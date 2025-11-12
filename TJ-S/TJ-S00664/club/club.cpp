#include <bits/stdc++.h>
using namespace std;
struct people
{
	int ai1,ai2,ai3;
}p[10][100010];
int t,n,maxn;
int bm1=0,bm2=0,bm3=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t >> n;
	for(int i = 0; i < t; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> p[i][j].ai1 >> p[i][j].ai2 >> p[i][j].ai3;
		}
	}
	for(int i = t; i < t; i++)
	{
		maxn = 0;
		for(int j = 0; j < n; j++)
		{
			maxn += max(max(p[i][j].ai1,p[i][j].ai2),p[i][j].ai3);
		}
		cout << maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[12][12],sc[101],rsc,x=1,y=1;
bool cmp(int a,int b){return a>b;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++) cin >> sc[i];
	for(int i = 0;i < 12;i++) for(int j = 0;j < 12;j++) a[i][j]=-1;
	rsc=sc[1];
	sort(sc+1,sc+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
	{
		a[x][y]=sc[i];
		if(a[x+1][y]==-1 && x+1<=n) x++;
		else if(a[x-1][y]==-1 && x-1>=1) x--;
		else if(a[x][y+1]==-1 && y+1<=m) y++; 
	}
	for(int i = 0;i < 12;i++)
	{
		for(int j = 0;j < 12;j++)
		{
			if(a[i][j]==rsc)
			{
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

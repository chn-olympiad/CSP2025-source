#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[105],b[105],c[15][15];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i],b[i] = a[i];
	sort(b + 1,b + n * m + 1,cmp);
	int x = 1,y = 1;
	for(int i = 1;i <= n * m;i++)
	{
		c[x][y] = b[i];
		if(x % 2 == 1) y++;
		else y--;
		if(y > n) x++,y = n;
		if(y < 1) x++,y = 1;
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(c[i][j] == a[1]) 
			{
				cout << i << " " << j << "\n"; 
				return 0; 
			} 
		} 
	} 
	return 0; 
}

#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],bz,c,r,cnt = 0,que[105][105];
bool flag = true,book = false;
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	
	bz = a[1];
	sort(a+1,a+(n*m)+1);
	reverse(a+1,a+(n*m)+1);
	
	for(int i = 1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j = n;j>=1;j--)
			{
				que[i][j] = a[++cnt];
			}
		}
		else if(i%2==1)
		{
			for(int j = 1;j<=n;j++)
			{
				que[i][j] = a[++cnt];
			}
		}
	}
	for(int i = 1;i<=m;i++)
	{
		for(int j = 1;j<=n;j++)
		{
			if(que[i][j] == bz)
			{
				c = i;
				r = j;
				break;
			}
		}
	}
	cout << c << " " << r;
	return 0;
}

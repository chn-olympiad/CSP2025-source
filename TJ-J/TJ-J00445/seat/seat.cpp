#include <iostream>
#include <algorithm>
using namespace std;

struct seat
{
	int number;
	int score;
}a[220];	
bool cmp(seat x,seat y)
{
	return x.score>y.score;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i].score;
		a[i].number=i;
	}
//	2 2
//	99 100 97 98
//	100 99 98 97
//	2 1 4 3
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[n*(i-1)+j].number==1)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				if(a[n*(i-1)+j].number==1)
				{
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
short n,m,a[110],R;
bool cmp(short x,short y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	int tmp = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	int l = 1,r = n * m;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(a[mid] > tmp) l = mid + 1;
		else if(a[mid] < tmp) r = mid - 1;
		else
		{
			R = mid;
			break;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			R--;
			cout << R << " " << i << " " << j << " ";
			if(R == 0)
			{
				cout << i << " " << j;
				return 0;
			}
		}
		i++;
		for(int j = n;j >= 1;j--)
		{
			R--;
			cout << R << " " << i << " " << j << " ";
			if(R == 0)
			{
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}

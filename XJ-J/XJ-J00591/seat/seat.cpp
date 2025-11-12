#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,all[110],xa;
	cin >> n >> m;
	for (int i=0;i<n*m;i++)
	{
		cin >> all[i];
	}
	xa = all[0];
	sort(all+0,all+n*m,cmp);
	int pri = 0;
	int c=1,r=1;
	for (int i=0;i<n*m;i++)
	{
		if (all[i] == xa)
		{
			cout << c << " " << r;
			break;
		}
		if (c % 2 != 0)
		{
			r++;
			if (r == n+1){
				r = n;c++;
			}
		}
		else
		{
			r--;
			if (r == 0)
			{
				r = 1;c++;
			}
		}
	}
	return 0;
} 

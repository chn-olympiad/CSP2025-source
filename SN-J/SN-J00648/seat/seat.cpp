#include<bits/stdc++.h>
using namespace std;
int n, m, R;
int a[105],e;
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++)
	{
		if(a[i]==R)e=i;
	}
	int i=1;
	int j=1;
	int qwer = 1;
	while(1)
	{
		if(j%2==1)
		{
			if(qwer==e)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			qwer++;
			i++;
			if(i>=(n+1))
			{
				i--;
				j++;
			}
			
		}else
		{
			if(qwer==e)
			{
				cout<<j<<" "<<i;
				return 0;
			}
			qwer++;
			i--;
			if(i<=0)
			{
				i++;
				j++;
			}
			
		}
	}
 }


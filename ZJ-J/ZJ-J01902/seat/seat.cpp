#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=32;

int a[N][N],n,m,x,t;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> m >> n >> x;
	int cnt=0;
	for(int i=1;i<n*m;i++)
	{
		cin >> t;
		if(t>x) cnt++;
	}
	int x=1,y=1;
	for(int i=1;i<=cnt;i++)
	{
		if(x&1)
		{
			if(y==m) x++;
			else y++;
		}
		else
		{
			if(y==1) x++;
			else y--;
		}
	}
	cout << x << ' ' << y << '\n';
	return 0;
}

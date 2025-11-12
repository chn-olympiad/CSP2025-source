#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
int n,m,sum,a[666],b[666],pos,tmp = 1,xxx = 1,yyy = 1,fx = 1;
bool cmp(int x,int y)
{
	return x > y;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	sum = n * m;
	for1(1,sum,i)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1,b + 1 + sum,cmp);
	for1(1,sum,i) if(a[1] == b[i])
	{
		pos = i;
		break;
	}
	while(tmp != pos)
	{
		tmp++;
		if(fx == 1)
		{
			if(xxx + 1 <= n) xxx++;
			else yyy++,xxx = n,fx = 2;
		}
		else 
		{
			if(xxx - 1 > 0) xxx--;
			else yyy++,xxx = 1,fx = 1;
		}
	}
	cout << yyy << ' ' << xxx;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,b;
	a = 1;
	b = 1;
	cin >> n>>m;
	int o,cnt,p;
	cnt = 1;
	cin >> o;
	for(int i = 0;i < n*m-1;i++)
	{
		cin >> p;
		if(o<p)
			cnt++;
	}
	if(cnt<=n)
	{
		cout << 1<<" "<<cnt;
		return 0;
	}else if(cnt%n==0)
	{
		if((cnt/n)%2==0)
			cout << cnt/n<<" "<<1;
		else
		    cout << cnt/n<<" "<<n;
	}
	else
	{
		if(((cnt/n)+1)%2==0)
		{
			cout <<(cnt/n)+1<<" "<<n+1-(cnt%n);
			return 0;
		}else
		{
			cout <<(cnt/n)+1<<" "<<cnt%n;
			return 0;
		}
	}
	return 0;
}


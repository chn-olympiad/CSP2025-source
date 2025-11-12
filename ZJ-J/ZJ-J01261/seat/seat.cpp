#include<bits/stdc++.h>
using namespace std;
int x,a[101],n,m,t,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	x = a[1];sort(a + 1,a + n * m + 1,[](int x,int y){return (x > y);});
	for(int i = 1;i <= n * m;i++) if(a[i] == x)
	{
		x = i;
		break;
	}
	t = (x + n - 1) / n,k = x % n;
	if(t % 2 == 0)
	{
		k = n + 1 - k;
		if(k == n + 1) k = 1;
	}
	else if(k == 0) k = n;
	cout << t << " " << k << "\n";
}


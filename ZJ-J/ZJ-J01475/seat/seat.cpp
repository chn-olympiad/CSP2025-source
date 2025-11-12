#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int a[1005];

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int val;
	cin>>val;
	for(int i = 1;i <= n*m - 1;i++)
		cin>>a[i];
	sort(a + 1,a + n * m);
	if(a[n*m - 1] < val)
	{
		cout<<1<<" "<<1<<"\n";
		return 0;
	}
	
	int t;
	for(int i = 1;i <= n * m - 1;i++)
		if(a[i]>val)
		{
			t = i;
			break;
		}
	
	t = n * m - t + 1;
	
	
	
	int hang,lie;
	if(t % n == 0) lie = t / n;
	else lie = t/n + 1;
	

	if(lie % 2 == 0)
	{
		if(t % n == 0)hang = 1;
		else hang = n - t % n+1;
	}
	else 
	{
		if(t % n == 0) hang = n;
		else hang = t % n;
	}
	cout<<lie<<" "<<hang<<"\n";
	
	return 0;
}

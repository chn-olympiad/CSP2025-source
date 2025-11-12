#include <bits/stdc++.h>
using namespace std;
int n;
const int N=5000+33;
int ar[N], front[N];
int main ()
{
	ios::sync_with_stdio(false);
	cin. tie (0), cout. tie (0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>ar[i];
	sort(ar+1, ar+n+1);
	if (n==3 && ar[1]+ar[2]+ar[3]>ar[3]*2)
	{
		cout<<1; 
		return 0;
	}
	if (n<=3)
	{
		cout<<0;
		return 0;
	}
	else
	{
		int sum=0;
		for (int i=1; i<=n; i++)
			front[i]=front[i-1]+ar[i];
		for (int i=0; i<=n; i++)
			for (int j=i+3; j<=n; j++)
				if (front[j]-front[i]>ar[j]) sum++;
		cout<<sum;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef int itn;
typedef long long ll;
const itn N=110;
int a[N];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int xr=a[1],l;
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<=n*m;j++)
		{
			if(a[i]>a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xr) l=i;
	}
	int sl=floor((double)(l+n-1)/n);
	int hp;
	if(sl%2!=0)
	{
		hp=l%n;
		if(l%n==0)
		{
			hp=n;
		}
	}
	else 
	{
		hp=n-(l%n-1);
	}
	cout<<sl<<" "<<hp;
	return 0;
} 

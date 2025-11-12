#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{
		scanf("%d",&a[i]);
	}
	int k=a[1],id=-1;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(k==a[i])id=i;
	}
	int l=(id-1)/n+1,h;
	if(l%2==1)
	{
		h=(id-1)%n+1;
	}
	else
	{
		h=n-(id-1)%n;
	}
	printf("%d %d",l,h);
	return 0;
}
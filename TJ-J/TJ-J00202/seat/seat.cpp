#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int x,i;
}a[105];
bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].i=i;
	}
	int ple;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i].i==1)
			ple=i;
	for(int i=0;i<m;i++)
		if(ple>=i*n+1&&ple<=(i+1)*n)
		{
			if(i%2==1)
				cout<<i+1<<" "<<n-ple+i*n+1;
			else
				cout<<i+1<<" "<<ple-i*n;			
		}
	return 0;
}

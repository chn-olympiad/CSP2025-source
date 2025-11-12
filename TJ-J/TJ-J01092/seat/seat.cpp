#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a>b;
}
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
	int z=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==z)
		{
			int h=i%n;
			int l=ceil(i*1.0/n);
			if(l%2==0)cout<<l<<' '<<n-h+1;
			else cout<<l<<' '<<h;
			return 0;
		}
	}
	}

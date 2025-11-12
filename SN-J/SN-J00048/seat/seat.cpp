#include<bits/stdc++.h>
using namespace std;
int n,m,a[500],cnt,e;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	e=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==e)
		{
			int lie=i/n;
			if(lie==0)lie++;
			if(i%n!=0)lie++;
			int hang=i-(lie-1)*n;
			if(lie%2==0)hang=n-hang+1;
			cout<<lie<<' '<<hang;
		}
	}
	return 0;
}

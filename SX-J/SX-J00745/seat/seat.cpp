#include<bits/stdc++.h>
using namespace std;
long long a[1000],aaa,n,m,id,aa,bb;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>aaa;
	a[0]=aaa;
	for(int i=1;i<n*m;i++)cin>>a[i];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==aaa)
		{
			id=i+1;
			break;
		}
	}
	if(id%n==0)aa=id/n;
	else aa=id/n+1;
	if(aa%2==1)bb=id-(aa-1)*n;
	else bb=(id-(aa-1)*n)+(n-(id-(aa-1)*n));
	cout<<aa<<' '<<bb;
	return 0;
}
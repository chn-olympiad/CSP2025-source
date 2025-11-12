#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[101],rs,rn,c,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	rs=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==rs)
		{
			rn=i;
			break;
		}
	}
	c=rn/n+1,r=rn%n;
	if(r==0) r=m;
	if(c%2==0) r=m-r+1;
	cout<<c<<' '<<r;
}

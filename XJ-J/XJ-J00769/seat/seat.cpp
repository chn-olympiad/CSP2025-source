#include<bits/stdc++.h>
using namespace std;
long long int n,m,r,c,v,s,i,a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>a[i];
	v=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==v)
		{	
			s=i;
			break;
		}
	}
	if(s>m)
	c=1+s/m;
	else
	c=1;
	if(s>m&&c%2==0)
	r=m-s%m+1;
	else
	r=s%m;
	if(c<=n&&r<=m)
	cout<<c<<" "<<r;
	return 0;
}

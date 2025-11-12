#include<bits/stdc++.h>
using namespace std;
int a[101],s[101];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,num,r,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		s[i]=i;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(s[i]==1)
		{
			num=i;
			break;
		}
	c=(num-1)/n+1;
	if(c%2==1)
		r=num-(c-1)*n;
	else
		r=c*n-num+1;
	cout<<c<<" "<<r;
	return 0;
}

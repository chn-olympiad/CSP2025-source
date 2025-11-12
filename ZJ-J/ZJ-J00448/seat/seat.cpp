#include <bits/stdc++.h>
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
	int n,m,i,j,t;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	int w=0;
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++)
		if(a[i]==t)
		{
			w=i;
			break;
		}
	int h,l;
	l=ceil(1.0*w/n);
	if(l%2==0)
	{
		h=n-(w%n)+1;
	}
	else
	{
		h=w%n;
		if(h==0)
			h=n;
	}
	cout<<l<<" "<<h<<endl;
	return 0;
}

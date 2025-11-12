#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,x;
}a[110];
bool cmp(node A,node B)
{
	return A.x>B.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int r=0,f=1;
	for(int i=1;i<=n*m;i++)
	{
		r+=f;
		if(r==n+1)
		{
			r=n;
			f=-1;
		}
		else if(r==0)
		{
			r=1;
			f=1;
		}
//		cout<<r<<"\n";
		if(a[i].id==1)
		{
			int c=ceil(1.0*i/n);
			cout<<c<<" "<<r;
			break;
		}
	}
	return 0;
}

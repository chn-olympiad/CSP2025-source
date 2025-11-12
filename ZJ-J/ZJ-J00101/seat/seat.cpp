#include<bits/stdc++.h>
using namespace std;
int n,m,a[10006];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int w=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m/2;i++)
	swap(a[i],a[n*m-i+1]);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==w)
		{
		w=i;
			break;
		}
		
	}
	int y=0,x=1;
	while(w)
	{
		if(x%2==1)
		{
			y=y+1;
			w=w-1;
			if(y>n)
			{
				x=x+1;y=y-1;
			}
		}
		else
		{
			y=y-1;
			w=w-1;
			if(y<1)
			{
				x=x+1;y=y+1;
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}

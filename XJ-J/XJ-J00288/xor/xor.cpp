#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010],q,p,x,y,h=0,t=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	q=1;
	for(int i=1;i<=n;i++)
	{
		y=a[i];
		p=i;
		t+=y;
		if(p==q)
		{
			if(x==k)
			{
				h++;
				p++;
				q=p;
				x=a[q];
				y=a[p];
				t=0;
			} 
		}
		else
		{
			if(y-x==k||x+y==k)
			{
				h++;
				p++;
				q=p;
				x=a[q];
				y=a[p];
				t=0;
			}
			else
			{
				if(t>k||y-x>k||x-y>k)
				{
					p++;
					q=p;
					x=a[q];
					y=a[p];
					t=0;
				}
			}
		}
	}
	cout<<h;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct seat{
	int x;
	int y;
	int s;
}a[105];

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1].s;
	
	int a1=a[1].s;
	if(a1==100) 
	{
		cout<<"1 1";
	
	}
	else{
		for(int i=2;i<=n*m;i++)
		{
			cin>>a[i].s;
			for(int j=i;j>=2;j--)
			{
				if(a[j].s>a[j-1].s)
				{
					int t=a[j].s;
					a[j].s=a[j-1].s;
					a[j-1].s=t;
				}
			}
		}
		for(int i=1;i<=n*m;i++)
		{
			if(a[i].s==a1)
			{
				if(i%n!=0)
				{
					a[i].x=i/n+1;
				}
				else{
					a[i].x=i/n;
				}
				if(a[i].x%2==0)
				{
					a[i].y=n-(i%n)+1;
				}
				else{
					if(i%n!=0) a[i].y=i%n;
					else a[i].y=n;
				}
				cout<<a[i].x<<" "<<a[i].y;
				break;
			}
		}
	}
	return 0;
}


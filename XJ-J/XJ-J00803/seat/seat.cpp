#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,p,w=1,e;
int op(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+m*n+1,op);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			break;
		}
		w++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				e++;
				if(w==e)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				e++;
				if(w==e)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
 } 

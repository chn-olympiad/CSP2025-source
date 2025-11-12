#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num,id;
}a[105];
bool cmp(node x,node y)
{
	return x.num>y.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			int y,x;
			if(i%n==0)
			{
				y=i/n;
			}
			else
			{
				y=i/n+1;
			}
			if(y%2==0)
			{
				if(i%n==0)
				{
					x=1;
				}
				else
				{
					x=n-(i%n)+1;
				}
			}
			else if(y%2==1)
			{
				if(i%n==0)
				{
					x=n;
				}
				else
				{
					x=i%n;
				}
			}
			cout<<y<<" "<<x<<endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,num,x;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==num)
		{
			if(i%n==0)
			{
				cout<<i/n<<" ";
				cout<<n;
				return 0;
			}
			else
			{
				cout<<i/n+1<<" ";
				x=i/n;
				cout<<i-(x*n);
				return 0;
			}
			
		}
	}
	return 0;
}

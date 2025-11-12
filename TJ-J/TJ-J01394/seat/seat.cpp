#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b)
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
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			if(i%n>0)
			{
				cout<<i/n+1<<" ";
				if((i/n+1)%2!=0)
				{
					cout<<i%n;
				}
				else
				{
					cout<<n-i%n+1;
				 } 
			}
			else
			{
				cout<<i/n<<" ";
				if((i/n)%2!=0)
				{
					cout<<n;
				}
				else
				{
					cout<<1;
				 } 
			}
			
		}
	}
	return 0;
 } 

#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1005],t,sum;
bool cmp(int z,int y)
{
	if(y<z) return z>y;
	else return y<z;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i])
		{
			sum=i;
		}
	}
	if(((sum+n-1)/n)%2==1)
	{
		if(sum%n==0)
		{
			cout<<(sum+n-1)/n<<" "<<n;
		}
		else
		{
			cout<<(sum+n-1)/n<<" "<<sum%n;
		}
	}
	else if(((sum+n-1)/n)%2==0)
	{
		if(sum%n==0)
		{
			cout<<(sum+n-1)/n<<" "<<1;
		}
		else
		{
			cout<<(sum+n-1)/n<<" "<<n-sum%n+1;
		}
	}
	return 0;
}

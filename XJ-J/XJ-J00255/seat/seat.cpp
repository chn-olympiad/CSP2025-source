#include<iostream> 
using namespace std;
int main()
{ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
int n,m,t,a[1000]={0},shu;
cin>>n>>m;
for(int i=1;i<=n*m;i++)
{
	cin>>a[i];
}
int k=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i;j<=n*m;j++)
		{
			if(a[j]>a[i])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			shu=i;
			break;
		}
	}
	if(shu%n!=0)
	{
		cout<<shu/n+1<<" ";
		if(shu/n==0||shu/n%2==0)
		{
			cout<<shu%n;
		}
		if(shu/n%2==1)
		{
			cout<<n-shu%n+1;
		}
	}
	if(shu%n==0)
	{
		cout<<shu/n<<" ";
		if(shu/n==0||shu/n%2==0)
		{
			cout<<1;
		}
		if(shu/n%2==1)
		{
			cout<<n;
		}
	}
	return 0;
}

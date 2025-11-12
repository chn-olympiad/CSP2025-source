#include<bits/stdc++.h>
using namespace std;
int a[10001];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,flag;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==x)
		{
			flag=i; 
		}
	}
	if(flag%n==0)
	{
		cout<<flag/n<<" "<<n<<endl;
		return 0;
	}
	else if((flag/n)%2==0)
	{
		cout<<flag/n+1<<" "<<flag%n<<endl;
		return 0;
	}
	else if((flag/n)%2==1)
	{
		cout<<flag/n+1<<" "<<n-flag%n+1<<endl;
		return 0;
	}
}

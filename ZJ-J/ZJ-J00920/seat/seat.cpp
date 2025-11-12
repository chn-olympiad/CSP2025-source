#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],k,p;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	cin>>n>>m;
	freopen("seat.out","w",stdout);
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
			p=i;
			break;
		}
	}
	if(p%n==0)
	{
		if((p/n)%2==0)
		cout<<p/n<<" "<<1;
		else
		cout<<p/n<<" "<<n;	
	}
	else
	{
		if((p/n+1)%2==0)
		cout<<p/n+1<<" "<<n-p%n+1;
		else
		cout<<p/n+1<<" "<<p%n;
	}				
	fclose(stdin);
	fclose(stdout);
	return 0;
}
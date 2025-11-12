#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(x==a[i])
		{
			if(i%2==0)   
			    cout<<i/n<<" "<<i%n+1;
			else
			    cout<<i/n+1<<" "<<i%n;
			return 0;
		}
    }
	return 0;
}

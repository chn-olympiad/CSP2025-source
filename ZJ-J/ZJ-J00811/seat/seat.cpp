#include<bits/stdc++.h>
using namespace std;
const int slen=1e6+10;
int a[slen];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pm=0,r=0;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			r=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{	
		if(a[i]==r)
		{
			if(i<=n)
			{
				cout<<1<<" "<<i;
				return 0;
			}
			if((i/n+1)%2==0||i%n==0)
			{
				if(i/n==0)
					cout<<1<<" ";
				else
				{
					if(i%n==0)
						cout<<i/n<<" ";
					else
						cout<<i/n+1<<" ";
				}
					
				if(i%n==0)
					cout<<1;
				else
					cout<<n-i%n+1;
			}
			else
			{
				if(i/n==0)
					cout<<1<<" ";
				else
					cout<<i/n+1<<" ";
				if(i%n==0)
					cout<<n;
				else
					cout<<i%n;
			}
			return 0;
		}
	}
	return 0;
}
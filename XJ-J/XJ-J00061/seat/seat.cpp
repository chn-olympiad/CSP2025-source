#include<bits/stdc++.h>
using namespace std;
long long int a[250],n,m,i,r;
int main()
{
	//freopen("seat.in",stdin);
	//freopen("seat.out",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m);
	for(i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			if(i<n)
			{
				cout<<i<<" "<<(i/n+1);
				return 0;
			}
			
			
			if(i%n==0&&(i/n)%2==0)
			{
				cout<<1<<" "<<i/n;
				return 0;
			}
		
			if(i%n==0&&(i/n)%2!=0)
			{
				cout<<n<<" "<<i/n;
				return 0;
			}
			
			
			if(i%n>1)
			{
				cout<<n-(i%n)<<" "<<(i/n)+1;
				return 0;
			}
			
			
			if(i%n==1)
			{
				if((i/n+1)%2)
				cout<<n<<" "<<(i/n)+1;
				else
				cout<<1<<" "<<(i/n)+1;
				return 0;
			}
			
		}
	}
}

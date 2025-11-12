#include<bits/stdc++.h>
using namespace std;
int s,sum=1;
int c,r;
    
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m>>R;
	for(int i=1;i<n*m;i++)
	{
		s=0;
		cin>>s;
		if(s>R)
		{
			sum++;
		}
	}
	int t=sum/n;
	if(sum%n!=0)
	{
		if(t%2==0){
			r=sum%n;
		}
		else
		{
			r=n-sum%n;
		}
	}
	
	if(t%2==0)
	{
		r=1;
	}
	else
	{
		r=n;
	}
	if(sum%n==0)
	{
		c=t;
	}
	else
	{
		c=t+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

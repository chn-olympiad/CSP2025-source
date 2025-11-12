#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,k,a[10005],x,t=0,s;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m);
	for(i=m*n;i>=1;i--)
	{
		t++;
		if(a[i]==x)
		{
			s=t;
			break;
		}
	}
	if(s%n!=0)
	{
		cout<<s/n+1<<" ";
		if((s/n+1)%2==1)
		cout<<s%n;
		else
		cout<<n-(s%n)+1;
	}
	

	
	if(s%n==0)
	{
		cout<<s/n<<" ";
		if((s/n)%2==1)
		cout<<n;
		else
		cout<<1;
	}
	
	
	
	return 0;
 } 

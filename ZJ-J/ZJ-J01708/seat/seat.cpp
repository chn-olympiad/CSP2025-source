#include<iostream>
using namespace std;
int n,m;
int a[100000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int R=a[1];
	for(int i=1;i<=n*m-1;i++)
	{
		if(a[i]<a[i+1])
		{
			swap(a[i],a[i+1]);
		}
	}
	int num;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			num=i;
		}
	}
	int c=1,r;
	if(num%n==0)
	{
		c=num/n;
		if(c%2==0)
		{
			r=1;
		}
		else
		{
			r=n;
		}
	}
	else
	{
		c+=num/n;
	    if(c%2==0)
	    {
		   r=(m+1)-(num%n);
	    }
	    else
	    {
		r=num%n;
	    }
	}
	cout<<c<<" "<<r;
	return 0;
}
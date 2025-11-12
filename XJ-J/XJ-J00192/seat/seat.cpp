#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout); 
	int n,m,num,c,r;
	int a[105];
	cin>>n>>m;
	int k=n*m;
	for(int i=0;i<=k-1;i++)
	{
		cin>>a[i];
		num=a[0];
	}
    for(int i=k-1;i>=0;i--)
	{
		sort(a,a+i+1);
		if(a[i]==num)
		{
		    num=i;	
		}	
	}
	c=num%m+1;
	r=num/n+1;
	cout<<c<<' '<<r;
	return 0;
}

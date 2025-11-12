#include<iostream>
using namespace std;
int a[5005];
int main()
{
	frepen("polygon.in","r",stdin);
	frepen("polygon.out","w",stdout);
	int n,i,j,s=0,t=1,b,z,max,d;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]; 
	} 
	for(i=1;i<=n-1;i++)
	{
		for(j=2;j<=n-1;j++)
		{
			b=a[i]+a[j];
			z=j+1;
			while(z!=n+1)
			{
			    d=b+a[z];
			    max=a[z]*2;
			    if(b+a[z]>a[z]*2)
			    {
			    	t++;
				}
				z++;
			}
		}
	} 
	cout<<t;
	return 0;
}

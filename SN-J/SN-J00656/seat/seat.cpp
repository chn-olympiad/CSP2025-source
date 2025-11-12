#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c,r,m,n,a[100],max=0,p=1;
	cin>>m>>n;
	for(int i=0;i<n*m;i++)
	{
	cin>>a[i];
	}
		for(int i=0;i<n*m;i++)
	{
	if(a[0]<a[i]) 
	p++;
	}
//	cout<<p<<" ";
	c=p/n+p%n;
	if(c%2==0)
	r=m+1-p%n;
	else if(c%2==0&&p%n==0) r=1;
	else if(c%2!=0&&p%n==0) r=n;
	else r=p%n;
	cout<<c<<" "<<r; 
		
	
	return 0;
}
//	for(int i=0;i<n*m;i++)
//	{
//		cout<<b[i];
//	}

//	for(int i=0;i<n*m;i++)
//	{
//		for(int j=0;j<n*m;j++)
//		{
//			if(a[j]>max)
//			{
//				max=a[j];
//				
//			}
//		                                                                                    
//			
//		}
//		b[i]=max;
////		cout<<",,"<<max<<",,";
//		max=0;
//	

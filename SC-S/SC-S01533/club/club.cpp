#include<iostream>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int t=0,n=0;
	cin>>t;
	int z[100]={};
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int a[3][n];
		int mx[3]={n/2,n/2,n/2},mn[3]={0};
		for(int l=0;l<n;l++)
		{
			cin>>a[0][l]>>a[1][l]>>a[2][l]; 
		}
		//********
		for(int f=0;f<n;f++)
		{
		if(a[0][f]>a[1][f]&&a[0][f]>a[2][f])
		{
			z[i]=z[i]+a[0][f];
			mx[0]--;
			if(a[0][f]<=mn[0])
			mn[0]=a[0][f];
			//cout<<z[i]<<" "<<0<<endl;
		}
		else
		if(a[1][f]>a[0][f]&&a[1][f]>a[2][f])
		{
			z[i]=z[i]+a[1][f];
			mx[0]--;
			if(a[1][f]<=mn[1])
			mn[1]=a[1][f];
			//cout<<z[i]<<" "<<1<<endl;
		}
		else
		if(a[2][f]>a[1][f]&&a[2][f]>a[0][f])
		{
			z[i]=z[i]+a[2][f];
			mx[0]--;
			if(a[2][f]<=mn[2])
			mn[2]=a[2][f];
			//cout<<z[i]<<" "<<2<<endl;
		}
		 } 	
	}
	for(int i=0;i<t;i++)
	cout<<z[i]<<endl;
 } 
#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[3][10010];
int x[3];
int k[10010];
int ans,s;
int cha;
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	for(int i=1;i<=3;i++)
	{
		x[i]=0;
	}
	cin >>t;int m=t/2;
	for(int i=1;i<=t;i++)
	{
		cin >>n;
	
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=3;l++)
			{
				cin >>a[l][j];
			}	
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<=3;l++)
			{
			    if(a[l][j]>ans)
			    {
			    	ans=a[l][j];
			    	k[j]=l;
				}
			
			}
			
			s+=ans;
			ans=0;	
			
		}
	
		cout <<s<<endl;
		s=0;
	}
	return 0;
}

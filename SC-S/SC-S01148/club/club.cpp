#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int ans;
int a[100000][2] ={0,0,0};
int main ()
{
     freopen("club.in","r",stdin);
     freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]<a[i][j+1])
			{
				swap(a[i][j],a[i][j+1]);
			}
		}
	}
	ans=0;
	ans=ans+a[i][0];
	cout <<ans;
	
	return 0 ;
}
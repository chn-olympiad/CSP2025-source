//不考虑是否超过n/2的情况的程序 
#include<bits/stdc++.h>
using namespace std;
int a[5][10001][4]; 
int ans[5][10001]; 
int maxx[100001];
int f[10001][4];        
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,c=0;
	cin>>t;
	cin>>n;
    for (int k=1;k<=t;k++)//列组
	{
		for (int i=1;i<=n;i++)//第k组第i个人 
		{
			cin>>a[k][i][1];
			cin>>a[k][i][2];
			cin>>a[k][i][3];
		    maxx[i]=max(a[k][i][2],a[k][i][1]);
		    maxx[i]=max(maxx[i],a[k][i][3]);
				c+=maxx[i];
			}
			cout<<c<<endl;
			c=0;
				
			}
			
		 

			return 0;
		 } 
		 
	
		 
		 
		
			 
	


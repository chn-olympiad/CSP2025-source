#include<bits/stdc++.h>
using namespace std;
int i,j,n,m,t,q,s,s1,a[100005][10],maxn;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int v[10]={0};
		
		cin>>n;
		m=n/2;
		for(i=1;i<=n;i++)
		for(j=1;j<=3;j++)
		{
			cin>>a[i][j];	
		}
		
		
        s=0;
		for(i=1;i<=n;i++)
		{
		    
			maxn=0;
			if(maxn<a[i][1])
			{
				
			    s1=1;
			}
			else
			if(maxn<a[i][2])
			{

				s1=2;
			}
			else
		    if(maxn<a[i][3])
			{

				s1=3;
			}
			s+=maxn;
			v[s1]++;

		}
		cout<<s;
	}
	return 0;
}


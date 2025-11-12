#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
const int N=1e5+5;
int t,n;
int stu[N][4];
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
        int flag1=0;
        int flag2=0;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>stu[i][1]>>stu[i][2]>>stu[i][3];
			a[i]=stu[i][1];
			if(stu[i][2]!=0)
			{
				flag1=1;
			}
			if(stu[i][3]!=0)
			{
				flag2=1;
			}
		}
		
		if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==j)
					{
						continue;
					}
					ans=max(ans,(stu[1][i]+stu[2][j]));
				}				
			}
		}
		
				if(flag1==0&&flag2==0)
				{
					sort(a+1,a+n+1,cmp);
					for(int i=1;i<=(n/2);i++)
					{
						ans+=a[i];
					}
				}
				
		cout<<ans<<endl;				
		}
}


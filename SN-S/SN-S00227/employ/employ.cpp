#include<bits/stdc++.h>
using namespace std;
int a1[300030],a2[300030],a3[300030];
int b1[300030],b2[300030],b3[300030];
int dp[1001000];
int t,n;
int f(int a,int b,int c)
{
	if(max(max(a,b),c)==a) return 1;
	if(max(max(a,b),c)==b) return 2;
	if(max(max(a,b),c)==c) return 3;
}
int main()
{
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int sum=0,sum1=0,sum2=0,sum3=0,c[100100],d1,d2;
	int x1=0,x2=0,x3=0;
	//cin>>t;
	//for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a1[j]>>a2[j]>>a3[j];
		}	
	}
//	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]=f(a1[j],a2[j],a3[j]);	
			if(c[j]==1) 
			{
				b1[j]=a1[j];
				sum1=a1[j]+sum1;
				x1++;	
			}
			if(c[j]==2) 
			{
				b2[j]=a2[j];
				sum2=a2[j]+sum2;
				x2++;
			}
			if(c[j]==3) 
			{
				b3[j]=a3[j];
				sum3=a3[j]+sum3;	
				x3++;
			}
		}	
		d1=max(max(x1,x2),x3);
		
		if(d1<=n/2) sum=sum1+sum2+sum3;
	
		cout<<sum<<endl;
		
		
	}
		
	
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0
*/

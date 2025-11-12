#include<bits/stdc++.h>
using namespace std;
int t;		
int n;
int a[10000][3],w[10000],c[1000],an[1000],s;
//bool ans()
//{
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=3;j++)
//			an[j]+=;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(an[i>n/2])
//			return false;
//	}
//	return true;
//}
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{

		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		for(int k=1;k<=n;k++)
		{
			for(int m=1;m<=3;m++)
			{
				if(w[k-1]+a[k][m]>=w[k])
				{
					w[k]=w[k-1]+a[k][m];
					s=m;
				}
			}
			c[s]++;
			if(c[s]>n/2)
			{
				c[s]--;
				
			}
		}
		cout<<w[n]<<endl;
		for(int i=1;i<=n;i++)
		{
			w[i]=0;
			c[i]=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
	return 0;
} 
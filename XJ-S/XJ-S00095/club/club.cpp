#include<bits/stdc++.h>
using namespace std;
int n,sum=0,ans=0,t,maxa=-1,a1,a2,a3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t!=0)
	{
		cin>>n;
		int a[10005][5]={},b[5]={}/*一列用了几个*/,c[10005]={},d[10005]={}/*最大值下标*/;
		ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<t;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			sum=0;
			for(int j=0;j<t;j++)
			{
				if(a[i][j]>sum) 
				{
					sum=a[i][j];
					c[i]=j;
				}
			}
			ans+=sum;
		}
		cout<<ans<<endl;
		t--;
	}
	fclose(stdin);
	fclose(stdout);
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

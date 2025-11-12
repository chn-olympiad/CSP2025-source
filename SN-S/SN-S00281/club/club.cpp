#include <bits/stdc++.h>
using namespace std;
int t,n,a[10010][4],m1,m2,m3;
bool has()
{
	for(int i=0;i<n;i++)
		if(a[i][4]==0)return 1;
	return 0;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			a[i][4]=0;
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[m1][0])m1=i;
			if(a[i][1]>a[m2][1])m2=i;
			if(a[i][2]>a[m3][2])m3=i;
		}
		a[m1][4]=1;a[m2][4]=2;a[m3][4]=3;
		m1=0,m2=0,m3=0;
		while(has())
		{
			for(int i=0;i<n;i++)
			{
				if(a[i][0]>a[m1][0]&&!a[i][4])m1=i;
				if(a[i][1]>a[m2][1]&&!a[i][4])m2=i;
				if(a[i][2]>a[m3][2]&&!a[i][4])m3=i;
			}
			if(m1==m2&&m2==m3)
			{
				if(a[m1][4]>a[m2][4]&&a[m1][4]>a[m3][4])a[m1][4]=1;
				if(a[m2][4]>a[m1][4]&&a[m1][4]>a[m3][4])a[m1][4]=2;
				if(a[m3][4]>a[m2][4]&&a[m2][4]>a[m1][4])a[m1][4]=3;
			}
			else a[m1][4]=1,a[m2][4]=2,a[m3][4]=3;
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			ans+=a[i][a[i][4]-1];
		}
		cout<<ans;
	}
}

/*1
4
4 2 1
3 2 4
5 3 4
3 5 1*/


#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],m[100005],k[4];
int asd(int i,int x)
{
	if(k[x]<n/2&&x<3&&i<n)
	{
		m[i]=max(m[i-1]+a[i][x],asd(i,x+1));
		k[i]++;
		asd(i+1,1);
	}
	else if(x<3&&i<n)
	{
		asd(i,x+1);
	}
	else if(i<n)
	{
		return m[i-1]+a[i][3];
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		int k[4]={0,0,0,0};
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		asd(1,1);
		cout<<m[n-1]<<endl;
	}
	return 0;
}
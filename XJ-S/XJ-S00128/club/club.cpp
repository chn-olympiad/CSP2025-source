#include<bits/stdc++.h>
using namespace std;
int a[100005][5],b[100005],d[5],ans[100005],l[10];
int main()
{
	int n,i,j,t,m,k,c;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		for(i=1;i<=3;i++)
		d[i]=0;
		cin>>n;
		m=n/2;
		for(i=1;i<=n;i++)
		for(j=1;j<=3;j++)
		cin>>a[i][j];
		
		if(n==2)
		{
		l[0]=a[1][1]+a[2][2];
		l[1]=a[1][1]+a[2][3];
		l[2]=a[1][2]+a[2][1];
		l[3]=a[1][2]+a[2][3];
		l[4]=a[1][3]+a[2][1];
		l[5]=a[1][3]+a[2][2];
		for(i=0;i<6;i++)
		{
			if(ans[1]<l[i])
			ans[k]=l[i];
		}

		}
		if(n!=2)
		{
			for(i=1;i<=n;i++)
		{
		for(j=1;j<=3;j++)
		{
			if(b[i]<a[i][j])
			{
				b[i]=a[i][j];
			}
		}ans[k]+=b[i];
		}
	 }
	}for(i=1;i<=t;i++)
	cout<<ans[i]<<endl;
	return 0; 
}

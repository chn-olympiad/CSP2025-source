#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int c[10005];
bool cmp(int x,int y)
{
	return x>y;
}
int max2(int x,int y,int z)
{
	int max3=max(x,y);
	int max4=max(x,z);
	if(max3>=max4)
	{
		return max3;
	}
	else
	{
		return max4;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("clud.out","w",stdout);
	int T,i,j,k,cnt=0,ans=0,sum=0,s=0;
	cin>>T;
	while(T--)
	{
		int n,max1[10005]={0};
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+1+n,cmp);
		for(i=1;i<=n;i++)
		{
			max1[i]=max2(a[i],b[i],c[i]);
			cout<<max1[i]<<endl;
			if(max1[i]==a[i])
			{
				cnt++;
			}
			else if(max1[i]==b[i])
			{
				ans++;
			}
			else if(max1[i]==c[i])
			{
				sum++;
			}
			if(cnt>=n/2)
			{
				for(j=1;j<=n;j++)
				{
					a[j]=0;
				}
			}
			else if(ans>=n/2)
			{
				for(j=1;j<=n;j++)
				{
					b[j]=0;
				}
			}
			else if(sum>=n/2)
			{
				for(j=1;j<=n;j++)
				{
					c[j]=0;
				}
			}
		}
		for(int m=1;m<=n;m++)
		{
			s=s+max1[m];
		}
		cout<<s;
	 } 
	return 0;
 } 

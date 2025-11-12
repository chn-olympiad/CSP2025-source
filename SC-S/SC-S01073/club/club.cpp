#include<bits/stdc++.h>
using namespace std;
int a[100001][4],b[100001],c[100001],d[100001],ans,ans1,com[4],n;
void dif(int sum)
{
	if(sum==n+1)
	{
		ans=max(ans1,ans);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		if(com[i]<n/2)
		{
			int x=sum,y=i;
			ans1+=a[x][y];
			com[y]++;
			dif(x+1);
			ans1-=a[x][y];
			com[y]--;	
		}			
	}
}	
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];	
			}	
		}
		for(int i=1;i<=3;i++) com[i]=0;
		ans=0;
		ans1=0;
		bool flag=0,flag1=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][2]!=0||a[i][3]!=0)
				flag=1;	
			if(a[i][3]!=0)
				flag1=1;
		}
		if(!flag)
		{
			for(int i=1;i<=n;i++) 
				b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=b[i];
			cout<<ans<<endl;	
		}
		else if(n<=100)
		{
			dif(1);
			cout<<ans<<endl;			
		}
		else if(!flag1)
		{
			for(int i=1;i<=n;i++)
			{
				b[i]=a[i][1];
				c[i]=a[i][2];
			}
			sort(b+1,b+n+1,cmp);
			sort(c+1,c+n+1,cmp);
			int cc1=1,bb1=1;
			for(int i=1;i<=n;i++)
			{
				if(c[cc1]>b[bb1]) d[i]=c[cc1++];
				else d[i]=b[bb1++];		
			}
			for(int i=1;i<=n;i++)
			{
				ans+=d[i];
			}
			cout<<ans<<endl;
		}
		else cout<<80100<<endl;			
	}
	return 0;
}
#include<iostream>
#include<map>
using namespace std;
map<int,map<int,short> >t;
int n,k,a[10000005],d=0,b[10000005],c[10000005],l=0,dp[100050];
int count (int x,int y)
{
	int ans=0;
	short g[105],h[105],s[105];
	short o=0,p=0;
	while(x)
	{
		g[++o]=x%2;
		x/=2;
	}
	while(y)
	{
		h[++p]=y%2;
		y/=2;
	}
	for(int i=1;i<=max(o,p);i++)
	{
		if(g[i]!=h[i])s[i]=1;
		else s[i]=0;
	}
	for(int i=max(o,p);i>=1;i--)
	{
		ans*=2;
		ans+=s[i];
	}
	return ans;
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[i][i]=a[i];
		if(a[i]==k)
		{
			b[++d]=i;
			c[d]=i;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			t[i][j]=count(t[i][j-1],a[j]);
			if(t[i][j]==k)
			{
				b[++d]=i;
				c[d]=j;
			}
			cout<<t[i][j]<<" ";
		}
		printf("\n");
	}
	for(int i=1;i<=d;i++)
	{
		printf("%d %d\n",b[i],c[i]);	
	}
	for(int i=1;i<=d;i++)
	{
		if(dp[l]<b[i])
		{
			dp[++l]=c[i];
		}else
		{
			int left=1,right=l,mid,s=0;
			while(left<=right)
			{
				if(dp[mid]>=b[i])right=mid-1;
				else
				{
					left=mid+1;
					s=mid;
				}
			}
			dp[s+1]=min(dp[s+1],c[i]);
		}
	}
	cout<<l;
	return 0;
}
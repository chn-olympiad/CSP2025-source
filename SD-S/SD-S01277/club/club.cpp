#include <bits/stdc++.h>
using namespace std;
int const maxn=1e5+1;
long long ans=0;
int n=0,t=0,p=0,x=0,cnt=0,aa=0,bb=0,cc=0,a[maxn],b[maxn],c[maxn],s[maxn][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(s,0,sizeof(s));
		cin>>n;
		p=n/2,aa=0,bb=0,cc=0,cnt=0,ans=0;
		for(int i=1;i<=n;i++)
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		if(n==100000)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(s[i][1]<s[j][1])
					{
						int z=s[i][1];
						s[i][1]=s[j][1];
						s[j][1]=z;
					}
				}
			}
			for(int i=1;i<=p;i++)
				ans+=s[i][1];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3])
			{
				aa++;
				a[aa]=i;
				s[i][0]=1;
				if(aa>p)
				{
					aa=p,x=0,cnt=0;
					int l=0;
					for(int j=1;j<=p;j++)
					{
						if(bb<p&&s[a[j]][2]+s[i][1]-s[a[j]][1]>x)
						{
							cnt=2;
							x=s[a[j]][2]+s[i][1]-s[a[j]][1];
							l=j;
						}
						if(cc<p&&s[a[j]][3]+s[i][1]-s[a[j]][1]>x)
						{
							cnt=3;
							x=s[a[j]][3]+s[i][1]-s[a[j]][1];
							l=j;
						}
					}
					if(cnt==2)
					{
						s[a[l]][0]=2;
						bb++;
						s[i][0]=1;
						a[l]=i;
					}
					else if(cnt==3)
					{
						s[a[l]][0]=3;
						cc++;
						s[i][0]=1;
						a[l]=i;
					}
					else 
					{
						if(bb<p&&s[i][2]>s[i][3])
						{
							s[i][0]=2;
							bb++;
						}
						else
						{
							s[i][0]=3;
							cc++;
						}
					}
				}
			}
			else if(s[i][2]>=s[i][1]&&s[i][2]>=s[i][3])
			{
				bb++;
				b[bb]=i;
				s[i][0]=2;
				if(bb>p)
				{
					bb=p,x=0,cnt=0;
					int l=0;
					for(int j=1;j<=p;j++)
					{
						if(aa<p&&s[b[j]][1]+s[i][2]-s[b[j]][2]>x)
						{
							cnt=1;
							x=s[b[j]][1]+s[i][2]-s[b[j]][2];
							l=j;
						}
						if(cc<p&&s[b[j]][3]+s[i][2]-s[b[j]][2]>x)
						{
							cnt=3;
							x=s[b[j]][3]+s[i][2]-s[b[j]][2];
							l=j;
						}
					}
					if(cnt==1)
					{
						s[b[l]][0]=1;
						aa++;
						s[i][0]=2;
						b[l]=i;
					}
					else if(cnt==3)
					{
						s[b[l]][0]=3;
						cc++;
						s[i][0]=2;
						b[l]=i;
					}
					else 
					{
						if(aa<p&&s[i][1]>s[i][3])
						{
							s[i][0]=1;
							aa++;
						}
						else
						{
							s[i][0]=3;
							cc++;
						}
					}
				}
			}
			else
			{
				cc++;
				c[cc]=i;
				s[i][0]=3;
				if(cc>p)
				{
					cc=p,x=0,cnt=0;
					int l=0;
					for(int j=1;j<=p;j++)
					{
						if(aa<p&&s[c[j]][1]+s[i][3]-s[c[j]][3]>x)
						{
							cnt=1;
							x=s[c[j]][1]+s[i][3]-s[c[j]][3];
							l=j;
						}
						if(bb<p&&s[b[j]][2]+s[i][3]-s[b[j]][2]>x)
						{
							cnt=2;
							x=s[b[j]][2]+s[i][3]-s[b[j]][2];
							l=j;
						}
					}
					if(cnt==1)
					{
						s[c[l]][0]=1;
						aa++;
						s[i][0]=3;
						c[l]=i;
					}
					else if(cnt==2)
					{
						s[c[l]][0]=2;
						bb++;
						s[i][0]=3;
						c[l]=i;
					}
					else 
					{
						if(aa<p&&s[i][1]>s[i][2])
						{
							s[i][0]=1;
							aa++;
						}
						else
						{
							s[i][0]=2;
							bb++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			int l=s[i][0];
			ans+=s[i][l];
		}
		cout<<ans<<endl;
	}
	return 0;
}

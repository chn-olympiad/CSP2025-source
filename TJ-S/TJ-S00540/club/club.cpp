#include<bits/stdc++.h>
using namespace std;
struct Nodep{
	int hao;
	int shu;
	int shi=0;
}a[100005],b[100005],c[100005];
bool cmp(Nodep x,Nodep y)
{
	return x.shu>y.shu;
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].shu>>b[i].shu>>c[i].shu;
			a[i].hao=b[i].hao=c[i].hao=i;
			a[i].shi=b[i].shi=c[i].shi=false;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int q=n-i-j;
				long long sum=0;
				long long ge=0;
				for(int p=1;p<=i;p++)
				{
					if(!a[p].shi)
					{
						a[p].shi=1;
						sum+=a[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[p].hao)
							{
								b[l].shi=1;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[p].hao)
							{
								c[l].shi=1;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<i)
				{
					for(int k=i+1;k<=n;k++)
					{
						if(ge>=i)
						{
							break;
						}
						if(!a[k].shi)
					{
						a[k].shi=1;
						sum+=a[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[k].hao)
							{
								b[l].shi=1;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[k].hao)
							{
								c[l].shi=1;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
					for(int p=1;p<=j;p++)
				{
					if(!b[p].shi)
					{
						b[p].shi=1;
						sum+=b[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[p].hao)
							{
								a[l].shi=1;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[p].hao)
							{
								c[l].shi=1;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<j)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(ge>=j)
						{
							break;
						}
						if(b[k].shi==false)
					{
						b[k].shi=true;
						sum+=b[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
				if(i==2&&j==2)
				{
					cout<<sum<<" "<<1<<endl;
				}
					for(int p=1;p<=q;p++)
				{
					if(!c[p].shi)
					{
						c[p].shi=true;
						sum+=c[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<q)
				{
					for(int k=q+1;k<=n;k++)
					{
						if(ge>=q)
						{
							break;
						}
						if(!c[k].shi)
					{
						c[k].shi=true;
						sum+=c[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
			}
			for(int i=1;i<=n;i++)
		{
			a[i].shi=b[i].shi=c[i].shi=false;
		}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int q=n-i-j;
				long long sum=0;
				long long ge=0;
				for(int p=1;p<=i;p++)
				{
					if(!a[p].shi)
					{
						a[p].shi=true;
						sum+=a[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<i)
				{
					for(int k=i+1;k<=n;k++)
					{
						if(ge>=i)
						{
							break;
						}
						if(!a[k].shi)
					{
						a[k].shi=true;
						sum+=a[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=j;p++)
				{
					if(!c[p].shi)
					{
						c[p].shi=true;
						sum+=c[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<j)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(ge>=j)
						{
							break;
						}
						if(!c[k].shi)
					{
						c[k].shi=true;
						sum+=c[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=q;p++)
				{
					if(!b[p].shi)
					{
						b[p].shi=true;
						sum+=b[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<q)
				{
					for(int k=q+1;k<=n;k++)
					{
						if(ge>=q)
						{
							break;
						}
						if(!b[k].shi)
					{
						b[k].shi=true;
						sum+=b[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
		for(int i=1;i<=n;i++)
		{
			a[i].shi=b[i].shi=c[i].shi=false;
		}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int q=n-i-j;
				long long sum=0;
				long long ge=0;
				for(int p=1;p<=i;p++)
				{
					if(!b[p].shi)
					{
						b[p].shi=true;
						sum+=b[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<i)
				{
					for(int k=i+1;k<=n;k++)
					{
						if(ge>=i)
						{
							break;
						}
						if(!b[k].shi)
					{
						b[k].shi=true;
						sum+=b[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=j;p++)
				{
					if(!a[p].shi)
					{
						a[p].shi=true;
						sum+=a[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<j)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(ge>=j)
						{
							break;
						}
						if(!a[k].shi)
					{
						a[k].shi=true;
						sum+=a[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=q;p++)
				{
					if(!c[p].shi)
					{
						c[p].shi=true;
						sum+=c[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<q)
				{
					for(int k=q+1;k<=n;k++)
					{
						if(ge>=q)
						{
							break;
						}
						if(!c[k].shi)
					{
						c[k].shi=true;
						sum+=c[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
				for(int i=1;i<=n;i++)
		{
			a[i].shi=b[i].shi=c[i].shi=false;
		}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int q=n-i-j;
				long long sum=0;
				long long ge=0;
				for(int p=1;p<=i;p++)
				{
					if(!b[p].shi)
					{
						b[p].shi=true;
						sum+=b[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<i)
				{
					for(int k=i+1;k<=n;k++)
					{
						if(ge>=i)
						{
							break;
						}
						if(!b[k].shi)
					{
						b[k].shi=true;
						sum+=b[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=j;p++)
				{
					if(!c[p].shi)
					{
						c[p].shi=true;
						sum+=c[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<j)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(ge>=j)
						{
							break;
						}
						if(!c[k].shi)
					{
						c[k].shi=true;
						sum+=c[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=q;p++)
				{
					if(!a[p].shi)
					{
						a[p].shi=true;
						sum+=a[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<q)
				{
					for(int k=q+1;k<=n;k++)
					{
						if(ge>=q)
						{
							break;
						}
						if(!a[k].shi)
					{
						a[k].shi=true;
						sum+=a[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
				for(int i=1;i<=n;i++)
		{
			a[i].shi=b[i].shi=c[i].shi=false;
		}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int q=n-i-j;
				long long sum=0;
				long long ge=0;
				for(int p=1;p<=i;p++)
				{
					if(!c[p].shi)
					{
						c[p].shi=true;
						sum+=c[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<i)
				{
					for(int k=i+1;k<=n;k++)
					{
						if(ge>=i)
						{
							break;
						}
						if(!c[k].shi)
					{
						c[k].shi=true;
						sum+=c[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=j;p++)
				{
					if(!a[p].shi)
					{
						a[p].shi=true;
						sum+=a[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<j)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(ge>=j)
						{
							break;
						}
						if(!a[k].shi)
					{
						a[k].shi=true;
						sum+=a[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=q;p++)
				{
					if(!b[p].shi)
					{
						b[p].shi=true;
						sum+=b[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<q)
				{
					for(int k=q+1;k<=n;k++)
					{
						if(ge>=q)
						{
							break;
						}
						if(!b[k].shi)
					{
						b[k].shi=true;
						sum+=b[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
				for(int i=1;i<=n;i++)
		{
			a[i].shi=b[i].shi=c[i].shi=false;
		}
			}
		}
		for(int i=1;i<=n/2;i++)
		{
			for(int j=1;j<=n-i;j++)
			{
				int q=n-i-j;
				long long sum=0;
				long long ge=0;
				for(int p=1;p<=i;p++)
				{
					if(!c[p].shi)
					{
						c[p].shi=true;
						sum+=c[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<i)
				{
					for(int k=i+1;k<=n;k++)
					{
						if(ge>=i)
						{
							break;
						}
						if(!c[k].shi)
					{
						c[k].shi=true;
						sum+=c[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==c[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==c[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=j;p++)
				{
					if(!b[p].shi)
					{
						b[p].shi=true;
						sum+=b[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[p].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<j)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(ge>=j)
						{
							break;
						}
						if(!b[k].shi)
					{
						b[k].shi=true;
						sum+=b[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(a[l].hao==b[k].hao)
							{
								a[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==b[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ge=0;
					for(int p=1;p<=q;p++)
				{
					if(!a[p].shi)
					{
						a[p].shi=true;
						sum+=a[p].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[p].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[p].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
				}
				if(ge<q)
				{
					for(int k=q+1;k<=n;k++)
					{
						if(ge>=q)
						{
							break;
						}
						if(!a[k].shi)
					{
						a[k].shi=true;
						sum+=a[k].shu;
						ge++;
						for(int l=1;l<=n;l++)
						{
							if(b[l].hao==a[k].hao)
							{
								b[l].shi=true;
								break;
							}
						}
						for(int l=1;l<=n;l++)
						{
							if(c[l].hao==a[k].hao)
							{
								c[l].shi=true;
								break;
							}
						}
					}
					else
					{
						continue;
					}
					}
				}
				ans=sum>ans?sum:ans;
				ge=0;
		for(int i=1;i<=n;i++)
		{
			a[i].shi=b[i].shi=c[i].shi=false;
		}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

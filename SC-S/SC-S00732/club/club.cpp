#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010],b[100010],c[100010],ans,aa[400010],bb[400010],ka,kb,cc[100010],mc,mi,ge[13],mx,s[100010][13];
bool f,ff;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n;
		f=ff=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0)
			{
				f=false;
			}
			if(c[i]!=0)
			{
				ff=false;
			}
		}
		if(f)
		{
			ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<"\n";
		}
		else if(ff)
		{
			ans=ka=kb=0;
			for(int i=1;i<=n;i++)
			{
				cc[i]=abs(a[i]-b[i]);
				if(a[i]>b[i])
				{
					aa[++ka]=i;
				}
				else
				{
					bb[++kb]=i;
				}
			}
			while(ka>n/2)
			{
				mc=1e9;
				for(int i=1;i<=ka;i++)
				{
					if(cc[aa[i]]<mc)
					{
						mc=cc[aa[i]];
						mi=i;
					}
				}
				for(int i=mi;i<ka;i++)
				{
					aa[i]=aa[i+1];
				}
				ka--;
				bb[++kb]=mi;
			}
			while(kb>n/2)
			{
				mc=1e9;
				for(int i=1;i<=kb;i++)
				{
					if(cc[bb[i]]<mc)
					{
						mc=cc[bb[i]];
						mi=i;
					}
				}
				for(int i=mi;i<kb;i++)
				{
					bb[i]=bb[i+1];
				}
				kb--;
				aa[++ka]=mi;
			}
			for(int i=1;i<=ka;i++)
			{
				ans+=a[aa[i]];
			}
			for(int i=1;i<=kb;i++)
			{
				ans+=b[bb[i]];
			}
			cout<<ans<<"\n";
		}
		else if(n==2)
		{
			cout<<max(a[1]+b[2],max(a[2]+b[1],max(a[1]+c[2],max(a[2]+c[1],max(b[1]+c[2],b[2]+c[1])))))<<"\n";
		}
		else if(n==4)
		{
			for(int i=1;i<=n;i++)
			{
				s[i][1]=a[i];
				s[i][2]=b[i];
				s[i][3]=c[i];
			}
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					for(int k=1;k<=3;k++)
					{
						for(int l=1;l<=3;l++)
						{
							ge[1]=ge[2]=ge[3]=0;
							ge[i]++;
							ge[j]++;
							ge[k]++;
							ge[l]++;
							if(ge[1]>2||ge[2]>2||ge[3]>2)
							{
								continue;
							}
							mx=max(s[1][i]+s[2][j]+s[3][k]+s[4][l],mx);
						}
					}
				}
			}
			cout<<mx<<"\n";
		}
		else
		{
			ans=0;
			for(int i=1;i<=n;i++)
			{
				ans+=max(max(a[i],b[i]),c[i]);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
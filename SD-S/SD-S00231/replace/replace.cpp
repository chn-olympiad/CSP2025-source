#include<iostream>
using namespace std;
int n,q,ans,cnts,ansi,ansss,sat,xaa,ansx,ansy;
int cz[200010][5];
string x,y,cnt,st;
string a[200010][5];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	if(n<=1000)
	{
		for(int i=1;i<=q;i++)
		{
			cnts=0;
			cin>>x>>y;
			if(x.size()!=y.size())
			{
				printf("0\n");
			}
			else
			{
				for(int xi=0;xi<x.size();xi++)
				{
					if(x[xi]!=y[xi])
					{
						cnt[0]=x[xi];
						ans=xi;
						break;
					}
				}
				for(int i=1;i<=n;i++)
				{
					sat=0;
					for(int xi=0;xi<a[i][1].size();xi++)
					{
						if(a[i][1][xi]==cnt[0])
						{
							ansi=xi;
							xaa=0;
							for(int xx=0;xx<a[i][1].size();xx++)
							{
								if(x[xx+ans-ansi]!=a[i][1][xx])
								{
									xaa=1;
									break;
								}
							}
							if(xaa==0)
							{
								sat=1;
								break;
							}
						
						}
					}
					if(sat==1)
					{
						st=x;
						for(int xx=0;xx<a[i][1].size();xx++)
						{
							st[xx+ans-ansi]=a[i][2][xx];
						}
						ansss=0;
						for(int k=0;k<y.size();k++)
						{
							if(st[k]!=y[k])
							{
								ansss=1;
								break;
							}
						}
						if(ansss==0)
						{
							cnts++;
						}
					}
				}
				printf("%d\n",cnts);
			}
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			cin>>x>>y;
			if(x.size()!=y.size())
			{
				printf("0\n");
			}
			else
			{
				cnts=0;
				for(int zz=1;zz<=n;zz++)
				{
					for(int j=0;j<a[zz][1].size();j++)
					{
						if(a[zz][1][j]=='b')
						{
							ansx=j;
						}
						if(a[zz][2][j]=='b')
						{
							ansy=j;
						}
					}
					cz[zz][1]=ansx;
					cz[zz][2]=ansy;
				}
				for(int j=0;j<x.size();j++)
				{
					if(x[j]=='b')
					{
						ansx=j;
					}
					if(y[j]=='b')
					{
						ansy=j;
					}
				}
				for(int yt=1;yt<=n;yt++)
				{
					if((cz[yt][1]-cz[yt][2]==ansx-ansy)&&(a[yt][1].size()-cz[yt][1]<=x.size()-ansx))
					{
						cnts++;
					}
				}
				printf("%d\n",cnts);
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long d[6];
int ans[100010],bns[100010],cns[100010],as[100010],bs[100010],cs[100010],an = 0,bn = 0,cn = 0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,a,b,c;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>m;
		int num = m/2;
		int kok = 0;
		int gh;
		for(int j = 1;j<=m;j++)
		{
			cin>>a>>b>>c;
			if((a>b&&a>c)||(a==b&&a>c)||(a>b&&a==c))
			{
				ans[j] = a;
				bns[j] = b;
				cns[j] = c;
				as[kok] = j;
				bs[kok] = j;
				cs[kok] = j;
				d[i] = d[i]+a;
				an++;
				kok++;
				if(an>num)
				{
					int kjk = ans[as[kok]];
					for(int kl = 1;kl<=kok;kl++)
					{
						kjk = min(kjk,ans[as[kl]]);
					}
					d[i] = d[i]-kjk;
					for(int kl = 1;kl<=kok;kl++)
					{
						if(kjk == ans[as[kl]])
						{
							gh = kl;
						}
					}
					if((bns[as[gh]]>=cns[as[gh]])&&(bn<num))
					{
						d[i] = d[i]+bns[as[gh]];
						bs[gh] = as[gh];
						bn++;
					}
					else
					{
						d[i] = d[i]+cns[as[gh]];
						cs[gh] = as[gh];
						cn++;
					}
					an = an-1;
				}
			}
			else if((b>a&&b>c)||(b==c&&b>a))
			{
				ans[j] = a;
				bns[j] = b;
				cns[j] = c;
				as[kok] = j;
				bs[kok] = j;
				cs[kok] = j;
				d[i] = d[i]+b;
				bn++;
				kok++;
				if(bn>num)
				{
					int kjk = bns[bs[kok]];
					for(int kl = 1;kl<=kok;kl++)
					{
						kjk = min(kjk,bns[bs[kl]]);
					}
					d[i] = d[i]-kjk;
					for(int kl = 1;kl<=kok;kl++)
					{
						if(kjk == bns[bs[kl]])
						{
							gh = kl;
						}
					}
					if((ans[bs[gh]]>=cns[bs[gh]])&&(an<num))
					{
						d[i] = d[i]+ans[bs[gh]];
						as[gh] = bs[gh];
						an++;
					}
					else
					{
						d[i] = d[i]+cns[bs[gh]];
						cs[gh] = bs[gh];
						cn++;
					}
					bn = bn-1;
				}
			}
			else if(c>a&&c>b)
			{
				ans[j] = a;
				bns[j] = b;
				cns[j] = c;
				as[kok] = j;
				bs[kok] = j;
				cs[kok] = j;
				d[i] = d[i]+c;
				cn++;
				kok++;
				if(cn>num)
				{
					int kjk = cns[cs[kok]];
					for(int kl = 1;kl<=kok;kl++)
					{
						kjk = min(kjk,cns[cs[kl]]);
					}
					d[i] = d[i]-kjk;
					for(int kl = 1;kl<=kok;kl++)
					{
						if(kjk == cns[cs[kl]])
						{
							gh = kl;
						}
					}
					if((ans[cs[gh]]>=bns[cs[gh]])&&(an<num))
					{
						d[i] = d[i]+ans[cs[gh]];
						as[gh] = cs[gh];
						an++;
					}
					else
					{
						d[i] = d[i]+bns[cs[gh]];
						bs[gh] = cs[gh];
						bn++;
					}
					cn = cn-1;
				}
			}
		}
	}
	for(int i = 1;i<=n;i++)
	{
		cout<<d[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

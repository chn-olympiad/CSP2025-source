#include<bits/stdc++.h>
using namespace std;

const int N=1e5+101;

long long t;
long long n;

struct node
{
	int fir;
	int sec;
	int thi;
	int vis;
	int c12;
	int c23;
	int c13;
}sta[N];

struct node1
{
	int fir;
	int sec;
	int thi;
	int vis;
	int c12;
	int c23;
	int c13;
}sta1[N];

struct node2
{
	int fir;
	int sec;
	int thi;
	int vis;
	int c12;
	int c23;
	int c13;
}sta2[N];

struct node3
{
	int fir;
	int sec;
	int thi;
	int vis;
	int c12;
	int c23;
	int c13;
}sta3[N];

int cmp1(node a,node b)
{
	return a.fir>=b.fir; 
}

int cmp2(node a,node b)
{
	return a.sec>=b.sec;
}

int cmp3(node a,node b)
{
	return a.thi>=b.thi;
}


signed main()
{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while (t--)
	{
		cin>>n;
		long long ans=0;
		int nu[5];
		nu[1]=n/2;
		nu[2]=n/2;
		nu[3]=n/2;
		int num[N]={};
		for (int i=1;i<=n;i++)
		{
			cin>>sta[i].fir>>sta[i].sec>>sta[i].thi;
			sta[i].c12=sta[i].fir-sta[i].sec;
			sta[i].c13=sta[i].fir-sta[i].thi;
			sta[i].c23=sta[i].sec-sta[i].thi;
		}
		
		sort(sta+1,sta+n+1,cmp1);
		for (int i=1;i<=n;i++)
		{
			sta1[i].fir=sta[i].fir;
			sta1[i].sec=sta[i].sec;
			sta1[i].thi=sta[i].thi;
			sta1[i].c12=sta[i].c12;
			sta1[i].c23=sta[i].c23;
			sta1[i].c13=sta[i].c13;
		}
		for (int i=1;i<=n/2;i++)
		{
			ans+=sta[i].fir;
			sta[i].vis=1;
			num[i]=1;
		}
		//cout<<ans<<endl;
		
		sort(sta+1,sta+n+1,cmp2);
		for (int i=1;i<=n;i++)
		{
			sta2[i].fir=sta[i].fir;
			sta2[i].sec=sta[i].sec;
			sta2[i].thi=sta[i].thi;
			sta2[i].c12=sta[i].c12;
			sta2[i].c23=sta[i].c23;
			sta2[i].c13=sta[i].c13;
		}
		for (int i=1;i<=n/2;i++)
		{
			if (sta[i].vis)
			{
				if (sta[i].sec>sta[i].fir)
				{
					nu[1]--;
					ans+=(sta[i].sec-sta[i].fir);
					num[i]=2;
				}
				else nu[2]--;
			}
			else
			{
				sta[i].vis=1;
				ans+=sta[i].sec;
				num[i]=2;
			}
		}
		//cout<<ans<<endl;
		
		sort(sta+1,sta+n+1,cmp3);
		for (int i=1;i<=n;i++)
		{
			sta3[i].fir=sta[i].fir;
			sta3[i].sec=sta[i].sec;
			sta3[i].thi=sta[i].thi;
			sta3[i].c12=sta[i].c12;
			sta3[i].c23=sta[i].c23;
			sta3[i].c13=sta[i].c13;
		}
		for (int i=1;i<=n/2;i++)
		{
			if (sta[i].vis)
			{
				if (sta[i].thi>sta[i].fir&&sta[i].thi>sta[i].sec)
				{
					if (num[i]==2)
					{
						nu[2]--;
						ans+=(sta[i].thi-sta[i].sec);
					}
					else
					{
						nu[1]--;
						ans+=(sta[i].thi-sta[i].fir);
					}
				}
				else nu[3]--;
			}
			else
			{
				sta[i].vis=1;
				ans+=sta[i].thi;
				num[i]=3;
			}
		}
		//cout<<ans<<endl;
		for (int i=1;i<=n;i++)
		{
			if (!sta[i].vis)
			{
				int yi=0,er=0,san=0;
				int y=0,e=0,s=0;
				if (sta[i].fir>=sta[i].sec&&sta[i].fir>=sta[i].thi)
				{
					yi=sta[i].fir;
					y=1;
				}
				else if (sta[i].sec>=sta[i].fir&&sta[i].sec>=sta[i].thi)
				{
					yi=sta[i].sec;
					y=2;
				}
				else if (sta[i].thi>=sta[i].sec&&sta[i].thi>=sta[i].fir)
				{
					yi=sta[i].thi;
					y=3;
				}
				
				if (sta[i].fir>=sta[i].sec&&sta[i].fir<=sta[i].thi||sta[i].fir>=sta[i].thi&&sta[i].fir<=sta[i].sec)
				{
					er=sta[i].fir;
					e=1;
				}
				else if (sta[i].sec>=sta[i].fir&&sta[i].sec<=sta[i].thi||sta[i].sec>=sta[i].thi&&sta[i].sec<=sta[i].fir)
				{
					er=sta[i].sec;
					e=2;
				}
				else if (sta[i].thi<=sta[i].fir&&sta[i].thi<=sta[i].sec||sta[i].thi>=sta[i].sec&&sta[i].thi<=sta[i].fir)
				{
					er=sta[i].thi;
					e=3;
				}
				
				if (sta[i].fir<=sta[i].sec&&sta[i].fir<=sta[i].thi)
				{
					san=sta[i].fir;
					s=1;
				}
				else if (sta[i].sec<=sta[i].fir&&sta[i].sec<=sta[i].thi)
				{
					san=sta[i].sec;
					s=2;
				}
				else if (sta[i].thi<=sta[i].fir&&sta[i].thi<=sta[i].sec)
				{
					san=sta[i].thi;
					s=3;
				}
				if (nu[y]<n/2) ans+=yi;
				else
				{
					if (er) ans+=er;
					else
					{
						if (y==1)
						{
							for (int j=n/2;j>=1;j--)
							{
								if (!sta1[j].vis)
								{
									if (sta1[j].c23>=0&&sta1[j].sec!=0&&sta1[j].c12>=0)
									{
										ans-=sta1[j].fir;
										ans+=sta1[j].sec;
										ans+=yi;
										sta1[j].vis=1;
										break;
									}
									else if (sta1[j].c23<=0&&sta1[j].thi!=0&&sta1[j].c13>=0)
									{
										ans-=sta1[j].fir;
										ans+=sta1[j].thi;
										ans+=yi;
										sta1[j].vis=1;
										break;
									}
								}
							}
						}
						else if (y==2)
						{
							for (int j=n/2;j>=1;j--)
							{
								if (!sta2[j].vis)
								{
									if (sta2[j].c12>=0&&sta2[j].fir!=0&&sta2[j].c12<=0)
									{
										ans+=sta1[j].sec;
										ans+=sta1[j].fir;
										ans+=yi;
										sta2[j].vis=1;
										break;
									}
									else if (sta1[j].c13<=0&&sta1[j].thi!=0&&sta2[j].c23>=0)
									{
										ans-=sta1[j].sec;
										ans+=sta1[j].thi;
										ans+=yi;
										sta2[j].vis=1;
										break;
									}
								}
								
							}
						}
						else if (y==3)
						{
							for (int j=n/2;j>=1;j--)
							{
								if (!sta3[j].vis)
								{
									if (sta3[j].c12<=0&&sta1[j].sec!=0&&sta3[j].c23<=0)
									{
										ans+=sta3[j].thi;
										ans+=sta3[j].sec;
										ans+=yi;
										sta3[j].vis=1;
										break;
									}
									else if (sta3[j].c12>=0&&sta3[j].fir!=0&&sta3[j].c13<=0)
									{
										ans+=sta3[j].thi;
										ans+=sta3[j].fir;
										ans+=yi;
										sta3[j].vis=1;
										break;
									}
								}
							}
						}
						
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}


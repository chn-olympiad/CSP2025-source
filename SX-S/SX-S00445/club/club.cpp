#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct B{
	long long z;
	int bh;
}f1[N],f2[N],f3[N];
struct A{
	int fs;
	int ss;
	int ts;
}a[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	long long n,sf1,sf2,sf3,minx,mini,maxx,maxgo,xi,xz,sf,ans=0;
	cin>>T;
	while(T--)
	{
		sf1=0;sf2=0;sf3=0;ans=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].fs,&a[i].ss,&a[i].ts);
			if(a[i].fs>=a[i].ss && a[i].fs>=a[i].ts)
			{
				f1[++sf1].z=a[i].fs;
				f1[sf1].bh=i;
			}
			else if(a[i].ss>=a[i].ts)
			{
				f2[++sf2].z=a[i].ss;
				f2[sf2].bh=i;
			}
			else
			{
				f3[++sf3].z=a[i].ts;
				f3[sf3].bh=i;
			}
		}
		
		/*»ù´¡¼ÆËã*/
		
		if(sf1>n/2)
		{
			cout<<1<<' ';
			sf=sf1;
			while(sf>n/2)
			{
				minx=LLONG_MAX;
				sf--;
				for(int i=1;i<=sf1;i++)
				{
					if(f1[i].z==-1) continue;
					else
					{
						xi=f1[i].bh;
						if(a[xi].ss>a[xi].ts)
						{
							xz=a[xi].fs-a[xi].ss;
							if(minx>xz)
							{
								minx=xz;
								mini=i;
								maxx=a[xi].ss;
								maxgo=2;
							}
						}
						else
						{
							xz=a[xi].fs-a[xi].ts;
							if(minx>xz)
							{
								minx=xz;
								mini=i;
								maxx=a[xi].ts;
								maxgo=3;
							}
						}
					}
				}
				if(maxgo==2)
				{
					f2[++sf2].z=maxx;
				}
				else
				{
					f3[++sf3].z=maxx;
				}
				f1[mini].z=-1;
			}
		}
		
		
		
		else if(sf2>n/2)
		{
			cout<<2<<' ';
			sf=sf2;
			while(sf>n/2)
			{
				minx=LLONG_MAX;
				sf--;
				for(int i=1;i<=sf2;i++)
				{
					if(f2[i].z==-1) continue;
					else
					{
						xi=f2[i].bh;
						if(a[xi].fs>a[xi].ts)
						{
							xz=a[xi].ss-a[xi].fs;
							if(minx>xz)
							{
								minx=xz;
								mini=i;
								maxx=a[xi].fs;
								maxgo=2;
							}
						}
						else
						{
							xz=a[xi].ss-a[xi].ts;
							if(minx>xz)
							{
								minx=xz;
								mini=i;
								maxx=a[xi].ts;
								maxgo=3;
							}
						}
					}
				}
				if(maxgo==2)
				{
					f1[++sf1].z=maxx;
				}
				else
				{
					f3[++sf3].z=maxx;
				}
				f2[mini].z=-1;
			}
		}
		
		
		
		else if(sf3>n/2)
		{
			cout<<3<<' ';
			sf=sf3;
			while(sf>n/2)
			{
				minx=LLONG_MAX;
				sf--;
				for(int i=1;i<=sf3;i++)
				{
					if(f3[i].z==-1) continue;
					else
					{
						xi=f3[i].bh;
						if(a[xi].ss>a[xi].fs)
						{
							xz=a[xi].ts-a[xi].ss;
							if(minx>xz)
							{
								minx=xz;
								mini=i;
								maxx=a[xi].ss;
								maxgo=2;
							}
						}
						else
						{
							xz=a[xi].ts-a[xi].fs;
							if(minx>xz)
							{
								minx=xz;
								mini=i;
								maxx=a[xi].fs;
								maxgo=3;
							}
						}
					}
				}
				if(maxgo==2)
				{
					f2[++sf2].z=maxx;
				}
				else
				{
					f1[++sf1].z=maxx;
				}
				f3[mini].z=-1;
			}
		}
		for(int i=1;i<=sf1;i++)
		{
			if(f1[i].z==-1)continue;
			ans=ans+f1[i].z;
		}
		for(int i=1;i<=sf2;i++)
		{
			if(f2[i].z==-1)continue;
			ans=ans+f2[i].z;
		}
		for(int i=1;i<=sf3;i++)
		{
			if(f3[i].z==-1)continue;
			ans=ans+f3[i].z;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
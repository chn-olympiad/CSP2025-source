#include <bits/stdc++.h>
using namespace std;
int t;
struct stu
{
	int x;
	int y;
	int z;
}a[110000],lx[110000],ly[110000],lz[110000];
bool cmpx(stu k,stu l)
{
	return k.x-max(k.y,k.z)<l.x-max(l.y,l.z);
}
bool cmpy(stu k,stu l)
{
	return k.y-max(k.x,k.z)<l.y-max(l.x,l.z);
}
bool cmpz(stu k,stu l)
{
	return k.z-max(k.y,k.x)<l.z-max(l.y,l.x);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,nh;
	int cntx,cnty,cntz,mx,ans,idx;
	cin>>t;
	while(t--)
	{
		ans=0;
		cntx=0;
		cnty=0;
		cntz=0;
		memset(a,0,sizeof(a));
		memset(lx,0,sizeof(lx));
		memset(ly,0,sizeof(ly));
		memset(lz,0,sizeof(lz));
		cin>>n;
		nh=n>>1;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			mx=max(a[i].x,max(a[i].y,a[i].z));
			ans+=mx;
			if(mx==a[i].x)
			{
				++cntx;
				lx[cntx].x=a[i].x;
				lx[cntx].y=a[i].y;
				lx[cntx].z=a[i].z;
			}
			else if(mx==a[i].y)
			{
				++cnty;
				ly[cnty].x=a[i].x;
				ly[cnty].y=a[i].y;
				ly[cnty].z=a[i].z;
			}
			else if(mx==a[i].z)
			{
				++cntz;
				lz[cntz].x=a[i].x;
				lz[cntz].y=a[i].y;
				lz[cntz].z=a[i].z;
			}
		}
		mx=max(cntx,max(cnty,cntz));
		int idx=1;
		if(mx>nh)
		{
			if(cntx==mx)
			{
				sort(lx+1,lx+cntx+1,cmpx);
				while(cntx>nh)
				{
					--cntx;
					ans-=lx[idx].x-max(lx[idx].y,lx[idx].z);
					++idx;
				}
			}
			else if(cnty==mx)
			{
				sort(ly+1,ly+cnty+1,cmpy);
				while(cnty>nh)
				{
					--cnty;
					ans-=ly[idx].y-max(ly[idx].x,ly[idx].z);
					++idx;
				}
			}
			else if(cntz==mx)
			{
				sort(lz+1,lz+cntz+1,cmpz);
				while(cntz>nh)
				{
					--cntz;
					ans-=lz[idx].z-max(lz[idx].y,lz[idx].x);
					++idx;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

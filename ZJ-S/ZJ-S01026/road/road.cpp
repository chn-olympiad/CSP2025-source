#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+1e2;
#define int long long

int n,m,k,ans=INT_MAX;
struct xing{
	int to;
	int co;// cost
};
vector<xing> a[N];

bool vc[N];
bool check(bool v[N])
{
	for(int i=1;i<=n;i++)
	{
		if(!v[i])return false;
	}
	return true;
}
void gone(bool v[N],int hg,int goo,int cost)
{
	if(check(v))
	{
		ans=min(ans,cost);
		return;
	}
	for(int i=0;i<a[hg].size();i++)
	{
		if(!v[a[hg][i].to])v[a[hg][i].to]=1,gone(v,a[hg][i].to,goo+1,cost+a[hg][i].co);//v[a[hg][i].to]=0;
	}
}


signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	int l1,r1,c1;
	xing l11,r11;
	for(int i=1;i<=m;i++)
	{
		cin>>l1>>r1>>c1;
		l11.to=r1,l11.co=c1;
		r11.to=l1,r11.co=c1;
		a[l1].push_back(l11);
		a[r1].push_back(r11);
	}
	
	int roo[100005];
	
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>roo[j];
		}
		for(int j=1;j<=m;j++)
		{
			for(int kw=j+1;kw<=m;kw++)
			{
				bool fl=1,fr=1;
				l11.to=kw,l11.co=roo[j]+roo[kw];
				r11.to=j,r11.co=roo[j]+roo[kw];
				for(int o=0;o<a[j].size();o++)
				{
					if(a[j][o].to==kw)
					{
						fl=0;
						a[j][o].co=min(a[j][o].co,l11.co);
						break;
					}
				}
				if(fl)a[j].push_back(l11);
				for(int o=0;o<a[kw].size();o++)
				{
					if(a[kw][o].to==j)
					{
						fr=0;
						a[kw][o].co=min(a[kw][o].co,r11.co);
						break;
					}
				}
				if(fr)a[kw].push_back(r11);
			}
		}
	}
	xing onn;
	for(int i=1;i<=n;i++)
	{
		onn.to=i;onn.co=0;
		a[0].push_back(onn);
	}
	gone(vc,0,0,0);
	cout<<ans;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

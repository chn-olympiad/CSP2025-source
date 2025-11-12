#include<bits/stdc++.h>
using namespace std;
long long a,b,c,ax[10000][10000],m,n,k,sum=0,ll=100000000,po,lp,llp=12;
int suum(int x,int y)
{
	for(int i=1;i<=y;i++)
	{
		if(ax[x][i]!=0)
		{
			
			sum+=ax[x][i];
			cout<<ax[x][i]<<endl;
			lp=ax[x][i];
			ax[x][i]=0;
			sum=suum(i,y);
		}
	}
	ll=min(ll,sum);
	sum-=lp;
	lp=0;
	return sum;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		ax[aa][bb]=cc;
		ax[bb][aa]=cc;
	}
	for(int i=n;i>0;i--)
	{
		for(int j=n;j>0;j--)
		{
			if(ax[i][j]!=0)
			{
				llp=ax[i][j];
				po=suum(1,n);
				cout<<ll+llp;
				return 0;
			}
		}
	}

	return 0;
}

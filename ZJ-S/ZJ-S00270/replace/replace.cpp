#include<bits/stdc++.h>
#define sn 5000005
#define int long long
#define mod 1000000007
#define base 13331
using namespace std;
int n,q,lf,rf,ans,ltd,len[sn],pw[sn],hx[sn],hy[sn],ho[sn],ht[sn],lense;
string x[sn],y[sn],sne,swo;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=1000000;i++)
	{
		pw[i]=pw[i-1]*base%mod;
	}
	ltd=1000000;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		len[i]=x[i].size();
		for(int j=0;j<len[i];j++)
		{
			hx[i]=(hx[i]*base+x[i][j])%mod;
			hy[i]=(hy[i]*base+y[i][j])%mod;
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>sne>>swo;
		lense=sne.size();
		while(lense>ltd)
		{
			ltd++;
			pw[ltd]=pw[ltd-1]*base%mod;
		}
		for(int j=0;j<lense;j++)
		{
			ho[j+1]=(ho[j]*base+sne[j])%mod;
			ht[j+1]=(ht[j]*base+swo[j])%mod;
		}
		for(int j=0;j<lense;j++)
		{
			if(sne[j]!=swo[j])
			{
				lf=j+1;
				break;
			}
		}
		for(int j=lense;j>=0;j--)
		{
			if(sne[j]!=swo[j])
			{
				rf=j+1;
				break;
			}
		}
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=lense;k++)
			{
				if((ho[k+len[j]-1]-(pw[len[j]]*ho[k-1])%mod+mod)%mod==hx[j])
				{
					if((ht[k+len[j]-1]-(pw[len[j]]*ht[k-1])%mod+mod)%mod==hy[j])
					{
						if(k+len[j]-1>=rf&&k<=lf)
						{
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
		for(int j=1;j<=lense;j++)
		{
			ho[j]=0,ht[j]=0;
		}
	}
	return 0;
}

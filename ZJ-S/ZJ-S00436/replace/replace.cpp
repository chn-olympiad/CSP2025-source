#include<bits/stdc++.h>
using namespace std;
int n,q;
string sa[200005],sb[200005],ta,tb;
inline int read()
{
	int tot=0;char c=getchar();
	while(!('0'<=c&&c<='9'))c=getchar();
	while('0'<=c&&c<='9')tot=tot*10+c-'0',c=getchar();
	return tot;
}
inline string rd()
{
	string tot;char c=getchar();
	while(!('a'<=c&&c<='z'))c=getchar();
	while('a'<=c&&c<='z')tot=tot+c,c=getchar();
	return tot;
}

const long long mdp=998244353,mdpp=1000000007,mod=2333333,modb=4999983;
long long ffa[200005],haspr[5000005];

long long mhaspr(long long x,long long y)
{
	return (x*mdpp%modb+y*mdp%mod)%mod;
}
long long mhas(string x)
{
	long long resa=0;
	for(int i=0;i<x.size();i++)
	{
		resa=(resa*mdp%mod+(x[i]-'a'+1))%mod;
	}
	long long resb=0;
	for(int i=0;i<x.size();i++)
	{
		resb=(resb*mdpp%modb+(x[i]-'a'+1))%modb;
	}
	return mhaspr(resa,resb);
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		sa[i]=rd(),sb[i]=rd();
		haspr[mhaspr(mhas(sa[i]),mhas(sb[i]))]++;
		//cout<<i<<' '<<mhas(sa[i])<<' '<<mhas(sb[i])<<' '<<mhaspr(mhas(sa[i]),mhas(sb[i]))<<endl;
	}
	while(q--)
	{
		ta=rd(),tb=rd();
		//cout<<ta<<' '<<tb<<endl;
		//cout<<mhas(ta)<<' '<<mhas(tb)<<endl;
		int l,r;
		int ans=0;
		for(int i=0;i<ta.size();i++)
		{
			if(ta[i]!=tb[i])
			{
				l=i;
				break;
			}
		}
		for(int i=ta.size()-1;i>=0;i--)
		{
			if(ta[i]!=tb[i])
			{
				r=i;
				break;
			}
		}
		//cout<<l<<' '<<r<<endl;
		long long reshasa=0,reshasb=0;
		long long reshasaa=0,reshasbb=0;
		for(int i=0;i<=l;i++)
		{
			reshasa=0,reshasb=0;
			reshasaa=0,reshasbb=0;
			for(int j=i;j<ta.size();j++)
			{
				reshasa=(reshasa*mdp%mod+(ta[j]-'a'+1))%mod;
				reshasb=(reshasb*mdp%mod+(tb[j]-'a'+1))%mod;
				reshasaa=(reshasaa*mdpp%modb+(ta[j]-'a'+1))%modb;
				reshasbb=(reshasbb*mdpp%modb+(tb[j]-'a'+1))%modb;
				if(j>=r)
				{
					ans+=haspr[mhaspr(mhaspr(reshasa,reshasaa),mhaspr(reshasb,reshasbb))];
					//cout<<q<<' '<<i<<' '<<j<<' '<<reshasa<<' '<<reshasb<<' '<<mhaspr(reshasa,reshasb)<<endl;
				}
			}
		}
		printf("%d\n",ans);
	}
	
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,B=233,mod=998244353;
int n,q,ans,ls[N],rs[N],lt[N],rt[N];
vector<int> sh[N][2],th[N][2];
string s[N][2],t[N][2];
int qpow(int x,int y,int p)
{
	int ret=1;
	while(y)
	{
		x=x*x%p;
		if(y%2==1)
		{
			ret=ret*x%mod;
		}
		y/=2;
	}
	return ret;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,y;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>t[i][0]>>t[i][1];
	}
	for(int i=1;i<=n;i++)
	{
		ls[i]=rs[i]=-1;
		for(int j=0;j<s[i][0].length();j++)
		{
			if(s[i][0][j]!=s[i][1][j])
			{
				if(ls[i]==-1)
				{
					ls[i]=j;
				}
				rs[i]=j;
			}
			sh[i][0].push_back(0);
			sh[i][1].push_back(0);
		}
		// cout<<ls[i]<<" "<<rs[i]<<"\n";
		sh[i][0].push_back(0);
		sh[i][1].push_back(0);
		for(int j=s[i][0].length()-1;j>=0;j--)
		{
			sh[i][0][j]=s[i][0][j]-'a';
			sh[i][1][j]=s[i][1][j]-'a';
			if(j<s[i][0].length()-1)
			{
				sh[i][0][j]=(sh[i][0][j]+sh[i][0][j+1]*B%mod)%mod;
				sh[i][1][j]=(sh[i][1][j]+sh[i][1][j+1]*B%mod)%mod;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		lt[i]=rt[i]=-1;
		for(int j=0;j<t[i][0].length();j++)
		{
			if(t[i][0][j]!=t[i][1][j])
			{
				if(lt[i]==-1)
				{
					lt[i]=j;
				}
				rt[i]=j;
			}
			th[i][0].push_back(0);
			th[i][1].push_back(0);
		}
		// cout<<lt[i]<<" "<<rt[i]<<"\n";
		th[i][0].push_back(0);
		th[i][1].push_back(0);
		for(int j=t[i][0].length()-1;j>=0;j--)
		{
			th[i][0][j]=t[i][0][j]-'a';
			th[i][1][j]=t[i][1][j]-'a';
			if(j<s[i][0].length()-1)
			{
				th[i][0][j]=(th[i][0][j]+th[i][0][j+1]*B%mod)%mod;
				th[i][1][j]=(th[i][1][j]+th[i][1][j+1]*B%mod)%mod;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
		{
			if(lt[i]==-1&&ls[j]==-1)
			{
				ans++;
				continue;
			}
			if(rs[j]-ls[j]!=rt[i]-lt[i])
			{
				continue;
			}
			if(ls[j]>lt[i]||s[j][0].length()-rs[j]>t[i][0].length()-rt[i])
			{
				continue;
			}
			x=(sh[j][0][ls[j]]-sh[j][0][rs[j]+1]*qpow(B,rs[j]-ls[j]+1,mod)%mod+mod)%mod;
			y=(th[i][0][lt[i]]-th[i][0][rt[i]+1]*qpow(B,rt[i]-lt[i]+1,mod)%mod+mod)%mod;
			// cout<<x<<" "<<y<<"\n";
			if(x!=y)
			{
				continue;
			}
			// cout<<"in\n";
			x=(sh[j][1][ls[j]]-sh[j][1][rs[j]+1]*qpow(B,rs[j]-ls[j]+1,mod)%mod+mod)%mod;
			y=(th[i][1][lt[i]]-th[i][1][rt[i]+1]*qpow(B,rt[i]-lt[i]+1,mod)%mod+mod)%mod;
			if(x!=y)
			{
				continue;
			}
			// cout<<"in\n";
			if(ls[j]>0)
			{
				x=(sh[j][0][0]-sh[j][0][ls[j]]*qpow(B,ls[j],mod)%mod+mod)%mod;
				y=(th[i][0][lt[i]-ls[j]]-th[i][0][lt[i]]*qpow(B,ls[j],mod)%mod+mod)%mod;
				if(x!=y)
				{
					continue;
				}
			}
			// cout<<"in\n";
			x=sh[j][0][rs[j]+1];
			y=(th[i][0][rt[i]+1]-th[i][0][rt[i]+s[j][0].length()-rs[j]+1]*qpow(B,s[j][0].length()-rs[j],mod)%mod+mod)%mod;
			if(x!=y)
			{
				continue;
			}
			ans++;
		}
		cout<<ans<<"\n";
	}
}
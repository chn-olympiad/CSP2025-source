#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
const int S=5e6+5;
const int Mod=1e8+7;
const int Bas=1331;
int n,q,l[N],len[N];
int hash1[S],hash2[S],hsh1[N],hsh2[N],bs[S]={1};
string s1[N],s2[N],t1[N],t2[N];
int w1[N],w2[N],h1[N],h2[N];
bool check1(string s)
{
	int le=s.size()-1,t=0;
	for(int i=1;i<=le;i++)
	{
		if(s[i]=='b')
		{
			if(t)return false;
			t=i;
		}
	}
	for(int i=1;i<=le;i++)
	{
		if(s[i]=='b')continue;
		if(s[i]!='a')return false; 
	}
	return true;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if((!check1(s1[i]))||(!check1(s2[i])))return false;
	}
	for(int i=1;i<=q;i++)
	{
		if((!check1(t1[i]))||(!check1(t2[i])))return false;
	}
	return true;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	for(int i=1;i<S;i++)bs[i]=(bs[i-1]*Bas)%Mod;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		l[i]=s1[i].size();
		s1[i]=" "+s1[i];
		s2[i]=" "+s2[i];
	}
	for(int p=1;p<=q;p++)
	{
		cin>>t1[p]>>t2[p];
		len[p]=t1[p].size();
		t1[p]=" "+t1[p];t2[p]=" "+t2[p];
	}
	if(check())
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=l[i];j++)
			{
				if(s1[i][j]=='b')
				{
					w1[i]=j;
					break;
				}
			} 
			for(int j=1;j<=l[i];j++)
			{
				if(s2[i][j]=='b')
				{
					w2[i]=j;
					break;
				}
			} 
		}
		for(int i=1;i<=q;i++)
		{
			for(int j=1;j<=len[i];j++)
			{
				if(t1[i][j]=='b')
				{
					h1[i]=j;
					break;
				}
			} 
			for(int j=1;j<=len[i];j++)
			{
				if(t2[i][j]=='b')
				{
					h2[i]=j;
					break;
				}
			} 
			int ans=0;
			for(int j=1;j<=n;j++)
			{
				if(h1[i]>=w1[j]&&(len[i]-h1[i])>=(l[j]-w1[j]))
				{
					if(h1[i]-h2[i]==w1[j]-w2[j])
					{
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=l[i];j++)
			{
				hsh1[i]=(hsh1[i]*Bas%Mod+s1[i][j])%Mod;
				hsh2[i]=(hsh2[i]*Bas%Mod+s2[i][j])%Mod;
			}
		}
		for(int p=1;p<=q;p++)
		{
			for(int i=1;i<=len[p];i++)
			{
				hash1[i]=(hash1[i-1]*Bas+t1[p][i])%Mod;
				hash2[i]=(hash2[i-1]*Bas+t2[p][i])%Mod;
			}
			int ans=0;
			for(int i=0;i<=len[p];i++)
			{
				if(hash1[i]!=hash2[i])break;
				for(int j=1;j<=n;j++)
				{
					if(i+l[j]>len[p])continue;
					if((hash1[i+l[j]]-bs[l[j]]*hash1[i]%Mod+Mod)%Mod==hsh1[j])
					{
						if((hash2[i+l[j]]-bs[l[j]]*hash2[i]%Mod+Mod)%Mod==hsh2[j])
						{
							if((hash1[len[p]]-bs[len[p]-(i+l[j])]*hash1[i+l[j]]%Mod+Mod)%Mod==(hash2[len[p]]-bs[len[p]-(i+l[j])]*hash2[i+l[j]]%Mod+Mod)%Mod)
							{
								ans++;
							}
						}
					}
				}
			} 
			cout<<ans<<endl;
		} 
	}
	return 0;
}

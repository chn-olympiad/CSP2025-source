#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e6+5,base=233,mod=1e15+9;
inline ll rd()
{
	int f=1;char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	ll x=(c^48);
	while(isdigit(c=getchar())) x=x*10+(c^48);
	return x*f;
}
int n,q;
map<ll,int>mp,vis;
ll h[N],mi[N];
char s1[N],s2[N];
ll get(int l,int r){return (h[r]-h[l-1]*mi[r-l+1]%mod+mod)%mod;}
int main()
{
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	n=rd(),q=rd(),mi[0]=1;
	for(int i=1;i<N;i++) mi[i]=mi[i-1]*base%mod;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s1+1),scanf("%s",s2+1);
		ll s=0,l=strlen(s1+1);
		for(int j=1;j<=l;j++)
			s=(s*base+(s1[j]-'a'+1)*26+(s2[j]-'a'+1))%mod,vis[s]=1;
		mp[s]++;
	}
	while(q--)
	{
		int ans=0;
		scanf("%s",s1+1),scanf("%s",s2+1);
		int l=strlen(s1+1),L=n,R=0;
		for(int j=1;j<=l;j++)
		{
			if(s1[j]!=s2[j]) R=max(R,j),L=min(L,j);
			h[j]=(h[j-1]*base+(s1[j]-'a'+1)*26+(s2[j]-'a'+1))%mod;
		}
		for(int i=1;i<=L;i++)
			for(int j=R;j<=l;j++)
			{
				ans+=mp[get(i,j)];
				if(!vis[get(i,j)]) break;
			} 
		printf("%d\n",ans);
	}
	return 0;	
} 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool mmark=true;
ll n,k,s[500005],qh[500005];
int main() 
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) {scanf("%lld",&s[i]);if(s[i]!=1) mmark=false;}
	if(k==0)
	{
		if(mmark) printf("%lld",n/2);
		else
		{
			int ans=0;
			bool mark[500005];
			memset(mark,false,sizeof(mark));
			for(int i=1;i<=n;i++)
			{
				if(s[i]==0) ans++;
				else if(s[i]==1 && s[i-1]==1 && !mark[i-1])
				{
					mark[i-1]=mark[i]=true;
					ans++;
				}
			}
			printf("%lld",ans);
		}
		return 0;
	}
	else if(k==1)
	{
		int ans=0;
		bool mark[500005];
		memset(mark,false,sizeof(mark));
		for(int i=1;i<=n;i++)
		{
			if(s[i]==1) {mark[i]=1;ans++;}
			else if((s[i]^s[i-1])==1 && !mark[i-1])
			{
				mark[i-1]=mark[i]=true;
				ans++;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}

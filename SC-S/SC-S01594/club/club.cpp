#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+5;
inline ll rd()
{
	int f=1;char c;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	ll x=(c^48);
	while(isdigit(c=getchar())) x=x*10+(c^48);
	return x*f;
}
ll n,cnt[5],ans,s1[N],s2[N],s3[N];
int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	for(int T=rd();T--;)
	{
		n=rd(),ans=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1,a,b,c;i<=n;i++)
		{
			a=rd(),b=rd(),c=rd();
			if(a>=b&&a>=c) ans+=a,s1[++cnt[1]]=max(b-a,c-a);
			else if(b>=a&&b>=c) ans+=b,s2[++cnt[2]]=max(a-b,c-b);
			else if(c>=a&&c>=b) ans+=c,s3[++cnt[3]]=max(a-c,b-c);
		}
		if(cnt[1]>n/2)
		{	
			sort(s1+1,s1+cnt[1]+1);
			for(int j=cnt[1];j>(n/2);j--) ans+=s1[j];
		}
		if(cnt[2]>n/2)
		{	
			sort(s2+1,s2+cnt[2]+1);
			for(int j=cnt[2];j>(n/2);j--) ans+=s2[j];
		}
		if(cnt[3]>n/2)
		{	
			sort(s3+1,s3+cnt[3]+1);
			for(int j=cnt[3];j>(n/2);j--) ans+=s3[j];
		}
		printf("%d\n",ans);
		
	}
	return 0;	
} 
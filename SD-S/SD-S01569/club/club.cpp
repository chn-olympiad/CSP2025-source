#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,p,ans;
vector<int>vec[3];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();ans=0;p=-1;
		for(int i=0;i<3;i++)vec[i].clear();
		for(int i=1,a,b,c;i<=n;i++)
		{
			a=read();b=read();c=read();
			if(a>=b&&a>=c){vec[0].push_back(a-max(b,c));ans+=a;}
			if(b>a&&b>=c){vec[1].push_back(b-max(a,c));ans+=b;}
			if(c>a&&c>b){vec[2].push_back(c-max(a,b));ans+=c;}
		}
		for(int i=0;i<3;i++)if(vec[i].size()>n/2)p=i;
		if(~p)
		{
			sort(vec[p].begin(),vec[p].end());
			for(int i=0;i<vec[p].size()-n/2;i++)ans-=vec[p][i];
		}
		printf("%lld\n",ans);
	}
}
/*
Ren5Jie4Di4Ling5%
14:50 solve it.
*/

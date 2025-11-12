#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fre(a) freopen(#a".in","r",stdin),freopen(#a".out","w",stdout)
const ll maxn=100009;
ll T,n,mx,ans,s[maxn][3];
ll pi;
ll siz[3],p[maxn][3],a[maxn];
void init()
{
	pi=3;
	siz[0]=siz[1]=siz[2]=0;
	ans=0;
}
ll get(ll x)
{
	return s[x][0]+s[x][1]+s[x][2]-max(max(s[x][0],s[x][1]),s[x][2])-min(min(s[x][0],s[x][1]),s[x][2]);
}
int main()
{
	fre(club);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		init();
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			mx=max(max(s[i][0],s[i][1]),s[i][2]);
			if(s[i][0]==mx)
			{
				siz[0]++;
				p[siz[0]][0]=i;
			}
			else if(s[i][1]==mx)
			{
				siz[1]++;
				p[siz[1]][1]=i;
			}
			else
			{
				siz[2]++;
				p[siz[2]][2]=i;
			}
			ans+=mx;
		}
		if(siz[0]>n/2)
		{
			pi=0;
		}
		else if(siz[1]>n/2)
		{
			pi=1;
		}
		else if(siz[2]>n/2)
		{
			pi=2;
		}
		if(pi!=3)
		{
			for(ll i=1;i<=siz[pi];i++)
			{
				a[i]=s[p[i][pi]][pi]-get(p[i][pi]);
			}
			sort(a+1,a+siz[pi]+1);
			for(ll i=n/2+1;i<=siz[pi];i++)
			{
				ans-=a[i-n/2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define F(i,l,r) for(int i=l;i<=r;++i)
#define min(a,b) ((a)>(b)?(a):(b))
//#define max(a,b) ((a)<(b)?(a):(b))
#define endl putchar('\n')
#define air putchar(' ')
using namespace std;
inline int read()
{
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+10;
int a[10][N];
int n,t;
vector<int>mp[10];
struct sc{
	int cha,i;
};
sc s[N];
bool cmp(sc x,sc y)
{
	return x.cha<y.cha;
}
void print(int x)
{
	printf("%d",x);endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		memset(s,0,sizeof s);
		memset(mp,0,sizeof mp);
		n=read();
		F(i,1,n) F(j,1,3) a[j][i]=read();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){ mp[1].push_back(i);ans+=a[1][i];}
			else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){ mp[2].push_back(i);ans+=a[2][i];}
			else if(a[3][i]>=a[2][i]&&a[3][i]>=a[1][i]){ mp[3].push_back(i);ans+=a[3][i];}
		}
		if(mp[1].size()<=n/2&&mp[2].size()<=n/2&&mp[3].size()<=n/2) print(ans);
		else
		{
			
			if(mp[1].size()>n/2){
				for(int i=0;i<mp[1].size();i++){ s[i].cha=a[1][mp[1][i]]-max(a[2][mp[1][i]],a[3][mp[1][i]]),s[i].i=mp[1][i];}
				sort(s,s+mp[1].size(),cmp);
				for(int i=0;i<mp[1].size()-n/2;i++)ans-=s[i].cha;print(ans);
			}
			if(mp[2].size()>n/2){
				for(int i=0;i<mp[2].size();i++){ s[i].cha=a[2][mp[2][i]]-max(a[1][mp[2][i]],a[3][mp[2][i]]),s[i].i=mp[2][i];}
				sort(s,s+mp[2].size(),cmp);
				for(int i=0;i<mp[2].size()-n/2;i++) ans-=s[i].cha;print(ans);
			}
			if(mp[3].size()>n/2)
			{
				for(int i=0;i<mp[3].size();i++){ s[i].cha=a[3][mp[3][i]]-max(a[2][mp[3][i]],a[1][mp[3][i]]),s[i].i=mp[3][i];}
				sort(s,s+mp[3].size(),cmp);
				for(int i=0;i<mp[3].size()-n/2;i++) ans-=s[i].cha;print(ans);
			}
		}
	}
	return 0;
}
/*
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
ACACACACACACACACACACACACACACAC
*/

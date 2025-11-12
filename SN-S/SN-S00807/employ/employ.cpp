#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace Revi{
	const int N=5e5+5,P=998244353;
	int n,m,c[N],p[N],res;
	string s;
	bool vis[N];
	inline void work()
	{
		cin>>n>>m>>s;
		s='+'+s;
		for(int i=1;i<=n;i++) cin>>c[i];
		int tmp=0;
		for(int i=1;i<=n;i++) tmp+=(int)(s[i]-'0');
		if(tmp==n)
		{
			int ans=1;
			int cnt=0;
			bool f=0;
			for(int i=1;i<=n;i++)
			{
				if(c[i]!=0) ans=ans*(++cnt)%P;
				else if(!f)
				{
					ans=ans*(++cnt)%P;
					f=1;	
				} 
			}
			cout<<ans%P;
			return ;
		}
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		int cnt=0;
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(s[p[i]]=='1'&&now<c[p[i]]) cnt++;
			else now++;
		}
		//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
		if(cnt>=m) ans++;
		while(next_permutation(p+1,p+n+1))
		{
			//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
			cnt=0;
			now=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='1'&&now<c[p[i]]) cnt++;
				else now++;
			}
			if(cnt>=m)
			{
				ans++;
			}
		}
		cout<<ans;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	Revi::work();
	return 0;
 } 
 
 
 /*
 
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
 
 */

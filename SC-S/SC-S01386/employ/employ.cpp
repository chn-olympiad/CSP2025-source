#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,lim;
int p[N],c[N],jc[N],ans=0;
string s;
inline int add(int x,int y){return (x+y)>=mod?x+y-mod:x+y;}
void solve1()
{
	for(int i=1;i<=n;i++) p[i]=i;
	int sum1=0,sum2=0;
	ans=0;
	do{
		sum1=sum2=0;
		for(int i=1;i<=n;i++)
			if(s[i-1]=='0') sum1++;
			else
			{
				if(sum1>=c[p[i]]) sum1++;
				else sum2++; 
			}
		if(sum2>=m) ans=add(ans,1);
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
}
bool used[N];
void dfs(int u,int sum1,int sum2)
{
	if(sum2>=m) return ans=add(ans,jc[n-u+1]),void();
	if(sum1>lim) return ;
	if(u>n)
	{
		ans+=(sum2>=m);
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!used[i])
		{
			used[i]=1;
			if(sum1>=c[i]||s[u-1]=='0') dfs(u+1,sum1+1,sum2);
			else dfs(u+1,sum1,sum2+1);
			used[i]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;lim=n-m;
	cin>>s;
	jc[0]=1;
	for(int i=1;i<=n;i++) cin>>c[i],jc[i]=1ll*jc[i-1]*i%mod;
	if(n<=10) return solve1(),0;
	if(m==n)
	{
		bool flag=true;
		for(int i=0;i<n;i++) flag&=(s[i]=='1');
		for(int i=1;i<=n;i++) flag&=c[i];
		if(flag) cout<<jc[n];
		else cout<<"0";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int P=998244353,N=505;
string s;
int n,k,a[N],ans=1,d;
//void dfs(int dth,int cnt,int d)
//{
//	if(cnt==k)
//	{
//		ans++;
//		return ;
//	}
//}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	dfs(1,0);
	for(int i=n;i>=n-k+1;i++)
	{
		ans=(ans*i)%P;
	}
	for(int i=1;i<=k;i++)
	{
		d*=i;
	}
	ans=(ans*d)%P;
	cout<<ans<<'\n';
	
	
	return 0;
}
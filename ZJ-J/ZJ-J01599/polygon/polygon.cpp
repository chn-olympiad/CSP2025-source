#include<bits/stdc++.h>
#define int long long
#define P 998244353
using namespace std;
const int N=5005;
int n;
int a[N],ans;
void dfs(int st,int sum,int cnt)
{
//	printf("st=%d sum=%d cnt=%d\n",st,sum,cnt);
//	for(int i=1;i<=cnt;++i) cout<<p[i]<<" ";
//	cout<<"\n";
	if(cnt>n) return;
	if(cnt>=3&&sum>a[st-1]*2) ans++,ans%=P;
	for(int i=st;i<=n;++i) dfs(i+1,sum+a[i],cnt+1);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0);
	cout<<ans;
}        

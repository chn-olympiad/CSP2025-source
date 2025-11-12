#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int a[N][3],to[N],val[N];
void ATRI()
{
	int n;cin>>n;
	int ans=0,cnt[]{0,0,0};
	for(int i=1;i<=n;++i)
	{
		for(int k:{0,1,2})cin>>a[i][k];
		to[i]=max_element(a[i],a[i]+3)-a[i];
		ans+=a[i][to[i]],++cnt[to[i]];
	}
	for(int k:{0,1,2})if(cnt[k]>n/2)
	{
		int tot=0;
		for(int i=1;i<=n;++i)if(to[i]==k)
		{
			int mx=0;
			for(int o:{0,1,2})if(o!=k)mx=max(mx,a[i][o]);
			val[++tot]=a[i][to[i]]-mx;
		}
		sort(val+1,val+tot+1);
		for(int i=1;i<=cnt[k]-n/2;++i)ans-=val[i];
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;cin>>t;while(t--)ATRI();
	return 0;
}
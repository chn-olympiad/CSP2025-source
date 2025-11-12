#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5001];
void dfs(int id,int sum,int ma)
{
	if(id>=n)
	{
		if(sum>2*ma&&sum>0)ans++;
		return;
	}
	dfs(id+1,sum+a[id+1],max(a[id+1],ma));
	dfs(id+1,sum,ma);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,-1);
	cout<<ans<<endl;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
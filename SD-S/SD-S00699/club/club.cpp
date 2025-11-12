#include<bits/stdc++.h>
using namespace std;
int q[500001];
int a[500001];
int n,k;
int dfs(int l,int r,int s)
{
	if(s>r-l+1)
	{
		return 0;
	}
	int ans=0;
	int x=l;
	for(int i=l+s-1;i<=r;i++)
	{
		int cnt=(q[i]^q[i-s]);
		if(cnt==k)
		{
			ans++;
			ans+=dfs(x,i-s,s+1);
			x=i+1;
			i+=s;
			i--;
		}
	}
	return ans+dfs(x,r,s+1);
}
int main()
{
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		q[i]=(q[i-1]^a[i]);
	}
	int ans=0;
	ans=dfs(1,n,1);
	cout << ans;
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int main()
{
	freopen("xor,in","r",stdin);
	freopen("xor,out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int s = 0;
		int flag = 0;
		int f[500001] = {0};
		for(int j = i;j <= n;j++)
		{
			if(f[i] || f[j])
			{
				flag = 1;
				break;
			}
			s += a[i] ^ a[j];
			f[i] = 1;
			f[j] = 1;
		}
		if(s == k && !flag)
		{		
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

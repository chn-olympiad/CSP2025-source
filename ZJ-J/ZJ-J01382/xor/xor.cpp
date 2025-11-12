#include<bits/stdc++.h>
using namespace std;
int s[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s[i]=s[i-1]^x;
	}
	int l=1,r=1,m=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=m+1;j<=i;j++)
		{
			if(int(s[i]^s[j-1])==k)
			{
				ans++;
				m=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

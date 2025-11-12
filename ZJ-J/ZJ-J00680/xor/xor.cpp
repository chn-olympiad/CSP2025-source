#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a[500005];
int c[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnta=0,cnt=0;
	int i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	a[++cnta].push_back(c[1]);
	for(i=1;i<=n;i++)
	{
		bool flag=0;
		for(j=0;j<a[cnta].size();j++)
		{
			if(a[cnta][j]==k)
			{
				cnt++;
				flag=1;
				a[++cnta].push_back(c[i+1]);
				break;
			}
		}
		if(flag==0)
		{
			for(j=0;j<a[cnta].size();j++)
			{
				a[cnta][j]^=c[i+1];
			}
			a[cnta].push_back(c[i+1]);
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


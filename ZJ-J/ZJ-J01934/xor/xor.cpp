#include<bits/stdc++.h>
//#define int long long
//#define pqg priority_queue<int,vector<int>,greater>
//#define pql priority_queue<int,vector<int> >
using namespace std;
int n,k,ans;
int a[500005];
int b[500005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	int las=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=las;j--)
		{
			int w=b[j-1]^b[i];
			if(w==k)
			{
				ans++;
				las=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

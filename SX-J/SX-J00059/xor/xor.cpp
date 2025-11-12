#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	int b=v[1];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(b==v[i]) sum++;
		if(sum==n)
		{
			cout<<0;
			return 0;
		}
	}
	cout<<2;
	return 0;
}

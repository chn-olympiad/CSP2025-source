#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int n,k,ans=0,f=0;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i];
	}
	for(int i=1;i<=n;i++)
    {
    	int v=k;
		for(int j=i;j>=f;j--)
		{
//			cout << v;
			v=(v)^(a[j]);
			if(v==0)
			{
				f=j+1;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}


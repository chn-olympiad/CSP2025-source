#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long a[6000],n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    long long ans;
    for(int i=3;i<=n;i++)
    {
    	int num=1;
    	for(int j=0;j<i;j++)
    	{
    		num=num*(n-j);
		}
		for(int j=0;j<num;j++)
		{
			ans++;
		}
	}
    cout<<ans;
    return 0;
}

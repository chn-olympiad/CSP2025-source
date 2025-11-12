#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long a[10000],n,k;
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int maxn=-1e9;
    for(int i=1;i<=n+k-1;i++)
    {
    	int nown=a[i];
    	for(int j=i+1;j<=i+k-1;j++)
    	{
    		nown^=a[j];
    		maxn=max(nown,maxn);
		}
	}
    cout<<maxn;
    return 0;
}

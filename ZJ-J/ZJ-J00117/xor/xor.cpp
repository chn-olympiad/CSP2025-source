#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	int x=a[i],j=i-1;
    	while(x!=k&&j>0)
    	{
    		x=(x^a[j]);
    		j--;
		}
		if(x==k)f[i]=f[j]+1;
		f[i]=max(f[i],f[i-1]);
	}
	cout<<f[n];
	return 0;
}


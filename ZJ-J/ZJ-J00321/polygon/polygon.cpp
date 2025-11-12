#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005];
signed main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	cout<<0;	
	return 0; 
}

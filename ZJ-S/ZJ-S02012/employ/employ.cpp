#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int a [N];
signed main ()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>> n;
	int ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%998244353;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
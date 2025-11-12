#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=(ans*i)%MOD;
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
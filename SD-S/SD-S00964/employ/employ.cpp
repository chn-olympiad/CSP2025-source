#include <bits/stdc++.h>
using namespace std;
long long cnt=1,a;
string s;
int n,m,x;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cnt=(cnt*i)%998244353;
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

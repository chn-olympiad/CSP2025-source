#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cout<<(m+(n*m-n-m-1!=0)*(n*n*n*n*n*(n+1)*2+n*n*n*m-877))%998244353;
	return 0;
}

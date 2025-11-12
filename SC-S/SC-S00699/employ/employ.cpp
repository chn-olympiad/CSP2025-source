#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,sum=1;
	string s;
	cin>>n>>m>>s;
	long long L=s.size();
	for(int i=1;i<=n;i++)
	{
		sum*=i%MOD;
		sum%=MOD;
	}
	cout<<sum;
	//一托，只能希望数据水了 
	return 0;
}
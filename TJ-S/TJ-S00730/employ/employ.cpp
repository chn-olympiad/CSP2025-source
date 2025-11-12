#include <iostream>
using namespace std;
const long long mod = 998244353;
bool flag;
long n,m;
char a[1000];
long b[1000];
long long jie(long long x)
{
	long long ans = 1;
	for(long long i = 1;i <= x;i++)
		ans = (ans*i)%mod;
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long i = 1;i <= n;i++)
		cin>>a[i];
	for(long i = 1;i <= n;i++)
		cin>>b[i];
		flag = true;
	for(long i = 1;i <= n;i++)
		if(a[i] == '0')
			flag = false;
	if(flag)
	{
		cout<<jie(n)<<endl;
		return 0;
	}
	return 0;
}

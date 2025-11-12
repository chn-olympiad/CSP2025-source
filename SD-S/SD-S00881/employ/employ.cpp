#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
void solve_A()
{
	int sum=1;
	for(int i=2;i<=n;i++)
		sum=(sum*i)%mod;
	cout<<sum<<endl;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	solve_A();
	return 0;
}


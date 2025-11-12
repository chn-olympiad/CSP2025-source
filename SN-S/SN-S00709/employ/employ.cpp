#include <bits/stdc++.h>
using namespace std;
const long long k=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	unsigned long long n,m;
	string f;
	unsigned long long q[501];
	unsigned ans=1;
	cin>>n>>m;
	cin>>f;
	for(int i=0;i<n;i++)
	{
		cin>>q[i];
	}
//	if(m==1)
//	sort(q,q+n);
//	int g=q[m-1];//for the manpower,g is the highest giving up man number before
//	
	for(unsigned long long i=1;i<=n;i++)
	{
		unsigned long long op=i%k;
		ans*=i;
		ans%=k;
	}
	cout<<ans;
	return 0;
}

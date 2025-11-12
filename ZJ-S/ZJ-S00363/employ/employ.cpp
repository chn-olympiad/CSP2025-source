#include<bits/stdc++.h>
using namespace std;
const int N=1000,mod=998244353;
long long n,m;
string s;
long long c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>0) sum++;
	}
	if(sum<m-1) cout<<0;
	else{
		long long ans=1;
		for(long long i=1;i<=n;i++){
			ans=((long long)ans*i%mod)%mod;
		}
		cout<<ans;
	}
	return 0;
}

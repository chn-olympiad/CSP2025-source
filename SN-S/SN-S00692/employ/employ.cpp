#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,c[510];
string s;
long long cnt[510];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	cnt[1]=1;
	for(int i=2;i<=n;i++)
	{
		cnt[i]=cnt[i-1]*i%M;
		//cout<<cnt[i]<<"\n";
	}
	cout<<cnt[n]%M<<"\n";
	return 0;
}

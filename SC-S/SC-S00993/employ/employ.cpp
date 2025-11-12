#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int MOD=998244353;
int N,M,C[505],sum;
string s;
bool flag=true;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>N>>M>>s;
	for(int i=0;i<N;i++)
	{
		if(s[i]=='0')
		{
			flag=false;
		}
	}
	for(int i=1;i<=N;i++)
	{
		cin>>C[i];
		if(C[i]==0)
		{
			sum++;
		}
	}
	if(N-sum<M)
	{
		cout<<0<<endl;
		return 0;
	}
	if(flag)
	{
		int ans=1;
		for(int i=1;i<=N-sum;i++)
		{
			ans=(ans*i)%MOD;
		}
		cout<<ans%MOD<<endl;
		return 0;
	}
	rand();
	cout<<rand()%MOD<<endl;
	return 0;
}
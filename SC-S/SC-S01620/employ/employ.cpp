#include<bits/stdc++.h>
#define fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLL=pair<ll,ll>;
using PLI=pair<ll,int>;
using ve=vector<int>;
mt19937_64 UL(time(0));
const int N=500+9,mod=998244353;
int n,m,p,k,T=1;
string s;
int c[N];
ve pr;
//void solve_a()
//{
//	int quit_cnt=0;
//	for(int i=1;i<=n;i++)if(c[i]==0)quit_cnt++;
//	if(quit_cnt+m>n)//太多胆小鬼了
//	{
//		cout<<"0\n";
//		return;
//	}
//	ll ans=1;
//	for(ll i=1;i<=2*n;i++)
//	{ans=(i*ans)%mod;cout<<i<<' '<<ans<<'\n';}
//	cout<<ans<<'\n';
//}
void solve(int tcase)
{
	cin>>n>>m;
	cin>>s;
	s="U"+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)pr.push_back(i);
//	bool CASEA=1;
//	for(int i=1;i<=n;i++)
//	{
//		if(s[i]=='0')
//		{
//			CASEA=0;
//			break;
//		}
//	}
//	if(CASEA)
//	{
//		solve_a();
//		return;
//	}
	ll ans=0;
	do{
//		for(auto x:pr)cout<<x<<" ";
//		cout<<'\n';
		int fail_cnt=0,success_cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0'||fail_cnt>=c[pr[i-1]])
			{
				fail_cnt++;
				continue;
			}
			success_cnt++;
		}
		if(success_cnt>=m)ans++;
	}while(next_permutation(pr.begin(),pr.end()));
	ans%=mod;
	cout<<ans<<'\n';
}
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fopen("employ");
//	cin>>T;
	for(int i=1;i<=T;i++)
	{
		solve(i);
	}
	return 0;
}
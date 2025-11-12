#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e9+7;
const int mod=998244353;
ll inv_fact[505],fact[505];
int yuangong[505];
int next[505];
int n;
int k;
int m_cnt;
int m_t;
int yongyou[505];
ll qpow(int n,int e)
{
	 ll ans=1;
	 while(e)
	 {
	 	if(e&1) ans=ans*n%mod;
	 	n=n*n;
	 	e>>=1;
	 }
	 return ans;
}
void Build()
{
	fact[0]=1;
	for(int i=1;i<=n;i++)
	{
		fact[i]=fact[i-1]*ll(i)%mod;
	}
	inv_fact[n]=qpow(fact[n],N-2);
	for(int i=n-1;i>=0;i--)
	{
		inv_fact[i]=inv_fact[i+1]*(ll)(i+1)%mod;
	}
}
void make(s)
{
	int cnt=0;
	for(int i=1;i<=s.length();i++)
	{
		if(s[i]=='1') {
			if(cnt>m_cnt) m_cnt=cnt;
			next[++k]=cnt;
			cnt=-1;
		}
		cnt++;
	}
	sort(next+1,next+1+k,cmp);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	make(s);
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		if(t>m_t) m_t=t;
		yuangong[t]++;
	}
	Build()
	for(int i=0,j=0,all=n;i<=m_cnt;i++)
	{
		if(next[i]==0) continue;
		while(j<=i){
			all-=yuangong[j];
			j++;
		}
		yongyou[i]=all;
	}
	ll ans=0;
	for(int k=m)
	for(int i=m_cnt;i>=0;i--){
		if(next[i]==0) continue;
		ans=(ans+)
	}
	return 0;
}

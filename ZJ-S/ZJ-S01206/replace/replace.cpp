#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fi first
#define se second
#define endl '\n'
#define start_multitest\
	int tests;\
	cin>>tests;\
	for(int test_case=1;test_case<=tests;test_case++)[&]()->int\
	{
#define end_multitest\
		return 0;\
	}();
constexpr ll base=1145141,mod=998244353;
constexpr int N=10000,L=1000010;
int n,q;
int Len[N];
pair<ll,ll>A[N];
ll H1[N],H2[N];
ll Pow[L];
ll _hash(string S)
{
	S="@"+S;
	ll res=0;
	for(int i=1;i<=(int)S.size()-1;i++)
		res=(res*base+S[i])%mod;
	return res;
}
void get_hash(string S,ll *H)
{
	S="@"+S;
	for(int i=1;i<=(int)S.size()-1;i++)
		H[i]=(H[i-1]*base+S[i])%mod;
}
ll get(ll *H,int l,int r)
{
	return (H[r]-H[l-1]*Pow[r-l+1]%mod+mod)%mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	Pow[0]=1;
	for(int i=1;i<=100000;i++)Pow[i]=Pow[i-1]*base%mod;
	for(int i=1;i<=n;i++)
	{
		string S1,S2;
		cin>>S1>>S2;
		Len[i]=S1.size();
		A[i]={_hash(S1),_hash(S2)};
	}
	while(q--)
	{
		string T1,T2;
		cin>>T1>>T2;
		int l=T1.size(),ans=0;
		get_hash(T1,H1);
		get_hash(T2,H2);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=l-Len[i]+1;j++)
				if(get(H1,1,j-1)==get(H2,1,j-1)&&get(H1,j+Len[i],l)==get(H2,j+Len[i],l)&&
					get(H1,j,j+Len[i]-1)==A[i].fi&&get(H2,j,j+Len[i]-1)==A[i].se)
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
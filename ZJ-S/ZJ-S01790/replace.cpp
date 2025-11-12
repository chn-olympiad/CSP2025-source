#include <bits/stdc++.h>
using namespace std;

using ull=unsigned long long;
using ll=long long;
const int base1=998244353;
const int base2=19491001;
const int N=200005;
string s[N][2],t[2];
pair<int,int> sp[N];
pair<int,int> find(string su,string sv)
{
	int len=su.size();
	int L=0,R=0;
	for(int j=0;j<len;j++)
	{
		if(su[j]!=sv[j])
		{
			L=j;
			break;
		}
	}
	for(int j=len-1;j>=0;j--)
	{
		if(su[j]!=sv[j])
		{
			R=j+1;
			break;
		}
	}
	return make_pair(L,R);
}
ull Pow(ull x,ull y)
{
	ull res=1;
	while(y)
	{
		if(y&1)x=x*x;
		res=res*x;
		y>>=1;
	}
	return res;
}
vector<ull> build_hash(string &ss,ull base)
{
	int len=ss.size();
	vector<ull> wchash(len,0);
	for(int i=0;i<len;i++)
	{
		wchash[i]=(ss[i]-'a')*Pow(base,i);
		if(i>0)wchash[i]+=wchash[i-1];
	}
	return wchash;
}
ull query_hash(vector<ull> &wchash,ull base,int l,int r)
{
	return (wchash[l+r-1]-(l>1?wchash[l-1]:0))*Pow(base,N-l);
}
vector<ull> shash[2][N][2];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,q;
	cin>>n>>q;
	bool A=(q==1);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		sp[i]=find(s[i][0],s[i][1]);
		
//		shash[0][i][0]=build_hash(s[i][0],base1);
//		shash[0][i][1]=build_hash(s[i][1],base1);
//		shash[1][i][0]=build_hash(s[i][0],base2);
//		shash[1][i][1]=build_hash(s[i][1],base2);
	}
	while(q--)
	{
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()){cout<<0<<'\n';continue;}
		auto [L1,R1]=find(t[0],t[1]);
		
		vector<ull> thash[2][2];
//		thash[0][0]=build_hash(t[0],base1);
//		thash[0][1]=build_hash(t[1],base1);
//		thash[1][0]=build_hash(t[0],base2);
//		thash[1][1]=build_hash(t[1],base2);
		
		int len1=t[0].size(),ans=0;
		for(int j=1;j<=n;j++)
		{
			auto [L2,R2]=sp[j];
			int len2=s[j][0].size();
			if(R1-L1>len2||L1<L2||len1-R1<len2-R2)continue;
			
			if(t[0].substr(L1,R1-L1)!=s[j][0].substr(L2,R2-L2))continue;
//			ull qwq1=query_hash(thash[0][0],base1,L1,R1-L1);
//			ull qwq2=query_hash(shash[0][j][0],base1,L2,R2-L2);
//			cout<<qwq1<<' '<<qwq2<<'\n';
			if(t[1].substr(L1,R1-L1)!=s[j][1].substr(L2,R2-L2))continue;
			if(s[j][0].substr(0,L2)!=t[0].substr(L1-L2,L2))continue;
			if(s[j][0].substr(R2,len2-R2)!=t[0].substr(R1,len2-R2))continue;
			
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
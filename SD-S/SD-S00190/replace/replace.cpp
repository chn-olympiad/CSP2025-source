#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N=2e5+10;
const int M=5e6+10;
const int inf=0x3f3f3f3f3f3f3f3f;
const int base=29;
const int p=998244353;
int n,q;
int len[N];
int num1[N],num2[N];
int sum1[M],sum2[M];
int pw[M];
int get1(int l,int r)
{
	if(l>r) return 0;
	int res=sum1[r]-sum1[l-1]*pw[r-l+1]%p;
	res=(res+p)%p;
	return res;
}
int get2(int l,int r)
{
	if(l>r) return 0;
	int res=sum2[r]-sum2[l-1]*pw[r-l+1]%p;
	res=(res+p)%p;
	return res;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base%p;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		len[i]=s1.size();
		for(int j=0;j<s1.size();j++) num1[i]=(num1[i]*base%p+s1[j]-'a'+1)%p;
		for(int j=0;j<s2.size();j++) num2[i]=(num2[i]*base%p+s2[j]-'a'+1)%p;
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		t1=' '+t1,t2=' '+t2;
		for(int i=1;i<t1.size();i++) sum1[i]=(sum1[i-1]*base%p+t1[i]-'a'+1)%p;
		for(int i=1;i<t2.size();i++) sum2[i]=(sum2[i-1]*base%p+t2[i]-'a'+1)%p;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j+len[i]-1<t1.size();j++)
			{
				if(get1(0,j-1)==get2(0,j-1)&&get1(j,j+len[i]-1)==num1[i]&&get2(j,j+len[i]-1)==num2[i]&&get1(j+len[i],t1.size()-1)==get2(j+len[i],t1.size()-1)) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

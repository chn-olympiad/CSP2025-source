#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7,N=200005;
int n,q;
map<int,int> rep;
int h1[N],h2[N];


int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a;
		a%=mod;
		b>>=1;
	}
	return res;
}


int calc_hash(string s)
{
	int ret=0;
	for(int i=0;i<s.size();i++)
	{
		ret*=30;
		ret+=(s[i]-'a'+1);
		ret%=mod;
	}
	return ret;
}

void solve(string t1,string t2)
{
	int l1=t1.size(),l2=t2.size();
	t1="#"+t1;
	t2="#"+t2;
	for(int i=1;i<=l1;i++)
	{
		h1[i]=h1[i-1]*30;
		h1[i]+=(t1[i]-'a'+1);
		h1[i]%=mod;
		//cout<<"hash"<<h1[i]<<endl;
	}
	for(int i=1;i<=l2;i++)
	{
		h2[i]=h2[i-1]*30;
		h2[i]+=(t2[i]-'a'+1);
		h2[i]%=mod;
		//cout<<h2[i]<<endl;
	}

	int ans=0;
	for(int i=1;i<=min(l1,l2);i++)
	{
		for(int j=i;j<=min(l1,l2);j++)
		{
			int x1=h1[i-1];
			int y1=(h1[j]-h1[i-1]*qpow(30,j-i+1))%mod;
			int z1=(h1[l1]-h1[j]*qpow(30,l1-j))%mod;

			int x2=h2[i-1];
			int y2=(h2[j]-h2[i-1]*qpow(30,j-i+1))%mod;
			int z2=(h2[l2]-h2[j]*qpow(30,l2-j))%mod;

			
			//cout<<x1<<" "<<y1<<" "<<z1<<" "<<x2<<" "<<y2<<" "<<z2<<endl;
			if(x1==x2 && z1==z2 && rep.find(y1)!=rep.end() && rep[y1]==y2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//cout<<calc_hash("cx")<<endl;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
		rep[calc_hash(s1)]=calc_hash(s2);
	}
	for(int i=1;i<=q;i++)
	{
		string t1,t2;
		cin>>t1>>t2;
		solve(t1,t2);
	}

	
}
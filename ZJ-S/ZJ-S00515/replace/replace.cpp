#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,S=1e6+5;
using ull=unsigned long long;
int n,q;
string s[N],t[N];
ull hshs[N],hsht[N],hsha[S],hshb,B[N];
ull bs=0;
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
ull gethsh(ull *hsh,int l,int r)
{
	if(l>r)
		return 0;
	return hsh[r]-hsh[l-1]*B[r-l+1];
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	bs=mt()%900+1000;
	B[0]=1;
	for(int i=1;i<N;i++)
		B[i]=B[i-1]*bs;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>t[i];
		hshs[i]=0;
		for(auto j:s[i])
			hshs[i]=hshs[i]*bs+j;
		hsht[i]=0;
		for(auto j:t[i])
			hsht[i]=hsht[i]*bs+t[i][j];
	}
	while(q--)
	{
		string a,b;
		cin>>a>>b;
		hshb=0;
		for(int i=0;i<a.length();i++)
			hsha[i]=(i?hsha[i-1]:0)*bs+a[i];
		for(int i=0;i<b.length();i++)
			hshb=hshb*bs+b[i];
		int ans=0;
		int lena=a.length();
		for(int i=0;i<lena;i++)
			for(int j=1;j<=n;j++)
			{
				int ed=i+s[j].length()-1;
				if(ed<lena&&gethsh(hsha,i,ed)==hshs[j])
					if((i?hsha[i-1]:0)*B[lena-i]+hsht[j]*B[lena-ed-1]+gethsh(hsha,ed+1,lena-1)==hshb)
						ans++;
			}
		cout<<ans<<'\n';
	}
	return 0;
}

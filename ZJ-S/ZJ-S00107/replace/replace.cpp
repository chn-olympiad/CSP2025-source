#include <bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=1e9+7;
const int N=2e5+5;
const int L=5e6+5;
int n,q,len[N];
string s1[N],s2[N],t1,t2;
int ha[N],hb[N],h1[L],h2[L];
int kk[L],ka[N],kb[N],lp[N],in[N];
int tot;
vector<int> kkk[N];
map<int,int> mp;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("replace1.in","r",stdin);
//	freopen("replace1.out","w",stdout);
	kk[0]=1;
	for(int i=1;i<=5e6;++i) kk[i]=kk[i-1]*29%Mod;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
		int l=s1[i].length();
		len[i]=l;
		for(int j=0;j<l;++j) ha[i]=(ha[i]*29+s1[i][j]-'a'+1)%Mod;
		for(int j=0;j<l;++j) hb[i]=(hb[i]*29+s2[i][j]-'a'+1)%Mod;
		int t=0,y=l-1;
		while(s1[i][t]==s2[i][t]) t++;
		while(s1[i][y]==s2[i][y]) y--;
		lp[i]=y-t+1,in[i]=t;
		for(int j=t;j<=y;++j) ka[i]=(ka[i]*29+s1[i][j]-'a'+1)%Mod;
		for(int j=t;j<=y;++j) kb[i]=(kb[i]*29+s2[i][j]-'a'+1)%Mod;
		if(mp[ka[i]]==0) mp[ka[i]]=++tot;
		kkk[mp[ka[i]]].push_back(i);
	}
	while(q--)
	{
		cin>>t1>>t2;
		int l=t1.length();
		h1[1]=t1[0]-'a'+1,h2[1]=t2[0]-'a'+1;
		for(int i=2;i<=l;++i) h1[i]=(h1[i-1]*29+t1[i-1]-'a'+1)%Mod;
		for(int i=2;i<=l;++i) h2[i]=(h2[i-1]*29+t2[i-1]-'a'+1)%Mod;
		int t=0,y=l-1;
		while(t1[t]==t2[t]) t++;
		while(t1[y]==t2[y]) y--;
		int ll=y-t+1;
		int key1=(h1[y+1]-h1[t]*kk[ll]%Mod+Mod)%Mod,key2=(h2[y+1]-h2[t]*kk[ll]%Mod+Mod)%Mod;
		int cnt=0;
		for(auto i:kkk[mp[key1]])
		{
			int o=kk[len[i]];
			if(ll==lp[i]&&key1==ka[i]&&key2==kb[i]&&t>=in[i])
			{
				int j=t-in[i];
				if((h1[j+len[i]]-h1[j]*o%Mod+Mod)%Mod==ha[i]&&(h2[j+len[i]]-h2[j]*o%Mod+Mod)%Mod==hb[i]&&h1[j]==h2[j]&&(h1[l]-h1[j+len[i]]*kk[l-j-len[i]]%Mod+Mod)%Mod==(h2[l]-h2[j+len[i]]*kk[l-j-len[i]]%Mod+Mod)%Mod) cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}

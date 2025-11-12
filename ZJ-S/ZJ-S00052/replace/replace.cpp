#include<bits/stdc++.h>
using namespace std;
const int mod1=998244353,mod2=1e9+7,base=131;
int trie[5000010][27],hp[200001][2],hq[200001][2],p[200001];
vector<int>num[5000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,cnt,pos,len,front,back,hp0,hq0,hp1,hq1,ans;
	string s,t;
	cin>>n>>q;
	cnt=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s>>t;
		len=s.size();
		front=-1;
		back=len;
		while(s[front+1]==t[front+1])
			front++;
		while(s[back-1]==t[back-1])
			back--;
		if(front<back)
		{
			for(int j=front+1;j<=back-1;j++)
			{
				hp[i][0]=(1ll*hp[i][0]*base+s[j])%mod1;
				hq[i][0]=(1ll*hq[i][0]*base+s[j])%mod2;
				hp[i][1]=(1ll*hp[i][1]*base+t[j])%mod1;
				hq[i][1]=(1ll*hq[i][1]*base+t[j])%mod2;
			}
			pos=0;
			for(int j=front;j>=0;j--)
			{
				if(trie[pos][s[j]-96]==0)
					trie[pos][s[j]-96]=++cnt;
				pos=trie[pos][s[j]-96];
			}
			num[pos].push_back(i);
			pos=1;
			for(int j=back;j<len;j++)
			{
				if(trie[pos][s[j]-96]==0)
					trie[pos][s[j]-96]=++cnt;
				pos=trie[pos][s[j]-96];
			}
			num[pos].push_back(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		len=s.size();
		if(t.size()!=len)
		{
			cout<<0<<endl;
			continue;
		}
		front=-1;
		back=len;
		while(s[front+1]==t[front+1])
			front++;
		while(s[back-1]==t[back-1])
			back--;
		hp0=hq0=hp1=hq1=0;
		for(int j=front+1;j<=back-1;j++)
		{
			hp0=(1ll*hp0*base+s[j])%mod1;
			hq0=(1ll*hq0*base+s[j])%mod2;
			hp1=(1ll*hp1*base+t[j])%mod1;
			hq1=(1ll*hq1*base+t[j])%mod2;
		}
		ans=0;
		pos=0;
		for(int k=0;k<num[pos].size();k++)
			if(hp[num[pos][k]][0]==hp0&&hq[num[pos][k]][0]==hq0)
				p[num[pos][k]]=i;
		for(int j=front;j>=0;j--)
		{
			if(trie[pos][s[j]-96]==0)
				break;
			pos=trie[pos][s[j]-96];
			for(int k=0;k<num[pos].size();k++)
				if(hp[num[pos][k]][0]==hp0&&hq[num[pos][k]][0]==hq0)
					p[num[pos][k]]=i;
		}
		pos=1;
		for(int k=0;k<num[pos].size();k++)
			if(hp[num[pos][k]][1]==hp1&&hq[num[pos][k]][1]==hq1&&p[num[pos][k]]==i)
				ans++;
		for(int j=back;j<len;j++)
		{
			if(trie[pos][s[j]-96]==0)
				break;
			pos=trie[pos][s[j]-96];
			for(int k=0;k<num[pos].size();k++)
				if(hp[num[pos][k]][1]==hp1&&hq[num[pos][k]][1]==hq1&&p[num[pos][k]]==i)
					ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

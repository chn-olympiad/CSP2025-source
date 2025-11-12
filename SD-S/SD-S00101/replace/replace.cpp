#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
typedef unsigned long long ull;
typedef long long ll;
const ull N=200010,L=6000010;
const ull bs=37,md=998244353;
typedef std::pair<ull,ull> P;
ull n,q;
char s[L],t[L];
ull ln;
ull l,r,hs1,hs2;
ull calc()
{
	hs1=hs2=0;
	l=1;r=ln;
	while(l<=ln&&s[l]==t[l]) ++l;
	while(r>=1&&s[r]==t[r]) --r;
	if(l>ln) return 0;
	for(ull i(l);i<=r;++i) hs1=(hs1*bs+s[i]-'a')%md;
	for(ull i(l);i<=r;++i) hs2=(hs2*bs+t[i]-'a')%md;
	return 1;
}
std::map<P,P> mp;
bool vis[L];
std::vector<ull> pr[L];
ull tot;ull sn[L][28];
ull ins(ull u,ull l,ull r)
{
	if(l>=r)
	{
		for(ull i(l);i>=r;--i)
		{
			ull& v=sn[u][s[i]-'a'];
			if(!v) v=++tot;
			u=v;
		}
		return u;
	}
	else
	{
		for(ull i(l);i<=r;++i)
		{
			ull& v=sn[u][s[i]-'a'];
			if(!v) v=++tot;
			u=v;
		}
		return u;
	}
}
ull qry(ull u,ull x,ull l,ull r)
{
	ull tx=x;
	vis[x]=1;
	for(ull i(r+1);i<=ln;++i)
	{
		if(!sn[x][s[i]-'a']) break;
		x=sn[x][s[i]-'a'];
		vis[x]=1;
	}
	
	ull ans=0;
	for(ull v:pr[u]) if(vis[v]) ++ans;
	for(ull i(l-1);i;--i)
	{
		if(!sn[u][s[i]-'a']) break;
		u=sn[u][s[i]-'a'];
		for(ull v:pr[u]) if(vis[v]) ++ans;
	}
	
	x=tx;
	vis[x]=0;
	for(ull i(r+1);i<=ln;++i)
	{
		if(!sn[x][s[i]-'a']) break;
		x=sn[x][s[i]-'a'];
		vis[x]=0;
	}
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%llu%llu",&n,&q);
	for(ull i(1);i<=n;++i)
	{
		scanf("%s%s",s+1,t+1);
		ln=strlen(s+1);
		if(!calc()) continue;
		if(mp.find(P(hs1,hs2))==mp.end())
		{
			mp[P(hs1,hs2)]=P(tot+1,tot+2);
			tot+=2;
		}
		ull rt1=mp[P(hs1,hs2)].first,rt2=mp[P(hs1,hs2)].second;
//		printf("%llu;%llu\n",l,r);
		ull x=l>1?ins(rt1,l-1,1):rt1,y=r<ln?ins(rt2,r+1,ln):rt2;
		pr[x].push_back(y);
	}
	for(ull i(1);i<=q;++i)
	{
		scanf("%s%s",s+1,t+1);
		ln=strlen(s+1);
		if(strlen(t+1)!=ln)
		{
			puts("0");
			continue;
		}
		calc();
		if(mp.find(P(hs1,hs2))==mp.end())
		{
			puts("0");
			continue;
		}
		ull rt1=mp[P(hs1,hs2)].first,rt2=mp[P(hs1,hs2)].second;
		printf("%llu\n",qry(rt1,rt2,l,r));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// remember! : only use O(n) or O(1)
// split (u in sub_v,x in sub_y) to {add (u,x in sub_y);qry (u in sub_v,x)}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/

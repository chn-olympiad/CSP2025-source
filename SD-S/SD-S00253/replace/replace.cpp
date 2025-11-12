#include <bits/stdc++.h>
using namespace std;
const int N = 5e6+10, P = 31;
int n, q;
char s1[N], s2[N];
typedef unsigned long long ull;
ull temp[N], hs[N], hs2[N], p[N];
bool len[N];
vector<pair<ull,int> > v[N];
vector<int> vec;
ull get(int l,int r)
{
	l++, r++;
	return hs[r]-hs[l-1]*p[r-l+1];
}
ull get2(int l,int r)
{
	l++, r++;
	return hs2[r]-hs2[l-1]*p[r-l+1];
}
void wrt(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) wrt(x/10);
	putchar('0'+x%10);
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0] = 1;
	for(int i=1;i<=5e6+3;i++) p[i]=p[i-1]*P;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		if(i!=1) scanf("%s %s",&s1,&s2);
		else cin>>s1>>s2;
		ull V = 0, v2 = 0;
		int l1 = strlen(s1);
		for(int j=0;j<l1;j++) V=V*P+s1[j]-'a'+1;
		for(int j=0;j<l1;j++) v2=v2*P+s2[j]-'a'+1;
		temp[i] = v2;
		len[l1] = 1;
		v[l1].push_back({V,i});
	}
	for(int i=1;i<=5e6+3;i++) if(len[i]) vec.push_back(i),sort(v[i].begin(),v[i].end());
	while(q--)
	{
		scanf("%s %s",&s1,&s2);
		int ans = 0;
		int l1 = strlen(s1);
		for(int j=0;j<l1;j++) hs[j+1] = hs[j]*P+s1[j]-'a'+1;
		for(int j=0;j<l1;j++) hs2[j+1] = hs2[j]*P+s2[j]-'a'+1;
		int mx = 0, mi=l1;
		for(int j=0;j<l1;j++)
			if(s1[j]!=s2[j]) mi=min(mi,j), mx=max(mx,j);
		for(int i=0;i<=mi;i++)
		{
			for(int j : vec)
			{
				if(i+j-1>=l1||i+j-1<mx) continue;
				int p1 = lower_bound(v[j].begin(),v[j].end(),make_pair(get(i,i+j-1),0))-v[j].begin();
				int p2 = upper_bound(v[j].begin(),v[j].end(),make_pair(get(i,i+j-1)+1,0))-v[j].begin();
				for(int k=p1;k<p2;k++)
					if(temp[v[j][k].second]==get2(i,i+j-1)) ans++;
			}
		}
		wrt(ans);
		puts("");
	}
	return 0;
}


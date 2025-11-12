//SN-S00493 PR++ 47 GXYZ
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5,p=299989,M=5e6+5;
int n,q,mx[N],mn[N],len[N],cnt;
ull vl[N],vr[N],v1[N],v2[N],vtl[M],vtr[M];
string s1[N],s2[N];
vector<int> ve[N];
map<pair<ull,ull>,int> mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		if(s1[i]==s2[i]) continue;
		len[i]=s1[i].size(),mn[i]=len[i];
		for(int j=1;j<=len[i];j++)
		{
			if(s1[i][j-1]!=s2[i][j-1]) mn[i]=min(mn[i],j),mx[i]=j;
		}
		for(int j=mn[i]-1;j>0;j--) vl[i]=vl[i]*p+s1[i][j-1];
		for(int j=mx[i]+1;j<=len[i];j++) vr[i]=vr[i]*p+s1[i][j-1];
		for(int j=mn[i];j<=mx[i];j++)
		{
			v1[i]=v1[i]*p+s1[i][j-1];
			v2[i]=v2[i]*p+s2[i][j-1];
		}
		pair<ull,ull> p1=make_pair(v1[i],v2[i]);
		if(!mp[p1]) mp[p1]=++cnt;
		ve[mp[p1]].push_back(i);
	}
	while(q--)
	{
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size())
		{
			printf("0\n");
			continue;
		}
		int len1=t1.size();
		int l=len1,r=0;
		for(int j=1;j<=len1;j++)
		{
			if(t1[j-1]!=t2[j-1]) l=min(l,j),r=j;
		}
		vtl[l]=vtr[r]=0;
		for(int j=l-1;j>0;j--) vtl[j]=vtl[j+1]*p+t1[j-1];
		for(int j=r+1;j<=len1;j++) vtr[j]=vtr[j-1]*p+t1[j-1];
		ull h1=0,h2=0;
		for(int j=l;j<=r;j++)
		{
			h1=h1*p+t1[j-1],h2=h2*p+t2[j-1];
		}
		int x=mp[make_pair(h1,h2)];
		if(!x)
		{
			printf("0\n");
			continue;
		}
		int cnt=0;
		for(int i=0;i<ve[x].size();i++)
		{
			int t=ve[x][i];
			if(len[t]>len1) continue;
			if(r+len[t]-mx[t]>len1||mn[t]>l) continue;
//			printf("%d %llu %llu\n",t,vr[t],vtr[r+len[t]-mx[t]]);
			if(vl[t]==vtl[l-mn[t]+1]&&vr[t]==vtr[r+len[t]-mx[t]]) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

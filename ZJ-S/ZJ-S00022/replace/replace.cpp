#include<bits/stdc++.h>
#define int long long
#define inf 2000000000000000
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
struct node
{
	string pre,s1,s2,suf;
};
int tot=0;
map<pair<string,string>,int>mp;
vector<pair<string,string> >g[N];
string pre[N],suf[N];
bool cmp(pair<string,string>x,pair<string,string>y)
{
	return (int)x.first.size()<(int)y.first.size();
}
signed main()
{ 
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,T;
	scanf("%lld%lld",&n,&T);
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		int len=s1[i].size();
		int L=-1,R;
		for(int j=0;j<len;j++)
			if(s1[i][j]!=s2[i][j])
			{
				if(L==-1)L=j;
				R=j;
			}
		if(L==-1)continue;
		node s={"","","",""};
		for(int j=0;j<L;j++)
			s.pre+=s1[i][j];
		for(int j=L;j<=R;j++)
			s.s1+=s1[i][j],s.s2+=s2[i][j];
		for(int j=R+1;j<len;j++)
			s.suf+=s1[i][j];
//		cout<<s.pre<<" "<<s.s1<<" "<<s.s2<<" "<<s.suf<<endl;
		if(!mp.count({s.s1,s.s2}))
			mp[{s.s1,s.s2}]=++tot;
		g[mp[{s.s1,s.s2}]].push_back({s.suf,s.pre});
		
		
	}
	for(int i=1;i<=tot;i++)
		sort(g[i].begin(),g[i].end(),cmp);
	int cnt=0;
	while(T--)
	{
		cnt++;
		string A,B;
		cin>>A>>B;
			
		if(A.size()!=B.size())
		{
			puts("0");
			continue;
		}
		int len=A.size();
		int L=-1,R;
		for(int i=0;i<len;i++)
			if(A[i]!=B[i])
			{
				if(L==-1)L=i;
				R=i;
			}
		node s={"","","",""};
		for(int j=0;j<L;j++)s.pre+=A[j];
		for(int j=L;j<=R;j++)
			s.s1+=A[j],s.s2+=B[j];
		for(int j=R+1;j<len;j++)
			s.suf+=A[j];
		int lenpre=s.pre.size();
		pre[0]=pre[lenpre+1]="";
		for(int i=1;i<=lenpre;i++)
			pre[i]=s.pre[lenpre-i]+pre[i-1];
		int lensuf=s.suf.size();
		suf[0]="";
		for(int i=1;i<=lensuf;i++)
			suf[i]=suf[i-1]+s.suf[i-1];
		int ans=0;
		if(!mp.count({s.s1,s.s2}))
		{
			puts("0");
		}
		else
		{
			int p=mp[{s.s1,s.s2}];
			//s.pre,s.suf在g[p]里面存在多少pair同时为pre和suf字串
			for(auto e:g[p])
			{
				if((int)e.first.size()>lensuf)
					break;
				if((int)e.second.size()>lenpre)continue;
		//		cout<<"("<<e.first<<" "<<e.second<<")"<<pre[e.second.size()]<<endl;
				ans+=(suf[e.first.size()]==e.first&&pre[e.second.size()]==e.second);
			}
			printf("%lld\n",ans);
		}
		
	}
	return 0;
}

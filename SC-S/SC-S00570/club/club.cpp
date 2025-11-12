#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+114;
int T,n,a[4][N],aa[4];
struct node{int data,place,lowww,mmaxn_place;};
vector<node>aaa[4];
void clearr(){for(int i=1;i<=3;i++) aa[i]=0,aaa[i].clear();}
bool cmp(node x,node y){return x.lowww>y.lowww;}
bool check()
{
	for(int i=1;i<=3;i++) if(aaa[i].size()>n/2) return false;
	return true;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);clearr();
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
			int maxn=0,maxnnum,mmaxn=0,maxnnnum;
			for(int j=1;j<=3;j++) if(a[j][i]>=maxn) maxnnum=j,maxn=a[j][i];
			for(int j=1;j<=3;j++) if(j!=maxnnum && a[j][i]>=mmaxn) maxnnnum=j,mmaxn=a[j][i];
			aa[maxnnum]+=a[maxnnum][i],aaa[maxnnum].push_back({a[maxnnum][i],i,a[maxnnum][i]-a[maxnnnum][i],maxnnnum});
		}
		while(!check())
		{
			for(int i=1;i<=3;i++) if(aaa[i].size()>n/2) 
			{
				sort(aaa[i].begin(),aaa[i].end(),cmp);
				node xxx=aaa[i][aaa[i].size()-1];aaa[i].pop_back();aa[i]-=xxx.data;
				aa[xxx.mmaxn_place]+=a[xxx.mmaxn_place][xxx.place],aaa[xxx.mmaxn_place].push_back({a[xxx.mmaxn_place][xxx.place],xxx.place,a[6-xxx.mmaxn_place-i][xxx.place],6-xxx.mmaxn_place-i});
			}
		}
		cout<<aa[1]+aa[2]+aa[3]<<'\n';
	}
}
/*
struct node
{
	int a,b,c;
	int jjoin,maxn;
}per[N];
int T,n,aa=0,bb=0,cc=0,aa_minn=0,bb_minn=0,cc_minn=0,aa_min_mumber,bb_min_mumber,cc_min_mumber;
vector <int> aaa,bbb,ccc;
queue <int> earlier;
void cclear(){while(!earlier.empty()) earlier.pop();}
void check()
{
	if(earlier.size()==0 && aaa.size()<=n/2 && bbb.size()<=n/2 && ccc.size()<=n/2)
	{
		printf("%lld",aa+bb+cc);
		return;
	}
	if(earlier.size())
	{
		while(!earlier.empty())
		{
			int u=earlier.front();earlier.pop();
			if(per[u].a==per[u].b && per[u].c==per[u].b)
			{
				if(aaa.size()<bbb.size() && aaa.size()<ccc.size()){aa+=per[u].a,aaa.push_back(u),per[u].jjoin=1,aa_min_mumber=(aa_minn==per[i].a)?i:aa_min_mumber;continue;}
				if(aaa.size()>bbb.size() && bbb.size()<ccc.size()){bb+=per[u].b,bbb.push_back(u),per[u].jjoin=2,bb_min_mumber=(bb_minn==per[i].b)?i:bb_min_mumber;continue;}
				if(bbb.size()>ccc.size() && ccc.size()<aaa.size()){cc+=per[u].c,ccc.push_back(u),per[u].jjoin=3;continue;}
			}
			else if(per[u].a==per[u].b && per[u].maxn==per[u].a)
			{
				if(aaa.size()<bbb.size()){aa+=per[u].a,aaa.push_back(u),per[u].jjoin=1,aa_min_mumber=(aa_minn==per[i].a)?i:aa_min_mumber;continue;}
				if(bbb.size()<aaa.size()){bb+=per[u].b,bbb.push_back(u),per[u].jjoin=2,bb_min_mumber=(bb_minn==per[i].b)?i:bb_min_mumber;continue;}
			}
			else if(per[u].b==per[u].c && per[u].maxn==per[u].b)
			{
				if(ccc.size()<bbb.size()){cc+=per[u].c,ccc.push_back(u),per[u].jjoin=3;continue;}
				if(bbb.size()<ccc.size()){bb+=per[u].b,bbb.push_back(u),per[u].jjoin=2,bb_min_mumber=(bb_minn==per[i].b)?i:bb_min_mumber;continue;}
			}
			else if(per[u].a==per[u].c && per[u].maxn==per[u].a) 
			{
				if(aaa.size()<ccc.size()){aa+=per[u].a,aaa.push_back(u),per[u].jjoin=1,aa_min_mumber=(aa_minn==per[i].a)?i:aa_min_mumber;continue;}
				if(ccc.size()<aaa.size()){cc+=per[u].c,ccc.push_back(u),per[u].jjoin=3;continue;}
			}
			else if(per[u].maxn==per[u].a){aa+=per[u].a,aaa.push_back(u),per[u].jjoin=1,aa_min_mumber=(aa_minn==per[i].a)?i:aa_min_mumber;continue;}
			else if(per[u].maxn==per[u].b){bb+=per[u].b,bbb.push_back(u),per[u].jjoin=2,bb_min_mumber=(bb_minn==per[i].b)?i:bb_min_mumber;continue;}
			else if(per[u].maxn==per[u].c){cc+=per[u].c,ccc.push_back(u),per[u].jjoin=3;continue;}
		}
	}
	while(aaa.size()>n/2 || bbb.size()>n/2 || ccc.size()>n/2)
	{
		if(aaa.size()>n/2)
		{
			if(per[aa_min_mumber].b>=per[aa_min_mumber].c){bb+=per[aa_min_mumber].b,bbb.push_back(aa_min_mumber),per[aa_min_mumber].jjoin=2,bb_min_mumber=(bb_minn==per[i].b)?i:bb_min_mumber;continue;}
			else if(per[aa_min_mumber].b<per[aa_min_mumber].c){cc+=per[aa_min_mumber].c,ccc.push_back(aa_min_mumber),per[aa_min_mumber].jjoin=3,cc_minn=min(cc_minn,per[aa_min_mumber].c),cc_min_mumber=(cc_minn==per[aa_min_mumber].c)?aa_min_mumber:cc_min_mumber;continue;}
		}
		
	}
	check();
}
signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		aa=0,bb=0,cc=0,aaa.clear(),bbb.clear(),ccc.clear(),cclear(),aa_minn=0,bb_minn=0,cc_minn=0,aa_min_mumber=0,bb_min_mumber=0,cc_min_mumber=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&per[i].a,&per[i].b,&per[i].c);per[i].jjoin=0,per[i].maxn=0,per[i].maxn=max({per[i].a,per[i].b,per[i].c});
			if(per[i].a>per[i].b && per[i].a>per[i].c) per[i].jjoin=1,aa+=per[i].a,aaa.push_back(i),aa_minn=min(aa_minn,per[i].a),aa_min_mumber=(aa_minn==per[i].a)?i:aa_min_mumber;
			if(per[i].a<per[i].b && per[i].b>per[i].c) per[i].jjoin=2,bb+=per[i].b,bbb.push_back(i),bb_minn=min(bb_minn,per[i].b),bb_min_mumber=(bb_minn==per[i].b)?i:bb_min_mumber;
			if(per[i].c>per[i].b && per[i].a<per[i].c) per[i].jjoin=3,cc+=per[i].c,ccc.push_back(i),cc_minn=min(cc_minn,per[i].c),cc_min_mumber=(cc_minn==per[i].c)?i:cc_min_mumber;
			if(per[i].jjoin==0) earlier.push(i);
		}
		check();
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	ll f;
	ll s;
	ll t;
	ll mtf;
	ll mts;
	ll mtt; 
}a[100005],cur;
ll dp[100005][4];
ll totl=0; ll n;

bool cmp(node ak,node bk)
{
	if(ak.f!=bk.f)
	return ak.f>bk.f;
	if(ak.s!=bk.s)
	return ak.s>bk.s;
	if(ak.t!=bk.t)
	return ak.t>bk.t;
	//return max(ak.f,max(ak.s,ak.t))>max(bk.f,max(bk.s,bk.t));
}
inline ll judge(ll i)
{
	int mmax=max(a[i].f,max(a[i].s,a[i].t));
	if(a[i].f==mmax)
		return 1;
	if(a[i].s==mmax)
		return 2;
	if(a[i].t==mmax)
		return 3;
}

inline pair<ll,ll> changef(ll t,vector<ll>fl,vector<ll>sl,vector<ll>tl)
{
	if(cur.f<n/2)
		return {a[t].f,0};
	
	ll mttf=-1,mt;
	for(int i=0;i<fl.size();i++)
	{
		ll tf=(a[t].f-a[i].f)-(a[t].mtf-a[i].mtf);
		if(tf>mttf)
		{
			mttf=tf;
			mt=i;
		}
	}
	if(mttf!=-1)
		return {mttf,mt};
	else
		return {0,-1}; 
}
inline pair<ll,ll> changes(ll t,vector<ll>fl,vector<ll>sl,vector<ll>tl)
{
	if(cur.s<n/2)
		return {a[t].s,0};
	
	ll mtts=0,mt;
	for(int i=0;i<sl.size();i++)
	{
		ll ts=(a[t].s-a[i].s)-(a[t].mtf-a[i].mtf);
		if(ts>mtts)
		{
			mtts=ts;
			mt=i;
		}
	}
	if(mtts>0)
		return {mtts,mt};
	else
		return {0,-1}; 
}
inline pair<ll,ll> changet(ll t,vector<ll>fl,vector<ll>sl,vector<ll>tl)
{
	if(cur.t<n/2)
		return {a[t].t,0};
	
	ll mttt=-1,mt=-1;
	for(int i=0;i<tl.size();i++)
	{
		ll tt=(a[t].t-a[i].t)-(a[t].mtt-a[i].mtt);
		if(tt>mttt)
		{
			mttt=tt;
			mt=i;
		}
	}
	if(mttt!=-1)
		return {mttt,mt};
	else
		return {0,-1}; 
}

inline void filp(ll th,vector<ll>fl,vector<ll>sl,vector<ll>tl)
{
	
	pair<ll,ll>tof=changef(th,fl,sl,tl);
	pair<ll,ll>tos=changes(th,fl,sl,tl);
	pair<ll,ll>tot=changet(th,fl,sl,tl);
	
	//cout<<tos.first<<tos.second<<endl;
	 
	ll maxn=-1;
	if(tof.first!=-1||tos.first!=-1||tot.first!=-1)
		maxn=max(tof.first,max(tos.first,tot.first));
	
	if(maxn==1)
	{
		if(tof.second==0&&tof.first!=0)
		{
			cur.f++;
			totl+=a[th].f;
		}
		else
		{
			totl-=a[tof.second].f;
			totl+=a[th].f;
			filp(tof.second,fl,sl,tl);
		}
	}
	if(maxn==2)
	{
		if(tos.second==0&&tos.first!=0)
		{
			cur.s++;
			totl+=a[th].s;
		}
		else
		{
			totl-=a[tos.second].s;
			totl+=a[th].s;
			filp(tos.second,fl,sl,tl);
		}
	}
	if(maxn==3)
	{
		if(tot.second==0&&tot.first!=0)
		{
			cur.t++;
			totl+=a[th].t;
		}
		else
		{
			totl-=a[tot.second].t;
			totl+=a[th].t;
			filp(tot.second,fl,sl,tl);
		}
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//ios::sync_with_stdio(0);
	
	ll t;
	cin>>t;
	while(t--)
	{
	
		cin>>n;
		
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		cur.f=cur.s=cur.t=0;
		totl=0;
		
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].f>>a[i].s>>a[i].t;
			ll maxn=max(a[i].f,max(a[i].s,a[i].t));
			a[i].mtf=a[i].f-maxn;
			a[i].mts=a[i].s-maxn;
			a[i].mtt=a[i].t-maxn;
			//去其他部门会掉的心情 
		}
			
		sort(a+1,a+n+1,cmp);
		vector<ll>fl,sl,tl;
		
		for(int i=1;i<=n;i++)
		{
			ll trr=judge(i);
			
			switch(trr)
			{
				case 1:
				{
					if(cur.f<n/2)
					{
						fl.push_back(i);
						cur.f++;
						totl+=a[i].f;
					}
					else
					if(cur.s<n/2)
					{
						sl.push_back(i);
						cur.s++;
						totl+=a[i].s;
					}
				/*	else 
						filp(i,fl,sl,tl);*/
					break;
				}
				case 2:
				{
					if(cur.s<n/2)
					{
						sl.push_back(i);
						totl+=a[i].s;
						cur.s++;
					}
					else
					if(cur.f<n/2)
					{
						fl.push_back(i);
						cur.f++;
						totl+=a[i].f;
					}
					/*else
						filp(i,fl,sl,tl);*/
					break;
				}
				case 3:
				{
					if(cur.t<n/2)
					{
						tl.push_back(i);
						totl+=a[i].t;
						cur.t++;
					}
					/*else
						filp(i,fl,sl,tl); */
					break;
				}
				
			}
		}
		cout<<totl<<endl;
	}
	
//	cin.tie(0);
	//cout.tie(0);	
	//基本路径结束 16.09 开始检查 将样例二结束 
	return 0;
} 

#include<bits/stdc++.h>
#define int unsigned long long
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define mem(s,t) memset(s,t,sizeof s)
#define ll long long
#define ld long double
#define endl '\n'
using namespace std;
const int N=1e5+5;
struct node{int a1,a2,a3;}m[N];
int t,n,ans;
int man(int a,int b,int c){return max(max(a,b),c);}
bool cmp1(int a,int b){return min(m[a].a1-m[a].a2,m[a].a1-m[a].a3)>min(m[b].a1-m[b].a2,m[b].a1-m[b].a3);}
bool cmp2(int a,int b){return min(m[a].a2-m[a].a1,m[a].a2-m[a].a3)>min(m[b].a2-m[b].a1,m[b].a2-m[b].a3);}
bool cmp3(int a,int b){return min(m[a].a3-m[a].a1,m[a].a3-m[a].a2)>min(m[b].a3-m[b].a1,m[b].a3-m[b].a2);}
void solve()
{
	cin>>n;
	vector<int> t1,t2,t3;
	ans=0;
	rep(i,1,n)
	{
		cin>>m[i].a1>>m[i].a2>>m[i].a3;
		int ma=man(m[i].a1,m[i].a2,m[i].a3);
		if(ma==m[i].a1&&ma!=m[i].a2&&ma!=m[i].a3)t1.push_back(i),ans+=m[i].a1;
		if(ma!=m[i].a1&&ma==m[i].a2&&ma!=m[i].a3)t2.push_back(i),ans+=m[i].a2;
		if(ma!=m[i].a1&&ma!=m[i].a2&&ma==m[i].a3)t3.push_back(i),ans+=m[i].a3;
		if(ma==m[i].a1&&ma==m[i].a2&&ma!=m[i].a3)
		{
			if(t1.size()<t2.size())t1.push_back(i),ans+=m[i].a1;
			else t2.push_back(i),ans+=m[i].a2;
		}
		if(ma==m[i].a1&&ma!=m[i].a2&&ma==m[i].a3)
		{
			if(t1.size()<t3.size())t1.push_back(i),ans+=m[i].a1;
			else t3.push_back(i),ans+=m[i].a3;
		}
		if(ma!=m[i].a1&&ma==m[i].a2&&ma==m[i].a3)
		{
			if(t2.size()<t3.size())t2.push_back(i),ans+=m[i].a2;
			else t3.push_back(i),ans+=m[i].a3;
		}
		if(ma==m[i].a1&&ma==m[i].a2&&ma==m[i].a3)
		{
			if(t1.size()<=t2.size()&&t1.size()<=t3.size())t1.push_back(i),ans+=m[i].a1;
			else if(t2.size()<=t1.size()&&t2.size()<=t3.size())t2.push_back(i),ans+=m[i].a2;
			else if(t3.size()<=t1.size()&&t3.size()<=t2.size())t3.push_back(i),ans+=m[i].a3;
		}
	}
	if(t1.size()>(n/2))
	{
		sort(t1.begin(),t1.end(),cmp1);
		while(t1.size()>(n/2))
		{
			int i=t1.back();
			ans-=min(m[i].a1-m[i].a2,m[i].a1-m[i].a3);
			t1.pop_back();
		}
	}
	if(t2.size()>(n/2))
	{
		sort(t2.begin(),t2.end(),cmp2);
		while(t2.size()>(n/2))
		{
			int i=t2.back();
			ans-=min(m[i].a2-m[i].a1,m[i].a2-m[i].a3);
			t2.pop_back();
		}
	}
	if(t3.size()>(n/2))
	{
		sort(t3.begin(),t3.end(),cmp3);
		while(t3.size()>(n/2))
		{
			int i=t3.back();
			ans-=min(m[i].a3-m[i].a2,m[i].a3-m[i].a1);
			t3.pop_back();
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)solve();
	return 0;
}

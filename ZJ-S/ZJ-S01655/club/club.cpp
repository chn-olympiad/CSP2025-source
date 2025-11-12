#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans;
struct node{
	int x,y,z,id;
	int xy,xz,yz;
}g[maxn];

bool cmp1(node a,node b){return a.xy>b.xy;}
bool cmp2(node a,node b){return a.xz>b.xz;}
bool cmp3(node a,node b){return a.yz>b.yz;}
bool cmp4(node a,node b){return a.xy<b.xy;}
bool cmp5(node a,node b){return a.xz<b.xz;}
bool cmp6(node a,node b){return a.yz<b.yz;}

struct vec{
	vector<node> a,b,c;
};
vector<node> a,b,c;
int sum(vec t)
{
	int ans=0;
	auto[xa,xb,xc]=t;
	for(node i:xa) ans+=i.x;
	for(node i:xb) ans+=i.y;
	for(node i:xc) ans+=i.z;
	return ans;
}
void A_to_B(vec t)
{
	auto[xa,xb,xc]=t;
	sort(xa.begin(),xa.end(),cmp1);
	while(xa.size()>n/2) 
	 {
	 	node x=xa.back();
	 	xa.pop_back();
	 	xb.push_back(x);
	 }
	ans=max(ans,sum((vec){xa,xb,xc}));
}
void A_to_C(vec t)
{
	auto[xa,xb,xc]=t;
	sort(xa.begin(),xa.end(),cmp2);
	while(xa.size()>n/2) 
	 {
	 	node x=xa.back();
	 	xa.pop_back();
	 	xc.push_back(x);
	 }
	ans=max(ans,sum((vec){xa,xb,xc}));
}
void B_to_A(vec t)
{
	auto[xa,xb,xc]=t;
	sort(xb.begin(),xb.end(),cmp4);
	while(xb.size()>n/2) 
	 {
	 	node x=xb.back();
	 	xb.pop_back();
	 	xa.push_back(x);
	 }
	ans=max(ans,sum((vec){xa,xb,xc}));
}
void B_to_C(vec t)
{
	auto[xa,xb,xc]=t;
	sort(xb.begin(),xb.end(),cmp3);
	while(xb.size()>n/2) 
	 {
	 	node x=xb.back();
	 	xb.pop_back();
	 	xc.push_back(x);
	 }
	ans=max(ans,sum((vec){xa,xb,xc}));
}
void C_to_A(vec t)
{
	auto[xa,xb,xc]=t;
	sort(xc.begin(),xc.end(),cmp5);
	while(xc.size()>n/2) 
	 {
	 	node x=xc.back();
	 	xc.pop_back();
	 	xa.push_back(x);
	 }
	ans=max(ans,sum((vec){xa,xb,xc}));
}
void C_to_B(vec t)
{
	auto[xa,xb,xc]=t;
	sort(xc.begin(),xc.end(),cmp6);
	while(xc.size()>n/2) 
	 {
	 	node x=xc.back();
	 	xc.pop_back();
	 	xb.push_back(x);
	 }
	ans=max(ans,sum((vec){xa,xb,xc}));
}
void solveA(vec t)
{
	A_to_B(t);
	A_to_C(t);
}
void solveB(vec t)
{
	B_to_A(t);
	B_to_C(t);
}
void solveC(vec t)
{
	C_to_A(t);
	C_to_B(t);
}
void solve()
{
	a.clear();b.clear();c.clear();
	cin>>n;ans=0;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>g[i].x>>g[i].y>>g[i].z;g[i].id=i;
	 	g[i].xy=g[i].x-g[i].y;
	 	g[i].xz=g[i].x-g[i].z;
	 	g[i].yz=g[i].y-g[i].z;
	 	if(max({g[i].x,g[i].y,g[i].z})==g[i].x) a.push_back(g[i]);
	 	if(max({g[i].x,g[i].y,g[i].z})==g[i].y) b.push_back(g[i]);
	 	if(max({g[i].x,g[i].y,g[i].z})==g[i].z) c.push_back(g[i]);
	 }
	if(a.size()>n/2) solveA((vec){a,b,c});
	else if(b.size()>n/2) solveB((vec){a,b,c});
	else if(c.size()>n/2) solveC((vec){a,b,c});
	else ans=sum((vec){a,b,c});
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--) solve();
	return 0;
}

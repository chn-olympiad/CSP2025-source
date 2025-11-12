//Just Sayori!!!
//csp 2025 rp++
//祝学长全部进 WC！
//祝大家全员一等奖！
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#define ll long long
#define rnt register int
#define gr getchar
#define pr putchar
#define N 500005
#define M 1000000007
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
void write(ll x)
{
	int top=0,stack[39];
	if (x<0) pr('-'),x=-x;
	do stack[++top]=x%10,x/=10;
	while (x);
	while (top) pr(stack[top--]^48);
}
struct node
{
	int w,id;
}s[3];
bool cmp1(node a,node b)
{
	return a.w>b.w;
}
bool cmp2(node a,node b)
{
	return a.w<b.w;
}
vector<node> vea,veb,vec;
void work()
{
	int n=read();
	ll ans=0;
	vea.clear(),veb.clear(),vec.clear();
	for (rnt i=1;i<=n;i++)
	{
		s[0].w=read(),s[0].id=1,s[1].w=read(),s[1].id=2,s[2].w=read(),s[2].id=3;
		sort(s,s+3,cmp1);
		if (s[0].id==1) vea.emplace_back(node{s[1].w-s[0].w,i}),ans+=s[0].w;
		if (s[0].id==2) veb.emplace_back(node{s[1].w-s[0].w,i}),ans+=s[0].w;
		if (s[0].id==3) vec.emplace_back(node{s[1].w-s[0].w,i}),ans+=s[0].w;
	}
	int lena=vea.size(),lenb=veb.size(),lenc=vec.size();
	if (lena) sort(vea.begin(),vea.end(),cmp2);
	if (lenb) sort(veb.begin(),veb.end(),cmp2);
	if (lenc) sort(vec.begin(),vec.end(),cmp2);
	while (lena>n/2)
		ans+=vea.back().w,vea.pop_back(),lena--;
	while (lenb>n/2)
		ans+=veb.back().w,veb.pop_back(),lenb--;
	while (lenc>n/2)
		ans+=vec.back().w,vec.pop_back(),lenc--;
	write(ans),pr(10);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while (t--) work();
	return 0;
}

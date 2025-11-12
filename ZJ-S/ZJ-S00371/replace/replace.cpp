#include <bits/stdc++.h>
using namespace std;
//~ #define calc_time
//~ #define debug
namespace zyc{
	#define pb push_back
	#define rep(i,l,r) for(int i=l;i<=r;i++)
	#define per(i,r,l) for(int i=r;i>=l;i--)
	const int N=2e5+10,L=5e6+10,V=1e7+10,K=1,MOD=1e7+3,P=1331;
	typedef long long ll;
	ll mul(ll a,ll b){return a*b%MOD;}
	ll add(ll a,ll b){return (a+b)%MOD;}
	vector<int>h[V];//每组每个最大不同段 hash 值对应的原串编号
	int suf[N];//每组每个后缀 hash 值
	int pre[N];//每组每个前缀 hash 值
	int vsuf[V],vpre[V],pi,ans;
	bool vis[N];
	vector<int>tmp;
	int n,q,v,lb,rb,len;
	char s1[L],s2[L],t1[L],t2[L];
	int p[L];
	int main(){
		#ifdef calc_time
		auto S=clock();
		#endif
		ios::sync_with_stdio(0);
		cin.tie(0); cout.tie(0);
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n>>q;
		p[0]=1;
		rep(i,1,L-1)p[i]=mul(p[i-1],P);
		rep(i,1,n){
			cin>>(s1+1)>>(s2+1);
			len=strlen(s1+1);
			lb=1,rb=len;
			while(s1[lb]==s2[lb]&&lb<=rb)lb++;
			while(s1[rb]==s2[rb]&&lb<=rb)rb--;
			v=0;
			rep(j,lb,rb){
				v=mul(v,P),v=add(v,s1[j]);
				v=mul(v,P),v=add(v,s2[j]);
			}
			h[v].pb(i);
			v=0;
			per(j,len,rb+1)v=mul(v,P),v=add(v,s2[j]);
			suf[i]=v;
			v=0;
			rep(j,1,lb-1)v=mul(v,P),v=add(v,s2[j]);
			pre[i]=v;
		}
		rep(i,1,q){
			cin>>(s1+1)>>(s2+1);
			len=strlen(s1+1);
			if((int)strlen(s2+1)!=len){
				cout<<0<<'\n';continue;
			}
			lb=1,rb=len;
			while(s1[lb]==s2[lb]&&lb<=rb)lb++;
			while(s1[rb]==s2[rb]&&lb<=rb)rb--;
			v=pi=0;
			vsuf[0]=1;tmp.pb(0);
			rep(j,rb+1,len){
				v=add(v,mul(s1[j],p[pi]));pi++;
				vsuf[v]=1;tmp.pb(v);
			}
			v=pi=0;
			vpre[0]=1;
			per(j,lb-1,1){
				v=add(v,mul(s1[j],p[pi]));pi++;
				vpre[v]=1;tmp.pb(v);
			}
			v=0;
			rep(j,lb,rb){
				v=mul(v,P),v=add(v,s1[j]);
				v=mul(v,P),v=add(v,s2[j]);
			}
			ans=0;
			for(auto j:h[v]){
				if(vsuf[suf[j]]&&vpre[pre[j]])ans++;
			}
			for(auto j:tmp)vsuf[j]=vpre[j]=0;
			tmp.clear();
			cout<<ans<<'\n';
		}
		#ifdef calc_time
		auto E=clock();
		double D=double(E-S)/CLOCKS_PER_SEC*1000;
		cerr<<D<<" ms\n";
		#endif
		return 0;
	}
}
int main(){return zyc::main();}
//Ren5Jie4Di4Ling5%

//这题给人一种非常 AC 自动机的感觉
//实际上就是 KMP 吧，我一开始没看仔细，看似是只替换一次的方案数
//我有没有傻了，这个像板
//哦，问题在于每次都跑一遍 KMP，复杂度是 n*T总长 的

//注意 T1 T2 长度可以先判

//发现事情不是那么简单
//替换一次要直接变成另一个
//那么要把这俩玩意儿的最长相同前后缀先截了
//中间的是必须匹配的东西

//这样的好处是什么？
//可不可以使用字符串哈希
//逐个在最短匹配段前一位一位加上数字
//然后看有没有字符串的前缀等于这个哈希值
//如果两个都有匹配，那么先看长度能不能包进去
//如果可以，那么看一下后面多出来的后缀的 hash 值一不一样

//求每个模式串的前后缀 hash 复杂度 O(L1)
//求每个询问串所对应的 hash 复杂度 O(L2)

//非常对

//为了保证正确性，考虑多哈希

//两个串的 hash 信息是否可以合并？
//前缀合并后缀不并

//先单 hash

//对于后缀的判断，其实只要看两者最长公共后缀的长度与 hash 值即可

//我真唐

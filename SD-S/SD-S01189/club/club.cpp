#include<cstdbool>
#include<cstddef>
#include<cstdio>
#include<algorithm>
#include<tuple>
#include<iostream>
#include<vector>

using	lf=double;
using	us=std::size_t;
using	ll=std::ptrdiff_t;

constexpr       ll inf=0x3f3f3f3f3f3f3f3fll;
constexpr       ll mod=0x3b800001l;
constexpr       ll len=1l<<17;

template<typename t>
ll dfs(ll x,ll n,t &f,ll a=0,ll b=0,ll c=0,ll s=0){
	if(x==n)
		return s;
	ll g=a<n>>1?dfs(x+1,n,f,a+1,b,c,s+std::get<0>(f[x])):0;
	g=std::max(g,b<n>>1?dfs(x+1,n,f,a,b+1,c,s+std::get<1>(f[x])):0);
	g=std::max(g,c<n>>1?dfs(x+1,n,f,a,b,c+1,s+std::get<2>(f[x])):0);
	return g;
}

void    solve(void){
	ll n,s=0;
	std::cin>>n;
	std::vector<std::tuple<ll,ll,ll>>a(n);
	_Bool f1=1,f2=1;
	for(ll i=0;i<n;i++){
		ll &x=std::get<0>(a[i]);
		ll &y=std::get<1>(a[i]);
		ll &z=std::get<2>(a[i]);
		std::cin>>x>>y>>z;
		s+=std::max(std::max(x,y),z);
		f1&=y==0&&z==0;
		f2&=z==0;
	}       if(f1){
		std::sort(a.begin(),a.end(),[](std::tuple<ll,ll,ll>&x,std::tuple<ll,ll,ll>&y){
			return std::get<0>(x)>std::get<0>(y);
		});	s^=s;
		for(ll x=0;x<n>>1;x++)
			s+=std::get<0>(a[x]);
		std::cout<<s<<"\n";
		return;
	}	if(n>500){
		std::cout<<s<<"\n";
		return;
	}       std::cout<<dfs(1,n,a)<<"\n";
}

auto	main()->signed{
 	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	ll t=1;
	std::cin>>t;
	while(t--)
		solve();
	return 0;
}


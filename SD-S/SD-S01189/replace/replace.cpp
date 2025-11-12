#include<cstddef>
#include<cstdio>
#include<cstring>
#include<tuple>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>

using	lf=double;
using	us=std::size_t;
using	ll=std::ptrdiff_t;

constexpr       ll inf=0x3f3f3f3f3f3f3f3fll;
constexpr       ll mod=0x3b800001l;

std::map<ll,std::set<ll>>a;

void	solve(void){
	ll n,q;
	std::cin>>n>>q;
	while(n--){
		std::string s1,s2;
		std::cin>>s1>>s2;
		ll x=1,y=1;
		for(char &c:s1){
			if(c=='b')
				break;
			x++;
		}	for(char &c:s2){
			if(c=='b')
				break;
			y++;
		}	a[y-x].emplace(std::min(x,y)<<30|s1.size()-std::max(x,y));
	}       while(q--){
		std::string s1,s2;
		std::cin>>s1>>s2;
		ll x=1,y=1,s=1;
		for(char &c:s1){
			if(c=='b')
				break;
			x++;
		}	for(char &c:s2){
			if(c=='b')
				break;
			y++;
		}       for(ll t:a[y-x]){
			ll f=t>>30;
			ll g=t^f<<30;
			if(std::min(x,y)<=f&&g<=s1.size()-std::max(x,y))
				s++;
		}       std::cout<<s<<"\n";
	}
}

auto	main()->signed{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	ll t=1;
//	std::cin>>t;
	while(t--)
		solve();
	return 0;
}


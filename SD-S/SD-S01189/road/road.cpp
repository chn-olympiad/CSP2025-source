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
constexpr       ll ver=1l<<14;

typedef struct  _vtx    vtx;
struct  _vtx{
	vtx *top;
	ll val,deg;
	void add_edge(vtx*,ll);
	auto fnd(void)->vtx*;
}	v[ver];

std::vector<std::tuple<vtx*,vtx*,ll,_Bool>>edg;

void    vtx::add_edge(vtx *y,ll z){
	edg.emplace_back(this,y,z,0);
}

auto	vtx::fnd(void)->vtx*{
	if(top==NULL)
		return this;
	else    return top=top->fnd();
}

auto	cmp(std::tuple<vtx*,vtx*,ll,_Bool>&x,std::tuple<vtx*,vtx*,ll,_Bool>&y)->_Bool{
	return std::get<2>(x)<std::get<2>(y);
}

void    solve(void){
	ll n,m,n2,s=0;
	std::cin>>n>>m>>n2;
	while(m--){
		ll x,y,z;
		std::cin>>x>>y>>z;
		v[x].add_edge(v+y,z);
		v[y].add_edge(v+x,z);
	}	for(vtx *x=v+n+1;x<=v+n+n2;x++){
		std::cin>>x->val;
		for(vtx *y=v+1;y<=v+n;y++){
			ll z;
			std::cin>>z;
			x->add_edge(y,z);
			y->add_edge(x,z);
		}
	}	std::sort(edg.begin(),edg.end(),cmp);
	for(auto &e:edg){
		auto &x=std::get<0>(e);
		auto &y=std::get<1>(e);
		auto &z=std::get<2>(e);
		auto &p=std::get<3>(e);
		if(x->fnd()==y->fnd())
			continue;
		x->deg++,y->deg++;
		x->fnd()->top=y->fnd();
		p=1;
	}       for(auto &e:edg){
		auto &x=std::get<0>(e);
		auto &y=std::get<1>(e);
		auto &z=std::get<2>(e);
		auto &p=std::get<3>(e);
		if(p==0)
			continue;
		if(x->deg==1&&v+n<x)
			continue;
		if(y->deg==1&&v+n<y)
			continue;
		s+=z;
	}       std::cout<<s<<"\n";
}

auto	main()->signed{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	ll t=1;
//	std::cin>>t;
	while(t--)
		solve();
	return 0;
}


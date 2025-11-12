#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using std::cin;using std::cout;
constexpr int N=200005;
int n,q,g[N],m,ans;
std::string s[2],t[2];
std::map<std::string,int>p;
std::set<std::string>w[N];
std::map<std::string,std::map<std::string,int>>h;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>q;for(int i=1;i<=n;++i){cin>>s[0]>>s[1];if(!p[s[0]]) p[s[0]]=i;w[p[s[0]]].insert(s[1]);++h[s[0]][s[1]];g[i]=s[0].size();}
	std::sort(g+1,g+n+1);m=std::unique(g+1,g+n+1)-g-1;
	for(int i=1;i<=q;++i){
		cin>>t[0]>>t[1];ans=0;
		int l=0,r=t[0].size()-1;
		for(;t[0][l]==t[1][l];++l);
		for(;t[0][r]==t[1][r];--r);
		for(int j=0;j<=l;++j)
			for(int k=m;k;--k){
				if(j+g[k]<=r) break;
				std::string s1=t[0].substr(j,g[k]),s2=t[1].substr(j,g[k]);
				if(p.find(s1)!=p.end()&&w[p[s1]].find(s2)!=w[p[s1]].end()) ans+=h[s1][s2];
			}
		cout<<ans<<'\n';
	}
	return 0;
}

//T1:club.cpp
#include<bits/stdc++.h>
using namespace std;
unsigned int n;
unsigned int ans;
struct ppp{
	unsigned int a;
	unsigned int b;
	unsigned int c;
};
vector<ppp> p;

inline unsigned int calculate(vector<unsigned int> a,vector<unsigned int> b,vector<unsigned int> c){
	unsigned int ans=0;
	for(unsigned int i=0;i<a.size();i++){
		ans+=p[a[i]].a;
	}
	for(unsigned int i=0;i<b.size();i++){
		ans+=p[b[i]].b;
	}
	for(unsigned int i=0;i<c.size();i++){
		ans+=p[c[i]].c;
	}
	return ans;
}

inline void dfs(unsigned int now,vector<unsigned int> a,vector<unsigned int> b,vector<unsigned int> c){
	if(now>n){
		if(a.size()*2<=n&&b.size()*2<=n&&c.size()*2<=n){
			ans = max(ans,calculate(a,b,c));
			return;
		}
		else return;
	}
	else{
		vector<unsigned int> new_a = a;
		new_a.push_back(now);
		vector<unsigned int> new_b = b;
		new_b.push_back(now);
		vector<unsigned int> new_c = c;
		new_c.push_back(now);
		dfs(now+1,new_a,b,c);
		dfs(now+1,a,new_b,c);
		dfs(now+1,a,b,new_c);
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	unsigned int t;
	cin>>t;
	for(unsigned int x=1;x<=t;x++){
		p.push_back({0,0,0});
		cin>>n;
		for(unsigned int i=1;i<=n;i++){
			unsigned int a,b,c;
			cin>>a>>b>>c;
			p.push_back({a,b,c});
		}
		dfs(1,{},{},{});
		cout<<ans<<"\n";
		ans = 0;
		p.clear();
	}
	return 0;
}
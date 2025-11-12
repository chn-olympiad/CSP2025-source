#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=1e16+3,Z=27;
struct Node{
	int bef,las,pre;
	friend bool operator < (Node a,Node b){
		if(a.bef!=b.bef) return a.bef<b.bef;
		if(a.las!=b.las) return a.las<b.las;
		return a.pre<b.pre;
	}
};
int calc(string &str){
	int res=0;
	for(char i:str){
		res=(res*Z+(i-'a'+1))%mod;
	}
	return res;
}
map<Node,vector<int> > mp;
int n,q,pw[N*5];
unordered_map<int,int> vis;
map<pair<int,int>,int> mc;
string s1,s2,t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*Z%mod;
	for(int i=1;i<=n;i++) {
		cin>>s1>>s2;
		int m=s1.size(),pre=0;int suf=m-1;
		while(pre<m&&s1[pre]==s2[pre]) ++pre;
		while(suf>=pre&&s1[suf]==s2[suf]) --suf; 
		string a,b,c,d;
		for(int i=0;i<pre;i++) a.push_back(s1[i]);
		for(int i=pre;i<=suf;i++){
			b.push_back(s1[i]);
			c.push_back(s2[i]);
		}
		for(int i=suf+1;i<m;i++) d.push_back(s1[i]);
		mp[{calc(a),calc(b),calc(c)}].push_back(calc(d));
	}
	int lstans=0;
	while(q--){
		cin>>s1>>s2;
		if(mc.count({calc(s1),calc(s2)})){
			cout<<mc[{calc(s1),calc(s2)}]<<'\n';
			continue;
		}
		t1=s1;t2=s2;
		if(s1.size()!=s2.size()) {
			cout<<0<<'\n';
			continue;
		}
		int m=s1.size(),pre=0;int suf=m-1;
		while(pre<m&&s1[pre]==s2[pre]) ++pre;
		while(suf>=pre&&s1[suf]==s2[suf]) --suf; 
		string b,c;
		for(int i=pre;i<=suf;i++){
			b.push_back(s1[i]);
			c.push_back(s2[i]);
		}
//		cout<<b<<' '<<c<<'\n';
		int ha=calc(b),hb=calc(c);
		int ans=0,cur=0;vis.clear();vis[0]=1;
		for(int i=suf+1;i<m;i++){
			cur=(cur*Z+(s1[i]-'a'+1))%mod;
			vis[cur]=1;
		}
		cur=0;
		for(int i=pre;i>=0;i--){
			if(i!=pre) cur=(cur+(s1[i]-'a'+1)*pw[pre-i-1])%mod;
			if(!mp.count({cur,ha,hb})) continue;
			vector<int> vec=mp[{cur,ha,hb}];
			for(int j:vec) {
				ans+=vis[j];
			}
		}
		mc[{calc(s1),calc(s2)}]=ans;
		cout<<ans<<'\n';
	} 
	return 0;
}


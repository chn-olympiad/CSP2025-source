#include<bits/stdc++.h>
#define pb push_back
#define ull unsigned long long 
#define pii pair<int,int>
using namespace std;
const int N=5e6+5,_=2e5+5,B=233,mod=998244353;
int n,q,idx[N+_*2];
map<pair<ull,ull>,int>mp;
struct trie{
	int nxt[N+_*2][26],tot,s[N+_*2];
	int nw(){
		return ++tot;
	}
	int ins(string ss,int p){
		for(auto c:ss){
			int v=c-'a';
			if(!nxt[p][v])nxt[p][v]=++tot;
			p=nxt[p][v];
		}
		s[p]++;
		return p;
	}
	pii qry(string ss,int p){
		int sum=0;
		for(auto c:ss){
			int v=c-'a';
			sum+=s[p];
			if(!nxt[p][v])return {0,sum};
			p=nxt[p][v];
		}
		return {p,sum+s[p]};
	}
}T1,T2;
void sol(){
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size()){
		cout<<0<<'\n';
		return ;
	}
	int p=0,q=s1.size()-1;
	while(p<s1.size()&&s1[p]==s2[p])p++;
	while(q>=0&&s1[q]==s2[q])q--;
	string temp="";
	ull sum1=0,sum2=0;
	for(int i=p;i<=q;i++){
		sum1=(sum1*B+s1[i]-'a'+1)%mod;
		sum2=(sum2*B+s2[i]-'a'+1)%mod;
	}
	if(!mp[{sum1,sum2}]){
		cout<<0<<'\n';
		return ;
	}
	// for(int i=q+1;i<s1.size();i++)temp+=s1[i];
	// auto [cur,qwq1]=T1.qry(temp,mp[{sum1,sum2}]);
	// if(!idx[cur]){
	// 	cout<<0<<'\n';
	// 	return ;
	// }
	
	temp.clear();
	for(int i=0;i<p;i++)temp+=s1[i];
	reverse(temp.begin(),temp.end());
	auto [qwq2,ans]=T2.qry(temp,idx[cur]);
	cout<<ans<<'\n';
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	for(;n--;){
		string s1,s2;
		cin>>s1>>s2;
		int p=0,q=s1.size()-1;
		while(p<s1.size()&&s1[p]==s2[p])p++;
		while(q>=0&&s1[q]==s2[q])q--;
		string temp="";
		ull sum1=0,sum2=0;
		for(int i=p;i<=q;i++){
			sum1=(sum1*B+s1[i]-'a'+1)%mod;
			sum2=(sum2*B+s2[i]-'a'+1)%mod;
		}
		if(!mp[{sum1,sum2}])mp[{sum1,sum2}]=T1.nw();
		// cout<<mp[{sum1,sum2}]<<'\n';
		for(int i=q+1;i<s1.size();i++)temp+=s1[i];
		int cur=T1.ins(temp,mp[{sum1,sum2}]);
		if(!idx[cur])idx[cur]=T2.nw();
		temp.clear();
		for(int i=0;i<p;i++)temp+=s1[i];
		reverse(temp.begin(),temp.end());
		cur=T2.ins(temp,idx[cur]);
	}
	for(;q--;)sol();
	return 0;
}
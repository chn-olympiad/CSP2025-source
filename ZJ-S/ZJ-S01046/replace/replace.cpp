#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
using CS=const string&;
using LL=long long;
LL const mod=1e9+7;
LL const base=131;
vector<LL>p;
unordered_map<string,vector<LL>>mp;
void init_p(int len){
	p.resize(len+10);
	p[0]=1LL;
	for(int i=1;i<=len+5;i++)
		p[i]=p[i-1]*base%mod;
}
LL Query(int l,int r,vector<LL>&Hash){
	if(l>r)return 0ll;
	l++,r++;
	return(Hash[r]-Hash[l-1]*p[r-l+1]%mod+mod)%mod;
}
void init_hash(CS s,vector<LL>&Hash){
	for(int i=1;i<=s.size();i++)
		Hash[i]=(Hash[i-1]*base%mod+(s[i-1]-'a'))%mod;
}
int work(CS t1,CS t2,CS s1,CS s2){
//	cout<<t1<<' '<<t2<<' '<<s1<<' '<<s2<<'\n';
	if(t1.size()!=t2.size()||
	   s1.size()!=s2.size()||
	   s1.size()>t1.size())return 0;
//	cout<<"into\n";
	int res=0;
	for(int i=0;i+s1.size()-1<t1.size();i++){
		LL sub1=Query(i,i+s1.size()-1,mp[t1]);
		LL sub2=Query(i,i+s2.size()-1,mp[t2]);
	//	cout<<"hash sum:"<<sub1<<' '<<sub2<<' '<<Query(0,s1.size()-1,mp[s1])<<' '<<Query(0,s2.size()-1,mp[s2])<<'\n';
		if(sub1==Query(0,s1.size()-1,mp[s1])&&
		   sub2==Query(0,s2.size()-1,mp[s2])){
			if(Query(0,i-1,mp[t1])==Query(0,i-1,mp[t2])&&
			   Query(i+s1.size(),t1.size()-1,mp[t1])==Query(i+s2.size(),t2.size()-1,mp[t2])){
			 //  	cout<<"find "<<i<<'\n';
			   	res++;
			   }
		}
	}
	return res;
}
string t1[N],t2[N];
int n;
void solve(){
	string s1,s2;
	cin>>s1>>s2;
	mp[s1].resize(s1.size()+10);
	mp[s2].resize(s2.size()+10);
	init_hash(s1,mp[s1]);
	init_hash(s2,mp[s2]);
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=work(s1,s2,t1[i],t2[i]);
	cout<<ans<<'\n';
	return;
}
struct Node{
	int b1,b2;
}str[N];
void special_solve(){
	string s1,s2;
	cin>>s1>>s2;
	int b1,b2;
	for(int i=0;i<s1.size();i++)
		if(s1[i]=='b'){
			b1=i;
			break;
		}
	for(int i=0;i<s2.size();i++)
		if(s2[i]=='b'){
			b2=i;
			break;
		}
	int ans=0;
//	cout<<s1<<' '<<s2<<":\n";
	for(int i=1;i<=n;i++){
		if(str[i].b1-str[i].b2!=b1-b2){
		//	cout<<i<<" out because 1\n";
			continue;
		}
		if(str[i].b1>b1||str[i].b2>b2){
		//	cout<<i<<" out because 2\n";
			continue;
		}
		if(t1[i].size()-str[i].b1>s1.size()-b1||
		   t2[i].size()-str[i].b2>s2.size()-b2){
		//	cout<<i<<" out because 3\n";
			continue;
		}
		ans++;
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	cin>>n>>q;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
		len=max(len,(int)t1[i].size());
		len=max(len,(int)t2[i].size());
	}
	if(n<=1e3&&len<=2000){ // case 1-5 O(n*len*q) ok
		init_p(len);
		for(int i=1;i<=n;i++){
			mp[t1[i]].resize(t1[i].size()+10);
			mp[t2[i]].resize(t2[i].size()+10);
			init_hash(t1[i],mp[t1[i]]);
			init_hash(t2[i],mp[t2[i]]);
		}
		while(q--)
			solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<t1[i].size();j++)
			if(t1[i][j]=='b'){
				str[i].b1=j;
				break;
			}
		for(int j=0;j<t2[i].size();j++)
			if(t2[i][j]=='b'){
				str[i].b2=j;
				break;
			}
	}
	while(q--)special_solve(); // case 6,9,10,13,14 O(n+len*q) ok
	return 0;
}
/*
3 4
aba aab
baa aba
aab aab
aaaba aabaa
abaaa aabaa
aaaab abaaa
abaaa abaaa
*/
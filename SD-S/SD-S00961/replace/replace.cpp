#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define PII pair<int,int>
#define fi first
#define se second
const int N=1e5+5,mod=998244353,P=13331,p=998244353;
int n,q;
int qp(int a,int n,int p){ll cnt=1;while(n){if(n&1){cnt=cnt*a%p;}a=a*a%p;n>>=1;}return cnt;}
int Hash(string s){
	ll cnt=0;
	for(int i=0;i<s.size();i++){
		cnt=(cnt*qp(p,i,P)%P+(s[i]-'a')*p%P+114514)%P;//神人哈希，这么逆天的东西应该不会碰撞 
	}
	return cnt;
}
string ret[P];
set<PII>table;
bool check(){/*这是压缩字符串，遇哈希变大变高 */
	for(PII i:table){string s=ret[i.fi],t=ret[i.se];int cnts=0,cntt=0;for(int j=0;j<s.size();j++){if(s[j]!='a'||t[j]!='b'){	return 0;}
	cnts+=(s[j]=='b');cntt+=(t[j]=='b');} if(cnts!=1||cntt!=1){return 0;}}
}
struct node{
	int pres,pret,sufs,suft;
};
void solve(){
	vector<node>ps;
	for(PII i:table){
		string s=ret[i.fi],t=ret[i.se];
		node cnt;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				cnt.pres=j;
				cnt.sufs=s.size()-j-1;
				break;
			}
		}
		for(int j=0;j<t.size();j++){
			if(t[j]=='b'){
				cnt.pret=j;
				cnt.suft=t.size()-j-1;
				break;
			}
		}
		ps.pb(cnt);
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int pres,pret,sufs,suft,ans=0;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				pres=j;
				sufs=s.size()-j-1;
				break;
			}
		}
		for(int j=0;j<t.size();j++){
			if(t[j]=='b'){
				pret=j;
				suft=t.size()-j-1;
				break;
			}
		}
		for(node i:ps){
			if(i.pres>=pres&&i.sufs>=sufs&&i.pret>=pret&&i.suft>=suft){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
signed main(){
	ios;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		int ss=Hash(s),tt=Hash(t);
		ret[ss]=s;
		ret[tt]=t; 
		if(ss!=tt){
			table.insert({ss,tt});
		}
	}
	if(check()){
		solve();
		return 0;
	}
	while(q--){
		string s,t;
		cin>>s>>t;
		int m=s.size(),ans=0;
		s='1'+s;
		t='2'+t;
		int l=1e9,r=0;
		for(int i=1;i<=m;i++){
			if(s[i]!=t[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		for(int i=l;i>=1;i--){
			for(int j=r;j<=m;j++){
				string ss=s.substr(i,j-i+1),tt=t.substr(i,j-i+1);
				if(table.count({Hash(ss),Hash(tt)})){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

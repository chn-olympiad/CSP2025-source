//replace
#include<bits/stdc++.h>
#define int long long
using namespace std;

const int B=29;
const int N=5e6+5;

string s,t;
int n,m,len,l,r,tot,a[N],tg[N],top;
map<pair<pair<int,int>,pair<int,int>>,int> mp;
map<pair<pair<int,int>,int>,bool> v;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s>>t;
		len=s.size();
		l=0,r=len-1;
		while(l<len&&s[l]==t[l]) l++;		
		if(l==len) continue;
		while(s[r]==t[r]) r--;
		int n1=0,n2=0,n3=0,n4=0;
		for(int j=l;j<=r;++j){
			n1=n1*B+(s[j]-'a'+1);
			n2=n2*B+(t[j]-'a'+1);
		}
		for(int j=l-1;j>=0;--j) n3=n3*B+(s[j]-'a'+1);
		for(int j=r+1;j<len;++j) n4=n4*B+(s[j]-'a'+1);
		if(!mp[{{n1,n2},{n3,n4}}]) mp[{{n1,n2},{n3,n4}}]=++tot;
		v[{{n1,n2},n3}]=1;
		tg[mp[{{n1,n2},{n3,n4}}]]++;
	}
	for(int i=1;i<=m;++i){
		cin>>s>>t;
		len=s.size();
		if(len!=t.size()){
			cout<<"0\n";
			continue;
		}
		l=0,r=len-1;
		while(s[l]==t[l]) l++;		
		while(s[r]==t[r]) r--;
		int n1=0,n2=0,n3=0,n4=0;
		for(int j=l;j<=r;++j){
			n1=n1*B+(s[j]-'a'+1);
			n2=n2*B+(t[j]-'a'+1);
		}
		a[top=1]=0;
		for(int j=r+1;j<len;++j){
			n4=n4*B+(s[j]-'a'+1);
			a[++top]=n4;
		}
		int ans=0;
		if(v[{{n1,n2},n3}]){
			for(int k=1;k<=top;++k) ans+=tg[mp[{{n1,n2},{n3,n4}}]];
		}
		for(int j=l-1;j>=0;--j){
			n3=n3*B+(s[j]-'a'+1);
			if(!v[{{n1,n2},n3}]) continue;
			for(int k=1;k<=top;++k) ans+=tg[mp[{{n1,n2},{n3,a[k]}}]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,L=1e6+5;
using ll=long long;
const ll MOD=93823232313334758;
inline vector<ll> hs(string s){
	vector<ll>res(s.size());
	for(int i=0;i<s.size();++i)res[i]=i>0?(res[i-1]*26+(s[i]-'a'))%MOD:(s[i]-'a');
	return res;
}
array<array<ll,2>,N>HS;
array<ll,L>pw;
inline void pre(){pw[0]=1;for(int i=1;i<=1e6;++i)pw[i]=pw[i-1]*26%MOD;}
inline ll get(const vector<ll>&h,int l,int r){
	ll res=(h[r]-(l>0?h[l-1]:0)*pw[r-l+1])%MOD;
	if(res<0)res+=MOD;
	return res;
}
array<array<string,2>,N>S;
array<array<int,2>,N>diff;
int n,q;
inline void pre2(){
	for(int i=1;i<=n;++i){
		HS[i][0]=hs(S[i][0]).back(),HS[i][1]=hs(S[i][1]).back();
		diff[i]={int(S[i][0].size()),-1};
		for(int j=0;j<S[i][0].size();++j)if(S[i][0][j]!=S[i][1][j]){diff[i][0]=j;break;}
		for(int j=S[i][0].size()-1;~j;--j)if(S[i][0][j]!=S[i][1][j]){diff[i][1]=j;break;}
	}
}
inline int sol(string t1,string t2){
	int l=t1.size(),r=-1;
	for(int j=0;j<t1.size();++j)if(t1[j]!=t2[j]){l=j;break;}
	for(int j=t1.size()-1;~j;--j)if(t1[j]!=t2[j]){r=j;break;}
	auto h1=hs(t1),h2=hs(t2);
	int res=0;
	for(int i=1;i<=n;++i){
		if(r-l+1==diff[i][1]-diff[i][0]+1&&l>=diff[i][0]&&S[i].size()-diff[i][1]-1+r<t1.size()){
			if(get(h1,l-diff[i][0],l-diff[i][0]+S[i][0].size()-1)==HS[i][0]&&get(h2,l-diff[i][0],l-diff[i][0]+S[i][0].size()-1)==HS[i][1])
				++res;
		}
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	string t1,t2;
	for(int i=1;i<=n;++i)cin>>S[i][0]>>S[i][1];
	pre(),pre2();
	for(int i=1;i<=q;++i)cin>>t1>>t2,cout<<sol(t1,t2)<<'\n';
	return 0;
}
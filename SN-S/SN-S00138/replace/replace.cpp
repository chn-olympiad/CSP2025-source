// 夏菁阳 SN-S00138 西安高新第一中学
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define il inline
using namespace std;

using ull=unsigned long long;
constexpr int MAXN=2e5+5,MAXM=5e6+5;
constexpr ull P=13331;
int n,q;
string s[MAXN][2];
ull hs[MAXM],pw[MAXM];
__gnu_pbds::cc_hash_table<ull,vector<int>>mp;
il ull gt(int l,int r){
	return hs[r]-hs[l-1]*pw[r-l+1];
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	pw[0]=1;
	for(int i=1;i<MAXM;i++) pw[i]=pw[i-1]*P;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		ull hs=0;
		for(auto x:s[i][0]) hs=hs*P+x;
		mp[hs].push_back(i);
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(clock()>0.94*CLOCKS_PER_SEC||t1.size()>=1e5||t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		int sz=t1.size(),ans=0;
		t1=' '+t1,t2=' '+t2;
		for(int i=1;i<=sz;i++) hs[i]=hs[i-1]*P+t1[i];
		for(int i=1;i<=sz;i++)
			for(int j=i;j<=sz;j++){
				ull hsh=gt(i,j);
				if(mp.find(hsh)==mp.end()) continue;
				for(auto x:mp[hsh]){
					string tp=t1;
					tp.replace(i,j-i+1,s[x][1]);
					if(tp==t2) ans++;
				}
			}
		cout<<ans<<'\n';
	}
//	cerr<<clock()<<"\n";
	return 0;
}


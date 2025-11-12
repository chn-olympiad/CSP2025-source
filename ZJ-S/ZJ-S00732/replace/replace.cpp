#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int base=13331;
int n,q;
string s1,s2;
//ll hash1[2][5000005],hash2[2][5000005];
map<pair<ull,ull>,int> num;
void solve1(){
	for(int i=1;i<=n;i++){ //O(nlogn+L1)
		cin>>s1>>s2;
		int len=s1.size();
		ull h1=0,h2=0;
		for(int j=0;j<len;j++){
			h1=h1*base+s1[j];
			h2=h2*base+s2[j];
		}
		if(num[{h1,h2}]==0) num[{h1,h2}]=1;
		else num[{h1,h2}]++;
	}
	while(q--){
		cin>>s1>>s2;
		//cout<<s1<<" "<<s2<<"\n";
		if(s1.size()!=s2.size()){
			cout<<"0\n";
			continue;
		}
		int len=s1.size();
		int l=-1,r=len;
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]) break;
			l=i;
		}
		for(int i=len-1;i>=0;i--){
			if(s1[i]!=s2[i]) break;
			r=i;
		}
		ull ans=0;
		for(int i=0;i<=l+1;i++){
			ull h1=0,h2=0;
			for(int j=i;j<len;j++){
				h1=h1*base+s1[j];
				h2=h2*base+s2[j];
				if(j>=r-1&&num[{h1,h2}]>0) ans+=num[{h1,h2}];
			}
		}
		cout<<ans<<"\n";
		//cout<<"!!!"<<q<<"\n";
	}
}
ll quickpow(ll x,ll y,ll mod){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
//void solve2(){
//	ll mod1=1e9+7;
//	for(int i=1;i<=n;i++){ //O(nlogn+L1)
//		cin>>s1>>s2;
//		int len=s1.size();
//		ll h1=0,h2=0;
//		for(int j=0;j<len;j++){
//			h1=(h1*base+s1[j])%mod1;
//			h2=(h2*base+s2[j])%mod1;
//		}
//		if(num[{h1,h2}]==0) num[{h1,h2}]=1;
//		else num[{h1,h2}]++;
//	}
//	while(q--){
//		cin>>s1>>s2;
//		//cout<<s1<<" "<<s2<<"\n";
//		if(s1.size()!=s2.size()){
//			cout<<"0\n";
//			continue;
//		}
//		int len=s1.size();
//		int l=-1,r=len;
//		for(int i=0;i<len;i++){
//			if(s1[i]!=s2[i]) break;
//			l=i;
//		}
//		for(int i=len-1;i>=0;i--){
//			if(s1[i]!=s2[i]) break;
//			r=i;
//		}
//		hash1[0][0]=s1[i];
//		hash2[0][0]=s2[i];
//		for(int i=1;i<len;i++){
//			hash1[0][i]=(hash1[0][i-1]*base+s1[i])%mod;
//			hash2[0][i]=(hash2[0][i-1]*base+s2[i])%mod;
//		}
//		
//		
////		ull ans=0;
////		for(int i=0;i<=l+1;i++){
////			ull h1=0,h2=0;
////			for(int j=i;j<len;j++){
////				h1=h1*base+s1[j];
////				h2=h2*base+s2[j];
////				if(j>=r-1&&num[{h1,h2}]>0) ans+=num[{h1,h2}];
////			}
////		}
////		cout<<ans<<"\n";
//		//cout<<"!!!"<<q<<"\n";
//	}
//}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	solve1();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/
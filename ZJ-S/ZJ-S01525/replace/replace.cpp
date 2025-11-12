#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

const int N=2e5+5;
const int L=2.5e6+10;
typedef unsigned long long ull;
unsigned long long ha1[N];
unsigned long long ha2[N];
ull base1=131;
ull base2=141;
ull mod=1e9+7;

char s1[L],s2[L];
int len[N];
ull shash1[N];
ull shash2[N];

map<pair<ull,int> ,int>mp;

ull qpow1(ull a,ull b){
	ull ret=1;
	while(b){
		if(b&1) ret=ret*a;
		b>>=1;
		a=a*a;
	}
	return ret;
}

ull qpow2(ull a,ull b,ull mod){
	ull ret=1;
	while(b){
		if(b&1) ret=ret*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return ret;
}

ull thash1[L];
ull thash2[L];

pair<ull,int> subthash(int l,int r){
	if(l==0) return {thash1[r],thash2[r]};
	pair<ull,int> ret;
	ret.first=thash1[r]-thash1[l-1]*qpow1(base1,2*(r-l+1));
	ret.second=(int)thash2[r]-thash2[l-1]*qpow2(base2,2*(r-l+1),mod)%mod;
	if(ret.second<0) ret.second+=mod;
	return ret;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out" ,"w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%s",s1);
		scanf("%s",s2);
		len[i]=strlen(s1);
		for(int j=0;j<len[i];j++){
			shash1[i]=shash1[i]*base1*base1+s1[j]*base1+s2[j];
			shash2[i]=shash2[i]*base2%mod*base2%mod+s1[j]*base2%mod+s2[j];
			shash2[i]%=mod;
		}
//		cerr<<shash1[i]<<" "<<shash2[i]<<"\n";
		mp[{shash1[i],shash2[i]}]+=1;
	}
		while(q--){
		scanf("%s",s1);
		scanf("%s",s2);
		int tlen=strlen(s1);
		int l=n,r=n;
		for(int i=0;i<tlen;i++){
			if(s1[i]!=s2[i]){
				if(l==n) l=i;
				r=i;
			}
			thash1[i]=thash1[i-1]*base1*base1+s1[i]*base1+s2[i];
			thash2[i]=thash2[i-1]*base2%mod*base2%mod+s1[i]*base2%mod+s2[i];
			thash2[i]%=mod;
		}
//		cerr<<l<<" "<<r<<"\n";
		int ans=0;
		for(int i=0;i<=l;i++){
			for(int j=r;j<tlen;j++){
				pair<ull,int> hs=subthash(i,j);
//				cerr<<"["<<i<<","<<j<<"] "<<hs.first<<" "<<hs.second<<"\n";
				if(mp.find(hs)!=mp.end()) ans+=mp[hs];
			}
		}
		printf("%d\n",ans);
	}
}

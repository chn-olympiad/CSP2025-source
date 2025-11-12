#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int N=2e5+5;
const int mod=20090813;
const int base=131;
map<PII,int> mp;
int qpow[N];
int hs[3][N];
int gethash_qwq(int l,int r,int opt){
	if(r<l){
		return 0;
	}
	return ((hs[opt][r]-hs[opt][l-1]*qpow[r-l+1])%mod+mod)%mod;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	qpow[0]=1;
	for(int i=0;i<N;i++){
		qpow[i]=qpow[i-1]*base%mod;
	}
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
//		cout<<s1<<' '<<s2<<"***\n"; 
		int hs1=0,hs2=0;
		for(int j=0;j<s1.size();j++){
			hs1=(s1[j]-'a')+hs1*base%mod;
			hs2=(s2[j]-'a')+hs2*base%mod;
			hs1%=mod;hs2%=mod;
//			cout<<j<<' '<<hs1<<' '<<hs2<<"***\n";
		}
		hs1=(hs1+mod)%mod;
		hs2=(hs2+mod)%mod;
		cout<<hs1<<' '<<hs2<<"***\n";
		mp[{hs1,hs2}]=1;
	} 
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		t1=" "+t1;t2=" "+t2;
		for(int j=1;j<=len;j++){
			hs[1][j]=(hs[1][j-1]*base%mod+t1[j]-'a'+mod)%mod;
			hs[2][j]=(hs[2][j-1]*base%mod+t2[j]-'a'+mod)%mod;
		}
		int ans=0; 
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
//				cout<<l<<' '<<r<<' '<<gethash_qwq(l,r,1)<<' '<<gethash_qwq(l,r,2)<<"***\n";
				if(gethash_qwq(1,l-1,1)==gethash_qwq(1,l-1,2)&&mp[{gethash_qwq(l,r,1),gethash_qwq(l,r,2)}]&&gethash_qwq(r+1,n,1)==gethash_qwq(r+1,n,2)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

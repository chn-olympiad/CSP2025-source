#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q;
unordered_map<int,int> mp;
int ha1[201000],ha2[201000];
int ah1[201000],ah2[201000];
int mod=998244353;
int pw[201000];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	pw[0]=1;
	for(int i=1;i<=201000;i++){
		pw[i]=(pw[i-1]*131)%mod;
	}
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int hs=0;
		for(int j=0;j<s1.size();j++){
			hs=hs*131+s1[j];
			hs%=mod;
		}
		int hs2=0;
		for(int j=0;j<s2.size();j++){
			hs2=hs2*131+s2[j];
			hs2%=mod;
		}
		mp[hs]=hs2;
	}
	for(int I=1;I<=m;I++){
		string t1,t2;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();i++){
			ha1[i]=ha1[i-1]*131+t1[i];
			ha1[i]%=mod;
			ha2[i]=ha2[i-1]*131+t2[i];
			ha2[i]%=mod;
		}
		ah1[t1.size()]=ah2[t1.size()]=0;
		for(int i=t1.size()-1;i>=0;i--){
			ah1[i]=ha1[i+1]*131+t1[i];
			ah1[i]%=mod;
			ah2[i]=ha2[i+1]*131+t2[i];
			ah2[i]%=mod;
		}
		int st=0,ed=0;
		int ans=0;
		for(int l=0;l<t1.size();l++){
			for(int r=l;r<t1.size();r++){
				int hash1=((ha1[r]-ha1[l-1]*pw[r-l+1])%mod+mod)%mod;
				int hash2=((ha2[r]-ha2[l-1]*pw[r-l+1])%mod+mod)%mod;
				if(mp[hash1]==hash2&&ha1[l-1]==ha2[l-1]&&ah1[r+1]==ah2[r+1]){
					ans++;
					//cout<<l<<" "<<r<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


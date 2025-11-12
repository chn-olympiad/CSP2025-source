#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e4+5,M=3e6+5;
int n,q,p=227,mod=1e9+7,vis[N],hs1[N],hs2[N],ans;
vector<int> s;
map<pair<int,int> ,bool> mp;
int qpow(int a,int b){
	int sum=1;
	while(b){
		if(b&1) sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int sum1=0,sum2=0,sz;
		sz=s1.size();
		s1=' '+s1;
		s2=' '+s2;
		if(!vis[sz]) s.push_back(sz);
		vis[sz]=1;
		for(int j=1;j<=sz;j++){
			sum1=sum1*p%mod+s1[j]-'a';
			sum1%=mod;
		}
		for(int j=1;j<=sz;j++){
			sum2=sum2*p%mod+s2[j]-'a';
			sum2%=mod;
		}
		//cout<<sum1<<' '<<sum2<<endl;
		mp[make_pair(sum1,sum2)]=1;
	}
	while(q--){
		ans=0;
		int sz;
		string s1,s2;
		cin>>s1>>s2;
		sz=s1.size();
		s1=' '+s1;
		s2=' '+s2;
		//cout<<hs1[sz]<<" "<<hs2[sz]<<endl;
		for(int i=1;i<=sz;i++){
			hs1[i]=hs1[i-1]*p%mod+s1[i]-'a';
			hs1[i]%=mod;
			//cout<<hs1[i]<<' ';
		}
		for(int i=1;i<=sz;i++){
			hs2[i]=hs2[i-1]*p%mod+s2[i]-'a';
			hs2[i]%=mod;
		}
		//cout<<hs1[sz]<<' '<<hs2[sz]<<" ";
		for(int i=1;i<=sz;i++){
			for(int j=0;j<s.size();j++){
				if(s[j]>i) continue;
				//cout<<hs1[i]<<" "<<s[j]<<" "<<hs1[i-s[j]]*qpow(p,s[j])<<endl;
				if(hs1[i-s[j]]==hs2[i-s[j]]&&hs1[sz-i]==hs2[sz-i]&&mp[make_pair((hs1[i]+mod-hs1[i-s[j]]*qpow(p,s[j])%mod)%mod,(hs2[i]+mod-hs2[i-s[j]]*qpow(p,s[j])%mod)%mod)]){
					//cout<<"haha";
					//ans=1;
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

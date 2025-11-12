#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const long long base=31,mod=998244353;
string s[200010],t[200010];
long long hs[200010],ht[200010],hsh1[5000010],hsh2[5000010],pw[5000010];
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	pw[0]=1;
	for(int i=1;i<=5000000;i++)pw[i]=(pw[i-1]*base)%mod;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		int x=s[i].size();
		for(int j=1;j<=x;j++){
			hs[i]=(hs[i]*base+(s[i][j-1]-'a'+1))%mod;
		} 
		for(int j=1;j<=x;j++){
			ht[i]=(ht[i]*base+(t[i][j-1]-'a'+1))%mod;
		} 
	}
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;int r=x.size(),c=y.size();
		if(r!=c){
			cout<<"0\n";
			continue;
		}
		hsh1[0]=hsh2[0]=0;
		for(int j=1;j<=r;j++){
			hsh1[j]=(hsh1[j-1]*base+(x[j-1]-'a'+1))%mod;
		}
		for(int j=1;j<=r;j++){
			hsh2[j]=(hsh2[j-1]*base+(y[j-1]-'a'+1))%mod;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			int k=s[j].size();
			for(int st=1;st<=r-k+1;st++){
				long long hshs=(hsh1[st+k-1]-hsh1[st-1]*pw[k]+mod)%mod;
				if(hshs==hs[j]){
					long long xx=(hsh1[r]-hshs*pw[r-st-k+1]+mod)%mod;
					xx+=ht[j]*pw[r-st-k+1];
					xx%=mod;
					if(xx==hsh2[r])++ans;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

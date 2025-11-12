#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,q,ans=0;
string a[N],b[N],s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0;
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<"\n";
			continue;
		}
		else{
			ll len=s1.length();
			for(ll i=1;i<=n;i++){
				for(ll j=0;j+a[i].length()<=len;j++){
					bool flag=1;
					for(ll k=j;k<j+a[i].length();k++){
						if(s1[k]!=a[i][k-j]){
							flag=0;
							break;
						}
					}
					if(flag){
						for(ll k=j;k<j+a[i].length();k++){
							if(s2[k]!=b[i][k-j]){
								flag=0;
								break;
							}
						}
						if(flag){
							for(ll k=0;k<j;k++){
								if(s2[k]!=s1[k]){
									flag=0;
									break;
								}
							}
							if(flag){
								for(ll k=j+a[i].length();k<len;k++){
									if(s2[k]!=s1[k]){
										flag=0;
										break;
									}
								}
								if(flag)ans++;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
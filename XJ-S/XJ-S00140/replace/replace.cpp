#include<bits/stdc++.h> 
using namespace std;
const long long mod=2147483647;
string er1[1005],er2[1005],qq[2];
int n,q;
long long hs(string ss){
	long long sum=0;
	for(int i=ss.size();i>0;i--){
		sum=(sum*27+(ss[i]-97))%mod;
	}
	return sum%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>er1[i]>>er2[i];
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		cin>>qq[0]>>qq[1];
		for(int j=0;j<qq[0].size();j++){
			for(int op=1;op<=n;op++){
				string ssss=qq[0];
				int flag=0;
				if(j+er1[op].size()>qq[0].size()){
					continue;
				}
				for(int pp=j;pp<er1[op].size();pp++){
					if(qq[0][pp]!=er1[op][pp]){
						flag=1;
						break;
					}
				}
				if(flag==0){
					long long tu=1;
					for(int ip=1;ip<=j;ip++){
						tu=tu*27%mod;
					}
					if((hs(qq[0])*tu%mod+hs(er2[op])%mod-hs(er1[op])%mod)%mod==hs(qq[1])*tu%mod){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

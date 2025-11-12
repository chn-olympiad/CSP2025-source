#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e6+10,P=19260817,mod=998244353;
ll n,q,h1[N],h2[N],hs1[N],hs2[N],p[N],len1[N],len2[N],ans;
ll get_hash1(ll l,ll r){
	return ((h1[r]-h1[l-1]*p[r-l+1]%mod)%mod+mod)%mod;
}
ll get_hash2(ll l,ll r){
	return ((h2[r]-h2[l-1]*p[r-l+1]%mod)%mod+mod)%mod;
}
string t1,t2,s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	p[0]=1;
	for(ll i=1;i<=5e6;i++) p[i]=p[i-1]*P%mod;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len1[i]=s1[i].length();
		len2[i]=s2[i].length();
		s1[i]="*"+s1[i];s2[i]="*"+s2[i];
		//cout<<len1[i]<<" "<<len2[i]<<endl;
		for(ll j=1;j<=len1[i];j++){
			hs1[i]*=P;hs1[i]%=mod;
			//cout<<hs1[i]<<" ";
			hs1[i]+=(ll)s1[i][j];hs1[i]%=mod;
			//cout<<hs1[i]<<" ";
		}
		//cout<<endl;
		for(ll j=1;j<=len2[i];j++){
			hs2[i]*=P;hs2[i]%=mod;
			hs2[i]+=(ll)s2[i][j];hs2[i]%=mod;
		}
		//cout<<hs1[i]<<" "<<hs2[i]<<endl;
	}
	while(q--){
		ans=0;
		cin>>t1>>t2;
		ll l1=t1.length(),l2=t2.length();
		t1="*"+t1;t2="*"+t2;
		for(ll i=1;i<=l1;i++) h1[i]=(h1[i-1]*P%mod+t1[i])%mod;
		for(ll i=1;i<=l2;i++) h2[i]=(h2[i-1]*P%mod+t2[i])%mod;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j+len1[i]-1<=l1;j++){
				if(j>l2) break;
				if(get_hash1(j,j+len1[i]-1)!=hs1[i]) continue;
				if(j!=1 and get_hash1(1,j-1)!=get_hash2(1,j-1)) continue;
				//cout<<i<<" "<<j<<endl;
				//cout<<j<<" "<<j+len1[i]-1<<" "<<l2<<endl;
				//cout<<get_hash2(j,j+len1[i]-1)<<endl;
				if(j+len1[i]-1>l2 or hs2[i]!=get_hash2(j,j+len1[i]-1)) continue;
				ll rest=l1-(j+len1[i]-1);
				//cout<<i<<" "<<j<<endl;
				if(rest!=0){
					if(j+len1[i]-1+rest!=l2) continue;
					if(get_hash1(j+len1[i],l1)!=get_hash2(l2-rest+1,l2)) continue;
				}
				//cout<<i<<" "<<j<<endl;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=5e6+10,P=131;
const ll mod=114514191981019;
ll n,q,ha1[N],ha2[N];
ll ha3[N],ha4[N],len[N],p[N];
char s1[N],s2[N],t1[N],t2[N];
ll get_ha3(ll l,ll r){
	return (ha3[r]-ha3[l-1]*p[r-l+1]%mod+mod)%mod;
}
ll get_ha4(ll l,ll r){
	return (ha4[r]-ha4[l-1]*p[r-l+1]%mod+mod)%mod;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		len[i]=strlen(s1+1);
		for(ll j=1;j<=len[i];j++){
			ha1[i]=(ha1[i]*P%mod+s1[j])%mod;
			ha2[i]=(ha2[i]*P%mod+s2[j])%mod;
		}	
	}
	p[0]=1;
	for(ll i=1;i<=n;i++){
		p[i]=p[i-1]*P%mod;
	}
	while(q--){
		scanf("%s%s",t1+1,t2+1);
		ll l1=strlen(t1+1),l2=strlen(t2+1);
		if(l1!=l2||l1*n>1e7){
			printf("0\n");
			continue;
		}
		ll l=l1;
		ha3[0]=ha4[0]=0;
		for(ll i=1;i<=l;i++){
			ha3[i]=(ha3[i-1]*P%mod+t1[i])%mod;
			ha4[i]=(ha4[i-1]*P%mod+t2[i])%mod;
		}
		ll ans=0;
		for(ll i=1;i<=l;i++){
			if(i>1&&get_ha3(1,i-1)!=get_ha4(1,i-1))break;
			for(ll j=1;j<=n;j++){
				if(i+len[j]-1>l)continue;
				if(ha1[j]==get_ha3(i,i+len[j]-1)&&ha2[j]==get_ha4(i,i+len[j]-1)){
					if(i+len[j]<=l&&get_ha3(i+len[j],l)!=get_ha4(i+len[j],l))continue;
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 

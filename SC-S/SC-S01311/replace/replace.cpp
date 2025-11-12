#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int S=5e6+5;
const ll mod1=998244353;
const ll mod2=1000000009;
const ll C=27;
int n,q,L,R;
string s,t;
set<pair<ll,ll>>trans; 
ll k1,k2,k3,k4,pre1[S],pre2[S],pre3[S],pre4[S],pw1[S],pw2[S];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=5000000;i++){
		pw1[i]=pw1[i-1]*C%mod1;
		pw2[i]=pw2[i-1]*C%mod2;
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s>>t;
		k1=k2=k3=k4=0;
		for(int j=0;j<s.size();j++){
			k1=(k1*C+s[j]-'a'+1)%mod1;
			k2=(k2*C+s[j]-'a'+1)%mod2;
			k3=(k3*C+t[j]-'a'+1)%mod1;
			k4=(k4*C+t[j]-'a'+1)%mod2;
		}
		trans.insert({k1*mod2+k2,k3*mod2+k4});
	}
	while(q--){
		int ans=0;
		cin>>s>>t;
		pre1[0]=pre2[0]=pre3[0]=pre4[0]=0;
		for(int i=0;i<s.size();i++){
			pre1[i+1]=pre1[i]=(pre1[i]*C+s[i]-'a'+1)%mod1;
			pre2[i+1]=pre2[i]=(pre2[i]*C+s[i]-'a'+1)%mod2;
			pre3[i+1]=pre3[i]=(pre3[i]*C+t[i]-'a'+1)%mod1;
			pre4[i+1]=pre4[i]=(pre4[i]*C+t[i]-'a'+1)%mod2;
		}
		for(int i=0;i<s.size();i++)if(s[i]^t[i]){L=i;break;}
		for(int i=s.size()-1;~i;i--)if(s[i]^t[i]){R=i;break;} 
		for(int l=0;l<=L;l++)
		for(int r=R;r<s.size();r++){
			k1=(pre1[r]-(l?pre1[l-1]:0)*pw1[r-l+1]%mod1)%mod1;
			k2=(pre2[r]-(l?pre2[l-1]:0)*pw2[r-l+1]%mod2)%mod2;
			k3=(pre3[r]-(l?pre3[l-1]:0)*pw1[r-l+1]%mod1)%mod1;
			k4=(pre4[r]-(l?pre4[l-1]:0)*pw2[r-l+1]%mod2)%mod2;
			if(trans.count({k1*mod2+k2,k3*mod2+k4}))
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
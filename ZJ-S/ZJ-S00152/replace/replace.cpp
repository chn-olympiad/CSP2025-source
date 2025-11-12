#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+10;
const ll mod=2147483647;


ll qpow(int a,int b){//a^b
	ll ans=1;
	while(b){
		if(b%2==0){
			b/=2,a=a*a%mod;
		}
		else ans=ans*a%mod,b--;
	}
	return ans;
}
ll htp(int l,int r,ll arr[]){
	if(l==0)return arr[r];
	return (arr[r]-arr[l-1]*qpow(131,r-l+1)+mod)%mod;
}




struct dbs{
	string s1,s2;
}s[N];
int len[N];
bool cmp(dbs a,dbs b){
	return a.s1.size()<b.s1.size();
}

string substr(string sss,int l,int lth){
	string ans=0;
	for(int i=l;i <= l+lth-1;i++){
		ans+=sss[i];
	}
	return ans;
}

int n,q;
string t,p;
ll hs[N][3];
ll hashs(string s){
	ll ans;
	int sz=s.size();
	for(int x=0;x<sz;x++){
		int k=s[x]-'a';
		ans=(ans*131)%mod+k;
	}
	return ans;
}
int solve(){
	int ans=0;
	int szt=t.size(),szp=p.size();
	if(szt!=szp)return 0;
	int l=-1,r=-1;
	for(int i=0;i<szt;i++){
		if(l==-1&&p[i]!=t[i])l=i;
		if(t[i]!=p[i])r=i;
	}
	if(l==-1)return 0;
	ll ht[szt+10]={t[0]-'a'+1},hp[szp+10]={p[0]-'a'+1};
	for(int i=1;i<szt;i++){
		ht[i]=((ht[i-1]*131)%mod+(t[i]-'a'+1))%mod;
	}
	for(int i=1;i<szp;i++){
		hp[i]=((hp[i-1]*131)%mod+(p[i]-'a'+1))%mod;
	}
	for(int lll=0;lll<=l;lll++){
		for(int rr=r;rr<szt;rr++){
			int lth=rr-lll+1;
			int x=lower_bound(len,len+n,lth)-len;
			for(int i=x;(int)(s[i].s1.size())==lth;i++){
				if(htp(lll,rr,ht)==htp(lll,rr,hp))continue;
				if(htp(lll,rr,ht)==hs[i][1]&&htp(lll,rr,hp)==hs[i][2])ans++;
				
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s[i].s1 >> s[i].s2;
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++){
		len[i]=s[i].s1.size();
		
		hs[i][1]=s[i].s1[0]-'a'+1,hs[i][2]=s[i].s2[0]-'a'+1;
		for(int j=1;j<len[i];j++){
			hs[i][1]=((hs[i][1]*131)%mod+(s[i].s1[j]-'a'+1))%mod;
		}
		for(int j=1;j<len[i];j++){
			hs[i][2]=((hs[i][2]*131)%mod+(s[i].s2[j]-'a'+1))%mod;
		}
	}
	for(int i=1;i<=q;i++){
		cin >> t >> p;
		cout << solve() << "\n";
	}
	return 0;
}

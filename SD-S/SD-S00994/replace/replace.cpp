#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<ll,ll>
#define mp make_pair
using namespace std;
const ll N=2e5+10;
const ll M=5e6+10;
const ll INF=1e9;
ll n,q,l,r,ans;
ull sum[M],h1[M],h2[M],sh[N][3];
string t1,t2,s[N][3];
ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-48;
		ch=getchar();
	}
	return ret*f;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	sum[0]=1;
	for(ll i=1;i<=5000010;i++)sum[i]=sum[i-1]*13331;
	for(ll i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		for(ll j=0;j<s[i][1].size();j++)sh[i][1]=sh[i][1]*13331+s[i][1][j];
		for(ll j=0;j<s[i][2].size();j++)sh[i][2]=sh[i][2]*13331+s[i][2][j];
	}
	while(q--){
		ans=r=0;l=INF;
		cin>>t1>>t2;
		for(ll i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				l=min(l,i);
				r=max(r,i);
			}
		}
		h1[0]=t1[0];
		for(ll i=1;i<t1.size();i++)h1[i]=h1[i-1]*13331+t1[i];
		h2[0]=t2[0];
		for(ll i=1;i<t2.size();i++)h2[i]=h2[i-1]*13331+t2[i];
		for(ll i=1;i<=n;i++){
			if(s[i][1].size()>=r-l+1){	
				for(ll last=r-s[i][1].size()+1;last<=l&&last+s[i][1].size()-1<t1.size();last++){
					if(last<0)continue;
					if(last<=l&&last+s[i][1].size()-1>=r&&sh[i][1]==h1[last+s[i][1].size()-1]-h1[last-1]*sum[s[i][1].size()]&&sh[i][2]==h2[last+s[i][1].size()-1]-h2[last-1]*sum[s[i][1].size()]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

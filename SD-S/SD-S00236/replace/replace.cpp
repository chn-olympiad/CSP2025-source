#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
const int INF=1e18;
const int base=177;
const int mod=998244353;
int st;
struct node{
	string s1,s2;
	int hs1,hs2;
};
node cj[N];
int lg[N];
void init(){
	lg[0]=1;
	for(int i=1;i<=N-10;i++){
		lg[i]=lg[i-1]*base%mod;
	}
}
int sm[N],smm[N];
int get(int l,int r){
	return ((sm[r]-(sm[l-1]*lg[r-l+1])+mod)%mod+mod)%mod;
}
int gett(int l,int r){
	return (smm[r]-smm[l-1]*lg[r-l+1]+mod)%mod;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	init();
	for(int i=1;i<=n;i++){
		cin>>cj[i].s1>>cj[i].s2;
		string s=cj[i].s1,t=cj[i].s2;
		int hs1=0,hs2=0;
		for(int j=0;j<s.size();j++){
			hs1=hs1*base+(s[j]-'a'+1);hs1%=mod;
		}
		for(int j=0;j<t.size();j++){
			hs2=hs2*base+(t[j]-'a'+1);hs2%=mod;
		}
		cj[i].hs1=hs1;cj[i].hs2=hs2;
	}
	if(q>10000){
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		s=' '+s;t=' '+t;
		for(int j=1;j<s.size();j++){
			sm[j]=sm[j-1]*base+(s[j]-'a'+1);sm[j]%=mod;
		}
		for(int j=1;j<t.size();j++){
			smm[j]=smm[j-1]*base+(t[j]-'a'+1);smm[j]%=mod;
		}
		int ans=0;
		int hs1=sm[s.size()-1],hs2=smm[t.size()-1];
		for(int j=1;j<=n;j++){
//			cout<<'j'<<j<<endl;
			for(int k=1;k+cj[j].s1.size()-1<s.size();k++){
//				cout<<k<<endl;
//				cout<<"k"<<k<<endl;
//				cout<<k<<" "<<k+cj[j].s1.size()-1<<endl;
//				cout<<cj[j].hs1<<" "<<get(k,k+cj[j].s1.size()-1)<<endl;
				if(cj[j].hs1==get(k,k+cj[j].s1.size()-1)){
					int x=t.size()-1-(k+cj[j].s1.size())+1;
//					cout<<x<<endl;
//					int len=cj[j].s1.size();
					if((hs1-get(k,k+cj[j].s1.size()-1)+cj[j].hs2*lg[x-1]+mod)%mod==hs2){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<array>
#include<vector>
#include<string>
using namespace std;
int n,q;
//const unsigned long long mod1=998244353ull,p1=98290289ull;
const long long mod=998244353ll,p=13333331ll;
long long pn[5000001];//p1n[5000001],
//int len[200001];
//map<unsigned,unsigned> replace;//1,replace2; 
string s1,s2,t1,t2;
int st1[5000001],st2[5000001];
long long dp[5000001];
vector<pair<int,pair<int,int>>> vp;
bool check(int l,int r){
	return ((st1[r]-(st1[l-1]*pn[r-l+1])%mod)%mod+mod)%mod==((st2[r]-(st2[l-1]*pn[r-l+1])%mod)%mod+mod)%mod;
}
long long up(long long x){
	if(x<0){
		x+=mod;
	}
	return x;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pn[0]=1ull;
	for(int i=1;i<=5000000;i++){
		pn[i]=int(pn[i-1]*p%mod);
	}
//	p2n[0]=1ull;
//	for(int i=1;i<=5000000;i++){
//		p2n[i]=unsigned(p2n[i-1]*p2%mod2);
//	}
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int val1=0,val2=0;
		for(auto j:s1){
			val1=((val1*p)%mod+j)%mod;
		}
		for(auto j:s2){
			val2=((val2*p)%mod+j)%mod;
		}
		vp.push_back({(int)s1.size(),{val1,val2}});
//		cout<<val1<<'\t'<<val2<<'\n';
	}
//	cout<<'\n';
	sort(vp.begin(),vp.end());
	while(q--){
//		cerr<<q<<'\n';
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		long long ans=0;
		for(int i=1;i<=t1.size();i++){
			st1[i]=(st1[i-1]*p%mod+t1[i-1])%mod;
			st2[i]=(st2[i-1]*p%mod+t2[i-1])%mod;
//			cout<<st1[i]<<'\t'<<st2[i]<<'\n';
		}
		int l=1,r=t1.size(),pre=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(1,mid)){
				pre=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		l=1,r=t1.size();
		int suf=t1.size()+1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,(int)t1.size())){
				suf=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
				}
//				cerr<<t1.size()<<'\t';
//				cerr<<pre<<'\t'<<suf<<'\n';
		for(auto &j:vp){
			if(suf-1-pre>j.first)continue;
			if(j.first>t1.size())break;
			int ll=max(suf-1,j.first),rr=min((int)t1.size(),pre+j.first);
			if(ll>rr)continue;
			for(int i=ll;i<=rr;i++){
				if(up((st1[i]-(st1[i-j.first]*pn[j.first])%mod)%mod)==j.second.first&&
				up((st2[i]-(st2[i-j.first]*pn[j.first])%mod)%mod)==j.second.second){
//				cerr<<j.first<<'\t';
//				cerr<<((st1[i]-(st1[i-j.first]*pn[j.first])%mod)%mod+mod)%mod<<'\t'<<j.second.first<<'\t';
//				cerr<<((st2[i]-(st2[i-j.first]*pn[j.first])%mod)%mod+mod)%mod<<'\t'<<j.second.second<<'\n';
					ans++;
//					system("pause");
//					cout<<i<<'\t'<<(j.first)<<'\n';
				}
			}
		}
		cout<<ans<<'\n';
	}
//	fflush(stdout);
	return 0;
}

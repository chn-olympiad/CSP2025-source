#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5;
const int base=177,mod=998244353,modd=1e9+7;
//unordered_map<int,int> mp;
map<pair<int,int>,int> mpl;
unordered_map<int,int>mpp[1000005];
int cnt,cntt;
int n,q,m,l,r;
int sum[N],summ[N],ssum[N],ssumm[N],lg[N],lgg[N];
int get_1(int l,int r){
	int x=(sum[r]-sum[l-1]*lg[r-l+1]%mod+mod)%mod,y=(summ[r]-summ[l-1]*lgg[r-l+1]%modd+modd)%modd;
	return mpl[make_pair(x,y)];
}
int get_2(int l,int r){
	int x=(ssum[r]-ssum[l-1]*lg[r-l+1]%mod+mod)%mod,y=(ssumm[r]-ssumm[l-1]*lgg[r-l+1]%modd+modd)%modd;
	return mpl[make_pair(x,y)];
}
int ask(){
	int ans=0;
	for(int i=1;i<=l;i++){
		for(int j=r;j<=m;j++){
			ans+=mpp[get_1(i,j)][get_2(i,j)];
		}
	}return ans;
}
string ss[200005],tt[200005];
struct node{
	int l,r,x;
}v[200005];
vector<int> vec[400005];
string ee[200005],rr[200005];
bool cmpp(int x,int y){
	return v[x].l<v[y].l;
}
signed main(){
//	freopen("replace4.in","r",stdin);
//	freopen("test.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	lg[0]=1;lgg[0]=1;
	int ghflag=0;
	for(int i=1;i<=5e6;i++) lg[i]=lg[i-1]*base%mod,lgg[i]=lgg[i-1]*base%mod;;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		s=" "+s;
		t=" "+t;
		ss[i]=s;
		tt[i]=t;
		int gh=0,ggh=0;
		for(int j=1;j<s.size();j++){
			if(s[j]!='a'){
				if(s[j]=='b') gh++;
				else gh=-1e18;
			}
			if(t[j]!='a'){
				if(t[j]=='b') ggh++;
				else ggh=-1e18;
			}
		}
		if(gh==1&&ggh==1){
			ghflag++;
		}
		int sum_=0,summ_=0,ssum_=0,ssumm_=0;
		if(s==t) continue;
		for(int j=1;j<s.size();j++){
			sum_=(sum_*base+s[j])%mod;
			summ_=(summ_*base+s[j])%modd;
			ssum_=(ssum_*base+t[j])%mod;
			ssumm_=(ssumm_*base+t[j])%modd;
		}
		if(mpl[make_pair(sum_,summ_)]==0)mpl[make_pair(sum_,summ_)]=++cntt;
		if(mpl[make_pair(ssum_,ssumm_)]==0)mpl[make_pair(ssum_,ssumm_)]=++cntt;
		mpp[mpl[make_pair(sum_,summ_)]][mpl[make_pair(ssum_,ssumm_)]]++;
	}
	int tflag=0;
	for(int i=1;i<=q;i++){
		cin>>ee[i]>>rr[i];
		ee[i]=" "+ee[i];
		rr[i]=" "+rr[i];
		string s=ee[i],t=rr[i];
		int gh=0,ggh=0;
		for(int j=1;j<s.size();j++){
			if(s[j]!='a'){
				if(s[j]=='b') gh++;
				else gh=-1e18;
			}
			if(t[j]!='a'){
				if(t[j]=='b') ggh++;
				else ggh=-1e18;
			}
		}
		if(gh==1&&ggh==1){
			tflag++;
		}
	}
	if(tflag==q&&ghflag==n){
		for(int i=1;i<=n;i++){
			int pos=0,poss=0;
			for(int j=1;j<ss[i].size();j++){
				if(ss[i][j]=='b') pos=j;
				if(tt[i][j]=='b') poss=j;
			}
			v[i].x=pos-poss;
			v[i].l=pos-1;
			v[i].r=ss[i].size()-1-pos;
			vec[v[i].x+200000].push_back(i);
		}
		for(int i=0;i<=400000;i++) sort(vec[i].begin(),vec[i].end(),cmpp);
		for(int i=1;i<=q;i++){
			string s=ee[i],t=rr[i];
			m=s.size()-1;
			int res=0;
			int pos=0,poss=0;
			for(int j=1;j<=m;j++){
				if(s[j]=='b') pos=j;
				if(t[j]=='b') poss=j;
			}
			int x=pos-poss;
			for(auto j:vec[x+200000]){
				if(v[j].l>pos-1) break;
				if(v[j].l<=pos-1&&v[j].r<=m-pos) res++;
			}
			cout<<res<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		string s=ee[i],t=rr[i];
		l=1e18,r=0;
		for(int j=1;j<s.size();j++){
			if(s[j]!=t[j]){
				l=min(l,j);
				r=j;
			}
		}
		m=s.size()-1;
		for(int j=1;j<=m;j++){
			sum[j]=(sum[j-1]*base+s[j])%mod;
			summ[j]=(summ[j-1]*base+s[j])%modd;
			ssum[j]=(ssum[j-1]*base+t[j])%mod;
			ssumm[j]=(ssumm[j-1]*base+t[j])%modd;
		}
		cout<<ask()<<"\n";
	}
	return 0;
}

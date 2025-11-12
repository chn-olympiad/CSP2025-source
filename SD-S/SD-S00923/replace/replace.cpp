#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=2e5+10,L=2e6+10,INF=0x3f3f3f3f3f3f3f3f;
const int mod[]={1000000009,998244853};
const int bs[]={13331,17};
struct Hash{
	int v[2];
	Hash(){v[0]=v[1]=0;}
};
bool operator<(Hash x,Hash y){
	return (x.v[0]==y.v[0])?x.v[1]<y.v[1]:x.v[0]<y.v[0];
}
typedef pair<Hash,Hash> phh;
Hash operator+(Hash x,char y){
	Hash res=x;
	for(int i=0;i<2;i++)
		res.v[i]=(res.v[i]*bs[i]+y)%mod[i];
	return res;
}
int n,q;
char s1[L],s2[L];
map<phh,int> hmp;
vector<int> lens;
Hash h[2][L];
void bf(){
	for(int i=1;i<=q;i++){
//	cerr<<i<<endl;
		cin>>(s1+1)>>(s2+1);
		int mn=INF,mx=0;
		int len=strlen(s1+1);
		int len2=strlen(s2+1);
		if(i!=451)continue;
		if(len!=len2){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				mn=min(mn,i);
				mx=max(mx,i);
			}
		}
		int ans=0;
//		cerr<<"???"<<' '<<len<<endl;
		for(int l=1;l<=mn;l++){
			phh hs;
			for(int r=l;r<=len;r++){
//				cerr<<l<<' '<<r<<endl;
				hs.fi=hs.fi+s1[r];
				hs.se=hs.se+s2[r];
				if(r>=mx)ans+=hmp[hs];
			}
		}
		cout<<ans<<'\n';
	}
}
int pw[2][L];
Hash qry(int t,int l,int r){
	Hash res;
	for(int i=0;i<2;i++){
		res.v[i]=(h[t][r].v[i]-h[t][l-1].v[i]*pw[i][r-l+1]%mod[i]+mod[i])%mod[i];
	}
	return res;
}
void solve(){
	for(int i=1;i<=q;i++){
		cin>>(s1+1)>>(s2+1);
		int len=strlen(s1+1);
		int len2=strlen(s2+1);
		if(len!=len2){
			cout<<0<<'\n';continue;
		}
		for(int i=1;i<=len;i++){
			h[0][i]=h[0][i-1]+s1[i];
			h[1][i]=h[1][i-1]+s2[i];
		}
		int mn=INF,mx=0;
		for(int i=1;i<=len;i++){
			if(s1[i]!=s2[i]){
				mn=min(mn,i);
				mx=max(mx,i);
			}
		}
		int ans=0;
		for(int l=1;l<=mn;l++){
			int itl=lower_bound(lens.begin(),lens.end(),mx-l+1)-lens.begin();
			int itr=upper_bound(lens.begin(),lens.end(),len-l+1)-lens.begin();
			for(int x=itl;x<itr;x++){
				int t=lens[x];
				int r=l+t-1;
				if(r>=mx&&r<=len){
					ans+=hmp[mp(qry(0,l,r),qry(1,l,r))];
				}
			}
		}
		cout<<ans<<'\n';
	}
}
map<pii,vector<int> >qmp;
void solveB(){
	for(int i=1;i<=q;i++){
		cin>>(s1+1)>>(s2+1);
		int d1=0,d2=0;
		int len=strlen(s1+1);
		int len2=strlen(s2+1);
		if(len!=len2){
			cout<<0<<'\n';
			continue;
		}
		for(int j=1;j<=len;j++){
			if(s1[j]=='b')d1=j;
			if(s2[j]=='b')d2=j;
		}
		int ans=0;
		for(int l=1;l<=min(d1,d2);l++){
			vector<int> &ve=qmp[mp(d1-l+1,d2-l+1)];
			ans+=upper_bound(ve.begin(),ve.end(),len-l+1)-ve.begin();
		}
		cout<<ans<<'\n';
	}
	
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<2;i++){
		pw[i][0]=1;
		for(int j=1;j<L;j++)pw[i][j]=pw[i][j-1]*bs[i]%mod[i];
	}
	cin>>n>>q;
	int sumlen=0,mxb=0;
	for(int i=1;i<=n;i++){
		int cntb=0;
		cin>>(s1+1)>>(s2+1);
		int len=strlen(s1+1);
		sumlen+=len;
		phh hs;
		int d1=0,d2=0;
		for(int j=1;j<=len;j++){
			hs.fi=hs.fi+s1[j];
			hs.se=hs.se+s2[j];
			if(s1[j]=='b')cntb++,d1=j;
			if(s2[j]=='b')cntb++,d2=j;
		}
		mxb=max(mxb,cntb);
		hmp[hs]++;
		lens.pb(len);
		qmp[mp(d1,d2)].pb(len);
	}
	sort(lens.begin(),lens.end());
	lens.erase(unique(lens.begin(),lens.end()),lens.end());
	if(mxb==2){
		solveB();
	}else solve();
	return 0;
}
/*
1 1
aab
baa
aab
baa
*/

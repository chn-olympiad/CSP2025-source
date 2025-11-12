#include<bits/stdc++.h>
#define fileio(nam) \
	freopen(nam".in","r",stdin); \
	freopen(nam".out","w",stdout)
#define ct(x) \
	ios::sync_with_stdio(x); \
	cin.tie(x),cout.tie(x)

using namespace std;
using ll =  long long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define fi first
#define se second

//#define int ull
const int N = 200200 ;
const int L = 5005005;
const int base = 20100911 ;
struct point {
	ull al,a,b;
	int l1,l2;
}e[N];
int n,q;
char s[L],t[L];

void readii(int id) {
	cin>>s+1>>t+1;
	int lenn=strlen(s+1);
	pii fl={1,lenn};
	while(s[fl.fi]==t[fl.fi]) fl.fi++;
	while(s[fl.se]==t[fl.se]) fl.se--;
	e[id].l1=fl.fi-1;
	e[id].l2=lenn-fl.se;
	
	ull hsh1=0;
	for(int i=1;i<=lenn;i++)  hsh1=base*hsh1+s[i];
	ull hsh2=0;
	for(int i=fl.fi;i<=fl.se;i++)  hsh2=base*hsh2+s[i];
	ull hsh3=0;
	for(int i=fl.fi;i<=fl.se;i++)  hsh3=base*hsh3+t[i];
	e[id].al=hsh1;
	e[id].a=hsh2;
	e[id].b=hsh3;
	
//	cout<<e[id].l1<<" "<<e[id].l2<<'\n';
	return;
}


map<pair<ull,ull>,int> Lsh;int cntlsh=0;
struct Noode{
	ull al;
	int l,r;
	void fz(point x) {
		al=x.al;
		l=x.l1;
		r=x.l2;
	}
};
vector<Noode> Readd[N];
ull pas[5005005];
ull myhash[5005005];
ull gethash(int l,int r) {
	return myhash[r]-myhash[l-1]*pas[r-l+1];
}
void MyWork() {
	cin>>s+1>>t+1;
	int lenn=strlen(s+1);
	pii fl=make_pair(1,lenn);
	while(s[fl.fi]==t[fl.fi]) fl.fi++;
	while(s[fl.se]==t[fl.se]) fl.se--;
	
	ull hsh2=0;
	for(int i=fl.fi;i<=fl.se;i++) 
		hsh2=base*hsh2+s[i];
	ull hsh3=0;
	for(int i=fl.fi;i<=fl.se;i++) 
		hsh3=base*hsh3+t[i];
	myhash[0]=0;
	for(int i=1;i<=lenn;i++){
		myhash[i]=myhash[i-1]*base+s[i];
	}
	
	int t=Lsh[make_pair(hsh2,hsh3)];
	if(t==0) {
		cout<<0<<'\n';
		return;
	}
	int ans=0;
	for(Noode v:Readd[t]) {
		if(v.l>fl.fi-1) continue;
		if(v.r>lenn-fl.se) continue;
		
	//	cout<<fl.se+1<<" "<<fl.se+v.r<<'\n';
		if(gethash(fl.fi-v.l,fl.se+v.r)==v.al) {
			//	cout<<v.l<<" "<<v.r<<'\n';
				ans++;
			}
	}
	cout<<ans<<'\n';
}
// PROBELM:  replace   
signed main() {
	
	fileio("replace");
	ct(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		readii(i);
	}
	pas[0]=1;
	for(int i=1;i<=5000000;i++) pas[i]=pas[i-1]*base;
	for(int i=1;i<=n;i++) {
		if(Lsh[make_pair(e[i].a,e[i].b)]==0) {
			cntlsh++;
			Lsh[make_pair(e[i].a,e[i].b)]=cntlsh;
		}
		Noode x;
		x.fz(e[i]);
		Readd[Lsh[make_pair(e[i].a,e[i].b)]].push_back(x);
	}
	for(int i=1;i<=q;i++) {
		MyWork();
	}
	return 0;
}

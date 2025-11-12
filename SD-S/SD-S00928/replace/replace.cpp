#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 5000006
#define mod
#define ull unsigned long long
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<"\n"
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"\n";
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

bool M1;
int n,q;
struct node{
	string a,b;
	int len;
	ull vala,valb;
}s[MAXN],t[MAXN];
int ans[MAXN];
const ull bs=107;
const int N=5000000;

bool checkb(string s,int len){
	int cnt=0;
	for(int i=1;i<=len;i++){
		if(s[i]!='a' && s[i]!='b') return false;
		cnt+=(s[i]=='b');
	}
	return cnt==1;
}

ull pw[MAXM];
ull prea[MAXM],sufa[MAXM],preb[MAXM],sufb[MAXM];
	
bool cmp1(node aa,node bb){
	return aa.len<bb.len;
}

void init(string a,string b,int len){
	prea[0]=preb[0]=0;
	for(int i=1;i<=len;i++){
		prea[i]=prea[i-1]*bs+(a[i]-'a');
	}
	for(int i=1;i<=len;i++){
		preb[i]=preb[i-1]*bs+(b[i]-'a');
	}
	sufa[len+1]=sufb[len+1]=0;
	for(int i=len;i>=1;i--){
		sufa[i]=sufa[i+1]*bs+(a[i]-'a');
	}
	for(int i=len;i>=1;i--){
		sufb[i]=sufb[i+1]*bs+(b[i]-'a');
	}
}
ull aska(int l,int r){
	return prea[r]-prea[l-1]*pw[r-l+1];
}
ull askb(int l,int r){
	return preb[r]-preb[l-1]*pw[r-l+1];
}
void solve1(){
	pw[0]=1;
	for(int i=1;i<=N;i++) pw[i]=pw[i-1]*bs;
	sort(s+1,s+1+n,cmp1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].len;j++){
			s[i].vala=s[i].vala*bs+(s[i].a[j]-'a');
		}
		for(int j=1;j<=s[i].len;j++){
			s[i].valb=s[i].valb*bs+(s[i].b[j]-'a');
		}
//		cout<<s[i].a<<" "<<s[i].b<<"\n";
//		printf("vala=%llu valb=%llu\n",s[i].vala,s[i].valb);
	}
	for(int i=1;i<=q;i++){
		if(ans[i]==-1) continue;
		init(t[i].a,t[i].b,t[i].len);
		int len=t[i].len;
		for(int j=1;j<=len;j++){
			if(prea[i]!=preb[i]) continue;
			for(int k=1;k<=n;k++){
				int le=s[k].len;
				if(j+le-1>len) break;
				if(sufa[j+le]!=sufb[j+le]) continue;
				ull va=aska(j,j+le-1),vb=askb(j,j+le-1);
				if(va==s[k].vala && vb==s[k].valb) ans[i]++;
			}
		}
	}
	for(int i=1;i<=q;i++){
//		cout<<t[i].a<<"\n"<<t[i].b<<"\n";
//		printf("i=%d sza=%d szb=%d\n",i,t[i].a.size(),t[i].b.size());
		if(ans[i]==-1) puts("0");
		else printf("%d\n",ans[i]);
	}
}

bool M2;

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int Time=clock();
	n=read();q=read();
	bool flb=1;
	for(int i=1;i<=n;i++){
		cin>>s[i].a;
		s[i].len=s[i].a.size();
		s[i].a=" "+s[i].a;
		flb&=checkb(s[i].a,s[i].len);
		cin>>s[i].b;
		s[i].b=" "+s[i].b;
		flb&=checkb(s[i].b,s[i].len);
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].a;
		t[i].len=t[i].a.size();
		t[i].a=" "+t[i].a;
		flb&=checkb(t[i].a,t[i].len);
		cin>>t[i].b;
		t[i].b=" "+t[i].b;
		if(t[i].a.size()!=t[i].b.size()){
			ans[i]=-1;
			continue;
		}
		flb&=checkb(t[i].b,t[i].len);
	}
	solve1();
//	if(flb){
//		
//	}else{
//		S1.solve();
//	}
	look_memory;
	look_time;
	return 0;
}

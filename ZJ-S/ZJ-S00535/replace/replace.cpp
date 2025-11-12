#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define sz(x) ((int)(x.size()))
#define lowbit(x) ((x)&(-(x)))
const ll B=233333,mod=1e17+3;
const int N=2.5e6+10,Q=2e5+10;
vector<int>pos[N];
vector<pii>qq[N];
int l[N],r[N],p1[N][26],p2[N][26],c1=1,c2=1,cd,t[N],ans[Q],id[Q],id1[Q];
bool flag[Q],fl[Q];
string s1[Q],s2[Q],S1[Q],S2[Q];
ll ha[Q],HA[Q];
void upd1(string s){
	int n=(int)s.size(),now=1;
	for(int i=0;i<n;i++){
		if(!p1[now][s[i]-'a']) p1[now][s[i]-'a']=++c1;
		now=p1[now][s[i]-'a'];
	}
}
void upd2(string s){
	int n=(int)s.size(),now=1;
	for(int i=0;i<n;i++){
		if(!p2[now][s[i]-'a']) p2[now][s[i]-'a']=++c2;
		now=p2[now][s[i]-'a'];
	}
}
int ask1(string s){
	int n=(int)s.size(),now=1;
	for(int i=0;i<n;i++) now=p1[now][s[i]-'a'];
	return now;
}
int ask2(string s){
	int n=(int)s.size(),now=1;
	for(int i=0;i<n;i++) now=p2[now][s[i]-'a'];
	return now;
}
void dfs2(int u){
	l[u]=++cd;
	for(int i=0;i<26;i++) if(p2[u][i]) dfs2(p2[u][i]);
	r[u]=cd;
}
void upd(int i,int x){
	for(;i<=cd;i+=lowbit(i)) t[i]+=x;
}
int ask(int i){
	int ans=0;
	for(;i;i-=lowbit(i)) ans+=t[i];
	return ans;
}
void dfs1(int u){
	for(int v:pos[u]) upd(l[v],1),upd(r[v]+1,-1);
	for(pii _:qq[u]) ans[_.ss]=ask(l[_.ff]);
	for(int i=0;i<26;i++) if(p1[u][i]) dfs1(p1[u][i]);
	for(int v:pos[u]) upd(l[v],-1),upd(r[v]+1,1);
}
bool gz(int x,int y){
	return ha[x]<ha[y];
}
bool gz1(int x,int y){
	return HA[x]<HA[y];
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		string ss1,ss2;cin>>ss1>>ss2;
		if(ss1==ss2) fl[i]=1;
		else{
			int L,R;
			for(int j=0;j<sz(ss1);j++){
				if(ss1[j]!=ss2[j]){
					L=j;
					break;
				}
			}
			for(int j=sz(ss1);j>=0;j--){
				if(ss1[j]!=ss2[j]){
					R=j;
					break;
				}
			}
			for(int j=L-1;j>=0;j--) s1[i]+=ss1[j];
			for(int j=R+1;j<sz(ss1);j++) s2[i]+=ss2[j];
			for(int j=L;j<=R;j++) ha[i]=(ha[i]*B+ss1[j]-'a'+1)%mod;
			for(int j=L;j<=R;j++) ha[i]=(ha[i]*B+ss2[j]-'a'+1)%mod;
		}
		id[i]=i;
	}
	sort(id+1,id+1+n,gz);
	for(int i=1;i<=q;i++){
		string ss1,ss2;cin>>ss1>>ss2;
		if(sz(ss1)!=sz(ss2)){
			flag[i]=1;
			continue;
		}
		int L,R;
		for(int j=0;j<sz(ss1);j++){
			if(ss1[j]!=ss2[j]){
				L=j;
				break;
			}
		}
		for(int j=sz(ss1);j>=0;j--){
			if(ss1[j]!=ss2[j]){
				R=j;
				break;
			}
		}
		for(int j=L-1;j>=0;j--) S1[i]+=ss1[j];
		for(int j=R+1;j<sz(ss1);j++) S2[i]+=ss2[j];
		for(int j=L;j<=R;j++) HA[i]=(HA[i]*B+ss1[j]-'a'+1)%mod;
		for(int j=L;j<=R;j++) HA[i]=(HA[i]*B+ss2[j]-'a'+1)%mod;
		id1[i]=i;
	}
	sort(id1+1,id1+1+q,gz1);
	int pl=0,pr=0;
	while(1){
		pr++;
		if(pr>q) break;
		int nxtr=pr;
		while(nxtr<q&&HA[id1[nxtr+1]]==HA[id1[pr]]) nxtr++;
		ll w=HA[id1[pr]];
		while(pl<n&&ha[id[pl+1]]<w) pl++;
		int L=pl+1;
		while(pl<n&&ha[id[pl+1]]==w) pl++;
		for(int i=pr;i<=nxtr;i++) upd1(S1[id1[i]]),upd2(S2[id1[i]]);
		for(int i=L;i<=pl;i++){
			if(fl[id[i]]) continue;
			int x=ask1(s1[id[i]]),y=ask2(s2[id[i]]);
			if(x&&y) pos[x].push_back(y);
		}
		for(int i=pr;i<=nxtr;i++){
			if(flag[id1[i]]) continue;
			int x=ask1(S1[id1[i]]),y=ask2(S2[id1[i]]);
			qq[x].push_back({y,id1[i]});
		}
		dfs2(1),dfs1(1);
		for(int i=1;i<=c1;i++) pos[i].clear(),qq[i].clear();
		for(int i=1;i<=c1;i++) for(int j=0;j<26;j++) p1[i][j]=0;
		for(int i=1;i<=c2;i++) for(int j=0;j<26;j++) p2[i][j]=0;
		c1=c2=1,cd=0,pr=nxtr;
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}

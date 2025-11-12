#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD[2]={1000000007,1000000033};
int n,m,q;
string s[2][200010],tt[2][200010];
string tA[200010],tB[200010];
string sA[200010],sB[200010];
int ans[200010];
struct hsh{
	int a,b,c,d;
	bool operator<(const hsh &x)const{
		if(a!=x.a) return a<x.a;
		if(b!=x.b) return b<x.b;
		if(c!=x.c) return c<x.c;
		return d<x.d;
	}
}sh[200010],th[200010];
int sp[200010],tp[200010];
int spos[400010],tpos[400010];
vector<hsh> v;
ll hs[4];
struct trie{
	int sn[26];
	int l,sz;
}t[10080010];
int ttp,rt[800010];
void insert(int r,int id,string s){
	int p=rt[r],len=s.length();
	for(int i=0;i<len;i++){
		if(!t[p].sn[s[i]-'a']) t[p].sn[s[i]-'a']=++ttp;
		p=t[p].sn[s[i]-'a'];
	}
	t[p].sz++;
	tpos[id]=p;
}
int dft=0;
void dfs(int x){
	if(!x) return;
	t[x].l=dft+1;
	dft+=t[x].sz;
	for(int i=0;i<26;i++){
		dfs(t[x].sn[i]);
		t[x].sz+=t[t[x].sn[i]].sz;
	}
}
void chk(int r,int id,string s){
	int p=rt[r],len=s.length();
	for(int i=0;i<len;i++){
		if(!t[p].sn[s[i]-'a']) return;
		p=t[p].sn[s[i]-'a'];
	}
	spos[id]=p;
}
int bt[10080010];
int lowbit(int x){return x&-x;}
void add(int x,int k){
	for(;x<=dft;x+=lowbit(x)) bt[x]+=k;
}
int query(int x){
	int res=0;
	for(;x;x-=lowbit(x)) res+=bt[x];
	return res;
}
vector<int> e[10000010];
bool bflg[400010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[0][i];
		cin>>s[1][i];
		int l=-1,r=0;
		int len=s[0][i].length();
		for(int j=0;j<len;j++)
			if(s[0][i][j]!=s[1][i][j]){l=j;break;}
		for(int j=len-1;j>=0;j--)
			if(s[0][i][j]!=s[1][i][j]){r=j;break;}
		if(l==-1){
			bflg[i]=1;
			continue;
		}
		hs[0]=hs[1]=hs[2]=hs[3]=0;
		for(int j=l;j<=r;j++){
			for(int d=0;d<=1;d++){
				hs[d]=hs[d]*27+s[0][i][j]-'a'+1;
				hs[d]%=MOD[d];
				hs[d+2]=hs[d+2]*27+s[1][i][j]-'a'+1;
				hs[d+2]%=MOD[d];
			}
		}
		hsh tmp={hs[0],hs[1],hs[2],hs[3]};
		v.push_back(tmp),sh[i]=tmp;
		sA[i]="";
		for(int j=l-1;j>=0;j--) sA[i]+=s[0][i][j];
		sB[i]="";
		for(int j=r+1;j<len;j++) sB[i]+=s[0][i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>tt[0][i];
		cin>>tt[1][i];
		int l=0,r=0;
		int len=tt[0][i].length();
		if(len!=(int)tt[1][i].length()){
			bflg[i+n]=1;
			continue;
		}
		for(int j=0;j<len;j++)
			if(tt[0][i][j]!=tt[1][i][j]){l=j;break;}
		for(int j=len-1;j>=0;j--)
			if(tt[0][i][j]!=tt[1][i][j]){r=j;break;}
		hs[0]=hs[1]=hs[2]=hs[3]=0;
		for(int j=l;j<=r;j++){
			for(int d=0;d<=1;d++){
				hs[d]=hs[d]*27+tt[0][i][j]-'a'+1;
				hs[d]%=MOD[d];
				hs[d+2]=hs[d+2]*27+tt[1][i][j]-'a'+1;
				hs[d+2]%=MOD[d];
			}
		}
		hsh tmp={hs[0],hs[1],hs[2],hs[3]};
		v.push_back(tmp),th[i]=tmp;
		tA[i]="";
		for(int j=l-1;j>=0;j--) tA[i]+=tt[0][i][j];
		tB[i]="";
		for(int j=r+1;j<len;j++) tB[i]+=tt[0][i][j];
	}
	sort(v.begin(),v.end());
	m=v.size();
	for(int i=0;i<2*m;i++) rt[i]=i+1;
	ttp=2*m;
	for(int i=1;i<=q;i++){
		if(bflg[i+n]) continue;
		tp[i]=lower_bound(v.begin(),v.end(),th[i])-v.begin();
		insert(tp[i],i,tA[i]);
		insert(tp[i]+m,i+q,tB[i]);
	}
	for(int i=1;i<=n;i++){
		if(bflg[i]) continue;
		sp[i]=lower_bound(v.begin(),v.end(),sh[i])-v.begin();
		chk(sp[i],i,sA[i]);
		chk(sp[i]+m,i+n,sB[i]);
	}
	for(int i=0;i<2*m;i++) dfs(rt[i]);
	for(int i=1;i<=n;i++){
		if(!spos[i]||!spos[i+n]) continue;
		int l=t[spos[i]].l,r=t[spos[i]].l+t[spos[i]].sz-1;
		e[l].push_back(i);
		e[r+1].push_back(-i);
	}
	for(int i=1;i<=q;i++){
		if(bflg[i+n]) continue;
		int x=t[tpos[i]].l,y=t[tpos[i+q]].l;
		e[x].push_back(n+i);
	}
	for(int i=1;i<=dft;i++){
		for(int u:e[i]){
			if(u<=n){
				if(u<0){
					u=-u;
					int l=t[spos[u+n]].l,r=t[spos[u+n]].l+t[spos[u+n]].sz-1;
					add(l,-1),add(r+1,1);
				}else{
					int l=t[spos[u+n]].l,r=t[spos[u+n]].l+t[spos[u+n]].sz-1;
					add(l,1),add(r+1,-1);
				}
			}else{
				ans[u-n]=query(t[tpos[u-n+q]].l);
			}
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
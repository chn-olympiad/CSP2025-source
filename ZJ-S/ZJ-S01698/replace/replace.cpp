#include <bits/stdc++.h>
using namespace std;

bool hanshu;

const int B=1<<20;
char buf[B],*p1=buf,*p2=buf;
#define gc (p1==p2 && (p2=(p1=buf)+fread(buf,1,B,stdin)), *p1++)

void read(int &x) {
	char ch=gc; x=0;
	while(!isdigit(ch)) ch=gc;
	while(isdigit(ch)) x=(x<<1)+(x<<3)+ch-48,ch=gc;
}
char o[6000005];
void read(string &x) {
	char ch=gc; while(ch<'a'||ch>'z') ch=gc;
	int cc=0;
	while(ch<='z'&&ch>='a') o[cc++]=ch,ch=gc;
	x=o; memset(o,0,cc);
}
typedef long long LL;
const LL mod=(LL)(1e12)+39ll,bs=1331;
const int N=200005;

int n,q;
struct xxx{
	LL u,v;//两个哈希值 
	string x;
}a[N];
map<pair<LL,LL>,vector<int> >mp;
map<pair<LL,LL>,int>rt;
LL hs(string s) { 
	LL res=0;
	for(int i=0;i<s.size();i++)
		res=(res*1331+s[i]-'a')%mod;
	return res;
}

int nx[6000005][27],cnt,fail[6000005];
int sum[6000005];
void insert(int &r,string s) {
	if(!r) r=++cnt;
	int p=r;
	for(char i:s) {
		int t=i-'a';
		if(!nx[p][t]) nx[p][t]=++cnt,p=cnt;
		else p=nx[p][t];
	}
	sum[p]++;
//	printf("insert ");cout<<s<<'\n';
//	printf(">>> at %d\n",p);
}
int qu[6000005],hd,tl;
void AC(int rt) {
	hd=1,tl=0;
	fail[rt]=rt;
	for(int i=0;i<27;i++) {
		if(!nx[rt][i]) nx[rt][i]=rt;
		else fail[nx[rt][i]]=rt,qu[++tl]=nx[rt][i];
	}
	while(hd<=tl) {
		int x=qu[hd++];
		for(int i=0;i<27;i++) {
			if(nx[x][i]) {
				qu[++tl]=nx[x][i];
				fail[nx[x][i]]=nx[fail[x]][i];
			}
			else nx[x][i]=nx[fail[x]][i];
		}
	}
	for(int i=1;i<=tl;i++) {
		sum[qu[i]]+=sum[fail[qu[i]]];
//		printf("---------- fail[%d]=%d, sum[%d]=%d\n",qu[i],fail[qu[i]],
//			qu[i],sum[qu[i]]);
	}
}

bool iloveyou;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++) {
		string x,y; read(x),read(y);
		if(x==y) { n--,i--; continue; }
		int j=0;
		while(x[j]==y[j]) j++;
		int k=x.size()-1;
		while(x[k]==y[k]) k--;
		a[i]=xxx{hs(x.substr(j,k-j+1)),hs(y.substr(j,k-j+1)),
			x.substr(0,j)+"{"+x.substr(k+1)};
		mp[{a[i].u,a[i].v}].push_back(i);
//		printf("a[%d]: ",i);
//		printf("%lld %lld, ",a[i].u,a[i].v);
//		cout<<a[i].x<<endl;
	}
	for(auto i:mp) {
		vector<int>&v=i.second;
//		printf(">>> ");
		for(int j:v) {
			insert(rt[{a[j].u,a[j].v}],a[j].x);
//			printf("%d ",j); 
		}
//		printf("\n");
		AC(rt[{i.first.first,i.first.second}]);
	}
	for(int _=1;_<=q;_++) {
		string x,y; read(x),read(y);
		if(x.size()!=y.size()) {
			printf("0\n");
			continue;
		}
		int j=0;
		while(x[j]==y[j]) j++;
		int k=x.size()-1;
		while(x[k]==y[k]) k--;
		xxx que={hs(x.substr(j,k-j+1)),hs(y.substr(j,k-j+1)),
			x.substr(0,j)+'{'+x.substr(k+1)};
		pair<LL,LL>tmp = {que.u,que.v};
		if(!rt.count(tmp)) {
			printf("0\n");
			continue;
		}
		int now = rt[tmp],ans=0;
		for(char i:que.x) {
			int ch = i-'a';
			ans+=sum[now=nx[now][ch]];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
对每个东西建立AC自动机 
*/

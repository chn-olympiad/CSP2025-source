#include<bits/stdc++.h>
#include<map>
using namespace std;

const int N=1e5+10,M=1e6+10;
const int INF=0x3f3f3f3f;

int n,m;

int vis[N];

int num[N][4];

struct node {
	int v,opt,id;
	bool operator<(node oth) {
		if(v!=oth.v)return v>oth.v;
		return id<oth.id;
	}
} nod[N*3];

int top;
int Anum[N];

void A() {
	for(int i=1; i<=n; ++i) {
		Anum[i]=num[i][1];
	}
	sort(Anum+1,Anum+1+n);
	int ans=0;
	for(int i=n/2+1; i<=n; ++i) {
//		printf("a:%d\n",Anum[i]);
		ans+=Anum[i];
	}
	printf("%d\n",ans);
}

int cnt[5];
void go1() {
	sort(nod+1,nod+1+top);
	cnt[1]=cnt[2]=cnt[3]=n/2;
	memset(vis,0,sizeof(vis));
	int ans=0;
	for(int i=1; i<=top; ++i) {

		int v=nod[i].v,opt=nod[i].opt,id=nod[i].id;

		if(vis[id])continue;
		if(cnt[opt]==0)continue;
		ans+=v,vis[id]=1,--cnt[opt];
	}
	printf("%d\n",ans);
}



int Aflag=1,Bflag=1;


typedef  vector<int> ac;
map<ac,int> mp;

int dfs(int ls) {
	if(ls==0)return 0;
	ac a=ac {ls,cnt[1],cnt[2],cnt[3]};
	if(mp[a])return mp[a];
	int ans=0;
	if(cnt[1])--cnt[1],ans=max(dfs(ls-1)+num[ls][1],ans),++cnt[1];
	if(cnt[2])--cnt[2],ans=max(dfs(ls-1)+num[ls][2],ans),++cnt[2];
	if(cnt[3])--cnt[3],ans=max(dfs(ls-1)+num[ls][3],ans),++cnt[3];
	return mp[a]=ans;
}

void go() {
	mp.clear();
	cnt[1]=cnt[2]=cnt[3]=n/2;
	printf("%d\n",dfs(n));
}

void work() {
	scanf("%d",&n);
	top=0;
	Aflag=Bflag=1;
	for(int i=1,a,b,c; i<=n; ++i) {
		scanf("%d%d%d",&a,&b,&c);
		num[i][1]=a,num[i][2]=b,num[i][3]=c;

		if(b!=0)Aflag=0;
		if(c!=0) {
			Bflag=Aflag=0;
		}
	}
	if(Aflag)A();
	else go();
}
int T;
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		work();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define qwq return
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e5+5;
int T,n,m;
ll ans;
int d[N][3],cnt[3],ch[N];
struct Node{
	int s,x,y;
	bool operator< (const Node &A)const {
		if (s==A.s) {
			if (x==A.x) {qwq y<A.y;}
			qwq x<A.x;
		}
		qwq s>A.s;
	}
};
set<Node> st[3];
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while (!isdigit(c)) {f=(c=='-'?-1:1);c=getchar();}
	while (isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	qwq x*f;
}
void clear() {
	cnt[0]=cnt[1]=cnt[2]=0;
	ans=0;
	for (int i=0;i<3;i++) {st[i].clear();}
}
void _(int x,int y) {
	cnt[y]++;
	ans+=1ll*d[x][y];
	ch[x]=y;
	for (int i=0;i<3;i++) {
		if (y^i) {
			st[y].insert({d[x][i]-d[x][y],x,i});
		}
	}
}
int A1(int x) {
	if (x==0) {qwq 1;}
	qwq 0;
}
int A2(int x) {
	if (x==2) {qwq 1;}
	qwq 2;
}
void work(int i,int j,int a,int b) {
	//cout<<">>>>"<<i<<' '<<j<<' '<<cnt[j]<<" "<<m<<"\n";
	if (cnt[j]<m) {_(i,j);qwq ;}
	if (st[j].empty() || st[j].begin()->s+d[i][j]<0) {
		if (d[i][a]>d[i][b]) {_(i,a);}
		else {_(i,b);}
	}
	else {
		int s=st[j].begin()->s,x=st[j].begin()->x,y=st[j].begin()->y;
		//cout<<i<<" "<<j<<"-->"<<x<<' '<<y<<"\n";
		ans-=1ll*d[x][ch[x]];
		st[j].erase({s,x,y});
		st[j].erase({d[x][A1(ch[x])]-d[x][ch[x]],x,A2(ch[x])});
		cnt[j]--;
		_(x,y);
		_(i,j);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while (T--) {
		n=read();m=n>>1;
		clear();
		for (int i=1;i<=n;i++) {d[i][0]=read();d[i][1]=read();d[i][2]=read();}
		for (int i=1;i<=n;i++) {
			int mx=max({d[i][0],d[i][1],d[i][2]});
			if ((mx==d[i][0] && mx==d[i][1]) || (mx==d[i][0] && mx==d[i][2]) || (mx==d[i][1] && mx==d[i][2])) {
				if (cnt[0]<m) {_(i,0);}
				else if (cnt[1]<m) {_(i,1);}
				else {_(i,2);}
				continue;
			}
			if (mx==d[i][0]) {work(i,0,1,2);}
			else if (mx==d[i][1]) {work(i,1,0,2);}
			else {work(i,2,0,1);}
		}
		printf("%lld\n",ans);
	}
	qwq 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
[18 4 13]
*/

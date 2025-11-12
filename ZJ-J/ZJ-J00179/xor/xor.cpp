#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define repp(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define getc getchar
#define putc putchar
#define scan scanf
#define prin printf
using namespace std;
const int N=5e5,K=(1<<20);
int a[N+100],s[N+100];
vector<int>v[K];
struct Node {
	int l,r;
	bool operator < (const Node &a)const {
		return r<a.r;
	}
}b[N+100];
bool cmp(const Node &a,const Node &b) {
	return a.l<b.l;
}
int cnt=0;
void add(int l,int r) {
	b[++cnt]={l,r};
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scan("%d%d",&n,&k);
	rep(i,1,n) scan("%d",a+i),s[i]=s[i-1]^a[i],v[s[i]].push_back(i);
	rep(i,1,n) {
		int kk=k^s[i-1];
		if(v[kk].size()==0) continue;
		for(int j:v[kk])
			if(j>=i) {
				add(i,j);
				break;
			}	
	}
	if(cnt==0) {
		prin("0");
		return 0;
	}
//	rep(i,1,cnt) cerr<<b[i].l<<" "<<b[i].r<<endl;
	sort(b+1,b+1+cnt,cmp);
	int ed=b[1].r,ans=1;
	stack<Node>q;
	q.push(b[1]);
	rep(i,2,cnt) {
		if(ed<b[i].l) {
			q.push(b[i]);
			ed=b[i].r;
			++ans;
		}else {
			Node q0=q.top();
			if(b[i].r<q0.r) {
				q.pop();
				q.push(b[i]);
				ed=b[i].r;
			}
		}
	}
	prin("%d",ans);
	return 0;
}
/*
4 2
2 1 0 3
*/

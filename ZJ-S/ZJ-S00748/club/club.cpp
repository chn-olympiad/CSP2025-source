#include<bits/stdc++.h>
#define fileio(nam) \
	freopen(nam".in","r",stdin); \
	freopen(nam".out","w",stdout)
#define ct(x) \
	ios::sync_with_stdio(x); \
	cin.tie(x),cout.tie(x)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
#define fi first
#define se second

const int N = 1001001;
struct point {
	int x,y,z;
}e[N];
int n;
point a[N],b[N],c[N];
int cnta,cntb,cntc;
int qc[N],fl;
void MyWork() {
	cin>>n;
	cnta=cntb=cntc=0;
	for(int i=1;i<=n;i++) {
		cin>>e[i].x>>e[i].y>>e[i].z;
		if(e[i].x>=e[i].y&&e[i].x>=e[i].z ){
			cnta++;
			a[cnta]=e[i];
		} else if(e[i].y>=e[i].x&&e[i].y>=e[i].z) {
			cntb++;
			b[cntb]=e[i];
		} else {
			cntc++;
			c[cntc]=e[i];
		}
	}
	ll answer=0;
	for(int i=1;i<=cnta;i++) answer+=a[i].x;
	for(int i=1;i<=cntb;i++) answer+=b[i].y;
	for(int i=1;i<=cntc;i++) answer+=c[i].z;
	if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2) {
		// You've well done!
		cout<<answer<<'\n';
		return;
	}
	fl=0;
	if(cnta>n/2) {
		fl=cnta;
		for(int i=1;i<=cnta;i++)
			qc[i]=min(a[i].x-a[i].y,a[i].x-a[i].z );
	} else if(cntb>n/2) {
		fl=cntb;
		for(int i=1;i<=cntb;i++)
			qc[i]=min(b[i].y-b[i].x,b[i].y-b[i].z);
	} else {
		fl=cntc;
		for(int i=1;i<=cntc;i++)
			qc[i]=min(c[i].z-c[i].x,c[i].z-c[i].y);
	}
	sort(qc+1,qc+1+fl);
	for(int i=1;i<=fl-n/2;i++) {
		answer-=qc[i];
	}
	cout<<answer<<'\n';
	return;
}
// PREBLEM:    club  
int Tnumt;
int main() {
	fileio("club");
	ct(0);
	cin>>Tnumt;
	while(Tnumt--)
		MyWork();
	return 0;
}

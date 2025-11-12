#include<bits/stdc++.h>
using namespace std;
//É¾×¢ÊÍ!É¾¶àÓàÎÄ¼þ! 
const int N=100005;
int n,l;
int ans,cc[5];
struct mn {
	int club;
	int s;
} z[5];
struct man {
	int a[5];
	int c1;
	int c2;
	int s;//cha
	//int c;
} b[N];
//bool v[N];
bool cp(man x,man y) {
	return x.s>y.s;
}
bool cp2(mn x,mn y) {
	return x.s>y.s;
}
signed main() {
	//OK
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		l=n/2;
		ans=0;
		cc[1]=cc[2]=cc[3]=0;
		for(int i=1; i<=n; i++) {
			cin>>b[i].a[1]>>b[i].a[2]>>b[i].a[3];
			z[1].s=b[i].a[1],z[1].club=1;
			z[2].s=b[i].a[2],z[2].club=2;
			z[3].s=b[i].a[3],z[3].club=3;
			sort(z+1,z+4,cp2);
			b[i].s=z[1].s-z[2].s;
			//b[i].c=i;
//			if(z[3]==b[i].a[1])b[i].club=1;
//			else if(z[3]==b[i].a[2])b[i].club=2;
//			else if b[i].club=3;
//			if(z[2]==b[i].a[1])b[i].club=1;
//			else if(z[2]==b[i].a[2])b[i].club=2;
//			else b[i].club=3;
			b[i].c1=z[1].club;
			b[i].c2=z[2].club;
		}
		sort(b+1,b+n+1,cp);
		for(int i=1; i<=n; i++) {
			if(cc[b[i].c1]<l)
				ans+=b[i].a[b[i].c1],
				     cc[b[i].c1]++;
			else if(cc[b[i].c2]<l) {
				ans+=b[i].a[b[i].c2],
				     cc[b[i].c2]++;
			}
			//cout<<cc[1]<<' '<<cc[2]<<' '<<cc[3]<<'\n';
		}

		cout<<ans<<'\n';
	}

	return 0;
}


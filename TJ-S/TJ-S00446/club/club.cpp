#include<bits/stdc++.h>
using namespace std;
int t,n,cnta,cntb,cntc,cnt;
struct c {
	int a,b,c;
} a[300005];
bool cmp(c x,c y) {
	return x.a>y.a;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b==0)cntb++;
			if(a[i].c==0)cntc++;
		}
		if(cntb==cntc&&cntb==n) {
			sort(a+1,a+1+n,cmp);
			for(int i=1; i<=n/2; i++)cnt+=a[i].a;
			cout<<cnt<<"\n";
		}
	}
	return 0;
}

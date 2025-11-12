#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
struct node {
	int a1,a2,a3;
} p1[maxn];
bool cmp(node x,node y) {
	return x.a1>y.a1;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		bool f=1;
		bool f1=1;
		for(int i=1; i<=n; ++i) {
			cin>>p1[i].a1>>p1[i].a2>>p1[i].a3;
			if(p1[i].a2!=0 || p1[i].a3!=0) {
				f=0;
			}
		}
		if(f) {
			sort(p1+1,p1+n+1,cmp);
			int ans=0;
			for(int i=1; i<=n/2; ++i) {
				ans+=p1[i].a1;
			}
			cout<<ans<<endl;
			continue;
		}
		if(n==2) {
			int w[100];
			w[1]=p1[1].a1+p1[2].a2;
			w[2]=p1[1].a1+p1[2].a3;
			w[3]=p1[1].a2+p1[2].a1;
			w[4]=p1[1].a2+p1[2].a3;
			w[5]=p1[1].a3+p1[2].a1;
			w[6]=p1[1].a3+p1[2].a2;
			sort(w+1,w+6+1);
			cout<<w[6]<<endl;
			continue;
		}

		int anss=0;
		for(int i=1; i<=n; ++i) {
			int pos,cur=0;
			int u1=p1[i].a1;
			int u2=p1[i].a2;
			int u3=p1[i].a3;
			if(u1>=max(u2,u3)) {
				cur=u1,pos=1;
			} else if(u2>=max(u1,u3)) {
				cur=u2,pos=2;
			} else if(u3>=max(u1,u2)) {
				cur=u3,pos=3;
			}
			anss+=cur;
		}
		cout<<anss<<endl;
	}
	return 0;
}//燃尽了 应该应该没有noip了 whk加油吧 

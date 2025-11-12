#include<bits/stdc++.h>
using namespace std;
const int N=100001;
struct null {
	int o,w,r;
} a[N];
int w(null x) {
	if(x.o>x.r and x.o>x.w)return 1;
	if(x.r>x.o and x.r>x.w)return 3;
	if(x.w>x.r and x.w>x.o)return 2;
	return 0;
}
bool cmp(null x,null y) {
	if(x.o!=y.o)return x.o>y.o;
	if(x.w>y.w)return x.w>y.w;
	return x.r>y.r;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) {
		int n,bj[4]= {};
		long long sum=0;
		cin>>n;
		int mf=n/2;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i].o,&a[i].w,&a[i].r);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1; i<=n; i++) {
			int temp=w(a[i]);
			if(temp!=0) {
				if(bj[temp]<mf) {
					bj[temp]++;
					if(temp==1)sum+=a[i].o;
					else if(temp==2)sum+=a[i].w;
					else sum+=a[i].r;
				}
			} else if(temp==0) {
				if(bj[1]<mf)bj[1]++,sum+=a[i].o;
				else if(bj[2]<mf)bj[2]++,sum+=a[i].w;
				else if(bj[3]<mf)bj[3]++,sum+=a[i].r;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}

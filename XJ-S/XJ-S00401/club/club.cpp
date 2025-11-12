//T1 expect 25pts
#include<bits/stdc++.h>
#define int long long
const int N=1E5+10;
using namespace std;
int T;
struct node {
	int a,b,c;
} a[N];
int n,ans;
//贪心思路：显然需要把最适合的人放到
//sort3次找出每一个人最适合的位置
void dfs(int k,int a1,int b1,int c1,int tot) { //对应的 k
	int mid=n/2;
	if(a1>mid || b1>mid || c1>mid) {
		return ;
	}
	if(k==n+1) {
		ans=max(ans,tot);
		return ;
	}

	dfs(k+1,a1+1,b1,c1,tot+a[k].a);
	dfs(k+1,a1,b1+1,c1,tot+a[k].b);
	dfs(k+1,a1,b1,c1+1,tot+a[k].c);
}
void dfs1(int k,int a1,int b1,int tot) { //对应的 k
	int mid=n/2;
	if(a1>mid || b1>mid ) {
		return ;
	}
	if(k==n+1) {
		ans=max(ans,tot);
		return ;
	}
	dfs1(k+1,a1+1,b1,tot+a[k].a);
	dfs1(k+1,a1,b1+1,tot+a[k].b);
}
int flag1,flag2;
int cmp(node x,node y) {
	if(x.a==y.a) {
		return x.b>y.b;
	}
	return x.a>y.a;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) {
		ans=0,flag1=0,flag2=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].c!=0&&a[i].b!=0) {
				flag1=1;
			}
			if(a[i].c!=0) {
				flag2=1;
			}
		}
		if(n<=20) {
			dfs(1,0,0,0,0);
			cout<<ans<<endl;
		} else {
			if(flag1==0) {
				sort(a+1,a+n+1,cmp);
				for(int i=1; i<=n/2; i++) {
					ans+=a[i].a;
				}
				cout<<ans<<endl;
			} else if(flag2==0) {
				dfs1(1,0,0,0);
				cout<<ans<<endl;
			} else {
				dfs(1,0,0,0,0);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}

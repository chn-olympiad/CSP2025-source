#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int t,ans;
int n;
struct data {
	int a1,a2,a3;
} a[100001];
void dfs(int k,int s1,int s2,int s3,int maxx) {
//	cout<<k<<' '<<s1<<' '<<s2<<' '<<s3<<' '<<maxx<<' '<<js<<' '<<ans<<endl;
	if(k>n) {
		ans=max(ans,maxx);
		return;
	}
	if(s1+1<=n/2) {
		dfs(k+1,s1+1,s2,s3,maxx+a[k].a1);
	}
	if(s2+1<=n/2) {
		dfs(k+1,s1,s2+1,s3,maxx+a[k].a2);
	}
	if(s3+1<=n/2) {
		dfs(k+1,s1,s2,s3+1,maxx+a[k].a3);
	}
}
bool cmp(data x,data y) {
	if(x.a1==y.a1) {
		if(x.a2==y.a2) {
			return x.a3>y.a3;
		}
		return x.a2>y.a2;
	}
	return x.a1>y.a1;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		sort(a+1,a+n+1,cmp);
		if(n>=200) {
			int sum=0;
			for(int i=1; i<=n/2; i++) {
					sum+=a[i].a1;
			}
			cout<<sum<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
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

1
10
1 0 0
2 0 0
3 0 0
4 0 0
5 0 0
6 0 0
7 0 0
8 0 0
9 0 0
9 0 0

1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

*/

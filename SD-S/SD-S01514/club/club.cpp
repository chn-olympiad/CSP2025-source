#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6+500;
#define int long long
int T;
int n,result;
struct node {
	int f1,f2,f3;
	int cha;
	int ff1,ff2,ff3;
	node(int f1,int f2,int f3):f1(f1),f2(f2),f3(f3) {
		cha=f1-f2;
		ff1=f1-f2-f3;
		ff2=f2-f1-f3;
		ff3=f3-f2-f1;
	}
};
bool cmp1(node&x,node&y) {
	return x.cha<y.cha;
}
vector<node> f1;
void dfs(int now,int ans,int a1,int a2,int a3) {
	if(now==n) {
		result=max(result,ans);
		return;
	}
	if(a1<n/2) {
		dfs(now+1,ans+f1[now].f1,a1+1,a2,a3);
	}
	if(a2<n/2) {
		dfs(now+1,ans+f1[now].f2,a1,a2+1,a3);
	}
	if(a3<n/2) {
		dfs(now+1,ans+f1[now].f3,a1,a2,a3+1);
	}
}
bool cmp(node&x,node&y) {
	return x.f1>y.f1;
}
signed main () {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	while(T--) {
		result=0;
		cin>>n;
		int sum=0;
		bool flagA=true;
		bool flagB=true;
		f1.resize(0,node(0,0,0));
		for(int i=1; i<=n; i++) {
			int x,y,z;
			cin>>x>>y>>z;
			sum+=(x+y+z);

			if(y!=0||z!=0) {
				flagA=false;
			}
			if(z!=0) {
				flagB=false;
			}
			node temp=node(x,y,z);
			f1.push_back(temp);

		}
		if(flagA) {
			sort(f1.begin(),f1.end(),cmp);
			int result=0;
			for(int i=0; i<n/2; i++) {
				result+=f1[i].f1;
			}
			cout<<result<<"\n";
			continue;
		}
		if(flagB) {
			sort(f1.begin(),f1.end(),cmp1);
			for(int i=0; i<n; i++) {
				if(i+1<=n/2) {
					sum-=f1[i].f1;
				} else {
					sum-=f1[i].f2;
				}
			}
			cout<<sum<<"\n";
			continue;
		}
		dfs(0,0,0,0,0);
		cout<<result<<"\n";
	}
	return 0;
}
/*
1
4
 4 0 0
 3 0 0
 5 0 0
 3 0 0


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

*/



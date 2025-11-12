#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int mod=998244353;
const int N=5e2+5;
int n,m,ans;
int a[N],p[N],q[N];
int calc() {
	int pre=0,num=0;
	for(int i=1; i<=n; i++)
		if(q[i]<=pre||a[i]==0) pre++;
		else num++;
	return num;
}
void dfs(int x) {
	if(x==n+1) {
		int num=calc();
		if(num<m) return ;
		ans++;
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(q[i]==0) {
			q[i]=p[x];
			dfs(x+1);
			q[i]=0;
		}
	}
	return ;
}
void slove1() {
	dfs(1);
	cout<<ans<<endl;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	for(int i=1; i<=n; i++) cin>>p[i];
	slove1();
	return 0;
}
/*
3 2
101
1 1 2
*/

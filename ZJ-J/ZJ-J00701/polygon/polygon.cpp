#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5100];
bool flag,flag1;
void dfs(int lens,int uses,int maxn,int indexs,int x) {
	if(uses>=x) {
		if(lens>maxn*2) {
			ans++;
			ans%=998244353;
		}
		return;
	}
	if(indexs>n) return;
	dfs(lens,uses,maxn,indexs+1,x);
	dfs(lens+a[indexs],uses+1,max(maxn,a[indexs]),indexs+1,x);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3; i<=n; i++) {
		dfs(0,0,0,1,i);
	}
	cout<<ans;
}

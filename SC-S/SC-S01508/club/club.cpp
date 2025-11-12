#include<bits/stdc++.h>
using namespace std;
int t,n,answer,a[100005][4];
void dfs(int i,int mem1,int mem2,int mem3,int ans) {
	if(i>n) {
		if(ans>answer) {
			answer=ans;
		}
		return;
	}
	int x=n/2;
	if(mem1<x) {
		dfs(i+1,mem1+1,mem2,mem3,ans+a[i][1]);
	}
	if(mem2<x) {
		dfs(i+1,mem1,mem2+1,mem3,ans+a[i][2]);
	}
	if(mem3<x) {
		dfs(i+1,mem1,mem2,mem3+1,ans+a[i][3]);
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<answer<<endl;
		answer=0;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int t,n,ans,s;
struct node {
	int w1;
	int w2;
	int w3;
} a[200000];
void dfs(int c1,int c2,int c3,int p,int s) {
	if(c1>n/2||c2>n/2||c3>n/2) return;
	if(p==n+1) {
		ans=max(ans,s);
		return;
	}
	dfs(c1+1,c2,c3,p+1,s+a[p-1].w1);
	dfs(c1,c2+1,c3,p+1,s+a[p-1].w2);
	dfs(c1,c2,c3+1,p+1,s+a[p-1].w3);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n;
		if(n<=10) {
			ans=0;
			s=0;
			bool flag1=true,flag2=true;
			for(int i=0; i<n; i++) {
				cin>>a[i].w1>>a[i].w2>>a[i].w3;
			}
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}
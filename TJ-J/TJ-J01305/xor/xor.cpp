#include <bits/stdc++.h>
using namespace std;
int n,li[500002],kl=0,max1=0;
int dfs(int set,int cnt) {
	int k=0;
	for (int i=set+1;i<=n;i++) {
		k^=li[i];
		if (k==kl) {
			dfs(i,cnt+1);
		}
		else {
			max1=max(max1,cnt);
		}
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>kl;
	bool all1=0;
	for (int i=1;i<=n;i++) {
		cin>>li[i];
		if (li[i]!=1) all1=0;
	}
	for (int i=0;i<n;i++) {
		dfs(i,1);
	}
	cout<<max1<<endl;
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
int n,a[105],k,ans,l,r;
bool vis[105];
bool cmp(int front,int rear) {
	int p=0;
	for(int i=front; i<=rear; i++) {
		if(vis[i]==1) {
			return 0;
		}
		p^=a[i];
	}
	if(p==k) {
		for(int j=front; j<=rear; j++) {
			vis[j]=1;
		}
		return 1;
	}
	return 0;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(cmp(i,j)) {
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

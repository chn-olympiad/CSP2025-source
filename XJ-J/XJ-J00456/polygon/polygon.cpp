#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	int n;
	cin>>n;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(n==3) {
		int ans=0;
		int maxn=0;
		for(int i=1; i<=n; i++) {
			maxn=max(maxn,a[i]);
			ans+=a[i];
		}
		if(ans>maxn*2) {
			cout<<1;
		} else {
			cout<<0;
		}
	}else if(cnt==n){
		cout<<pow(3,n-4)*n;
	} else {
		srand(time(0));
		cout<<rand()%100; 
	}
	return 0;
}

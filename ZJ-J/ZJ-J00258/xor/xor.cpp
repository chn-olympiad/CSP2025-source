#include<bits/stdc++.h>
using namespace std;
struct o {
	int l;
	int r;
	bool q=false;
};
o dp[100005];
int n,k,a[100005],max1=0,sum=0;
int xr(int x,int y) {
	int s=x|y,t=x&y;
	return s-t;
}
void check() {
	int b=0;
	for(int i=1; i<=n; i++) {
		b=0;
		for(int j=i; j<=n; j++) {
			b=xr(b,a[j]);
			if(b==k) {
				dp[i].l=i;
				dp[i].r=j;
				dp[i].q=true;
				break;
			}
		}
	}
}
int main() {
	int ri=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	check();
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(dp[j].q==true&&j>ri){
				ri=dp[j].r;
				sum++;
			}else if(dp[j].q==true&&j<=ri){
				if(dp[j].r<ri){
					ri=dp[j].r;
				}
			}
		}
		max1=max(sum,max1);
		sum=0;
	}
	cout<<max1;
	return 0;
}

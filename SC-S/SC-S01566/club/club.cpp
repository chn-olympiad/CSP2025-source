#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const int maxn = 1e5+10;
int n;
int a[210][5];
int f[2][110][110];
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1;i<=n;i++) 
	    for(int j=1;j<=3;j++) cin>>a[i][j];
	f[0][0][0] = 0;
	for(int i=1;i<=n;i++) {
	    for(int j=0;j<=min(i,n/2);j++) {
		for(int k=0;k<=min(i-j,n/2);k++) {
		    int a3 = i-j-k;
		    f[i&1][j][k] = -1;
		    if(j > 0) f[i&1][j][k] = max(f[i&1][j][k],f[(i-1)&1][j-1][k] + a[i][1]);
		    if(k > 0) f[i&1][j][k] = max(f[i&1][j][k],f[(i-1)&1][j][k-1] + a[i][2]);
		    if(a3 > 0) f[i&1][j][k] = max(f[i&1][j][k],f[(i-1)&1][j][k] + a[i][3]);
		}
	    }
	}
	int ans = -1;
	for(int j=0;j<=n/2;j++) 
	    for(int k=0;k<=n/2;k++) 
		ans = max(ans,f[n&1][j][k]);
	cout<<ans<<endl;
    }
    return 0;
}
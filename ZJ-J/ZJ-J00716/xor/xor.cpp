#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n,m,a[N],sum[N],f[N][N];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	}
	for(int l=0;l<n;l++){
		for(int i=1;i<=n-l;i++){
			if((sum[i-1]^sum[i+l])==m) f[i][i+l]=max(f[i][i+l],1);
			for(int k=i;k<i+l;k++){
				f[i][i+l]=max(f[i][i+l],f[i][k]+f[k+1][i+l]);
			}
		}
	}
	cout<<f[1][n];
	return 0;
}
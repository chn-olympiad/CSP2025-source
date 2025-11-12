#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n, K;
int a[N], f[1005][1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> K;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		if(a[i]==K) f[i][i]=1;
	}
	for(int len=1; len<=n; len++){
		for(int l=1; l+len-1<=n; l++){
			int r=l+len-1;
			for(int k=l; k<r; k++){
			    f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]);
			}
			if(f[l][r]==0){
				int tot=0;
				for(int i=l; i<=r; i++){
					tot^=a[i];
				}
				if(tot==K) f[l][r]=1;
			}
		}
	}
	cout << f[1][n];
	return 0;
}

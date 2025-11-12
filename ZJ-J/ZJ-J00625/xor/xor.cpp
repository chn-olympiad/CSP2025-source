#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],vis[500005],sum1[25][500005];
bool check(int op) {
	if(op==1) for(int i=1; i<=n; i++) if(a[i]!=1) return false;
	if(op==2) for(int i=1; i<=n; i++) if(a[i]>1) return false;
	if(op==3) for(int i=1; i<=n; i++) if(a[i]>255) return false;
	return true;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(k==0 && check(1)) cout<<(n>>1);
	else if(k<=1 && check(2)) {
		int ans=0;
		if(k==0) {
			for(int i=1; i<=n; i++) {
				if(a[i]==0) ans++;
				if(a[i]==1)
					if(a[i-1]==1 && !vis[i-1]) {
						vis[i-1]=vis[i]=true;
						ans++;
					}
			}
		} else for(int i=1; i<=n; i++) if(a[i]==1) ans++;
		cout<<ans;
	} else if(k<=255 && check(3)) {
		for(int i=0; i<8; i++) {
			for(int j=1;j<=n;j++){
				vis[i]=false;
				sum1[i][j]=sum1[i][j-1]+((a[j]>>i)&1);
			} 
			if(((k>>i)&1)==0) {
				for(int j=1; j<=n; j++) {
					if(((a[j]>>i)&1)==0) ;//do sth
					else if(((a[j-1]>>i)&1)==1 && !vis[j-1]) {
						vis[j-1]=vis[j]=true;
						//do sth
					}
				}
			}else for(int j=1; j<=n; j++) if(((a[j]>>i)&1)==1) ;//do sth
		}
	}

	return 0;
}

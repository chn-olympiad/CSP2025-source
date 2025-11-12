#include<bits/stdc++.h>
using namespace std;
const int N=1e4+9;
const int M=5e6+9;
int n,k,a[M];
int main() {
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0) {
		int i,f=0;
		for(i=1;i<=n;i++) {
			if(a[i]!=1) continue;
		}
		if(i>n) {
			cout<<n/2;return 0;
		}
	}
	if(k<=1) {
		int l=0,r=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==1) l++;
			if(a[i]==0) r++;
		}
		if(l%2!=0||r%2!=0) {
			cout<<max(l,r);return 0;
		}
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=i;j<=n;j++) {
//			if(fl[i][j]!=0||fl[j][i]!=0) continue;
//			f[i][j]=a[i];
//			for(int k=i+1;k<=j;k++) f[i][j]^=a[k];
//			fl[i][j]=114;fl[j][i]=514;
//		}
//	}
//	ll cnt=0;
//	for(int i=1;i<=n;i++) {
//		for(int j=i;j<=n;j++) {
//			if(f[i][j]==k) {
//				l[++cnt]=i;r[cnt]=j;
//			}
//		}
//	}
//	for(int i=1;i<=cnt;i++) {
//		for(int j=i+1;j<=cnt;j++) {
//			if(l[i]!=l[j]&&r[i]!=r[j]&&l[i]<l[j]&&r[i]<l[j]||l[i]!=l[j]&&r[i]!=r[j]&&l[i]>r[j]&&r[i]>r[j]) {
//				flag[i][j]++;
//			}
//		}
//	}
//cha yi bu jiu neng na 60pts le,da zui di dang bao li qu le
	return 0;
}

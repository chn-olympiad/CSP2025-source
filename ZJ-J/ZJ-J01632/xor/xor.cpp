#include<bits/stdc++.h>
#define int long long
using namespace std;
int yh(int a,int b) {
	int k=0,x[30],y[30],s=1;
	while(a||b) {
		x[s]=(a&1);
		y[s]=(b&1);
		s++;
		a=a>>1;
		b=b>>1;
	}
	s--;
	for(int i=s; i>=1; i--) {
		k=k<<1;
		if(x[i]!=y[i])k++;
	}
	return k;
}
int n,a[500100],k,ans,s[500100],l=1,maxx=-1;
int f[500100][300];
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cout<<yh(0,2)<<"\n\n";//0
	cin>>n>>k;
	s[0]=0;
	for(int i=1; i<=n; i++)cin>>a[i],s[i]=yh(s[i-1],a[i]),maxx=max(a[i],maxx);
//	for(int i=1;i<=n;i++)cout<<s[i]<<" ";//1;
//	cout<<"\n";//1
//	if(n<=1000) {
//		for(int i=1; i<=n; i++) {
//			for(int j=l; j<=i; j++) {
//				if(yh(s[i],s[j-1])==k) {
//					ans++;
//					l=i+1;
//					break;
//				}
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
//	if(maxx<=255) {
//		ans=-1;
//		for(int i=1;i<=n;i++){
//			f[i][a[i]]=f[i-1][256];
//			for(int j=0;j<=255;j++){
//				f[i][j]=f[i-1][yh(j,a[i])];
//				if(j==k)f[i][j]++,f[i][256]=max(f[i][j],f[i][256]),ans=max(ans,f[i][j]);
//				f[i][256]=max(f[i-1][j],f[i][256]);
//			}
//		}
//		cout<<ans;
//		return 0;
//	}
	for(int i=1; i<=n; i++) {
		for(int j=l; j<=i; j++) {
			if(yh(s[i],s[j-1])==k) {
				ans++;
				l=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//operator
//priority_queue<int> q;

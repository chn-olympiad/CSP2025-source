#include<bits/stdc++.h>
using namespace std;
const int N=20,mod=998244353;
int sum[N],c[N],a[N];
//int f[N][(1<<18)+10][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=n;i++) cin>>c[i];
	do{
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1];
			if(s[i]=='0') sum[i]++;
		}
		int k=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'&&sum[i-1]<c[a[i]]&&k<c[a[i]]) ++cnt;
			else k++;
//			cout<<sum[i]<<" ";
		}
//		cout<<"\n";
		if(cnt>=m) ++ans;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans%mod;
	return 0;
}
//f[0][0][0]=1;
//	for(int i=1;i<=n;i++){
//		for(int nm=1;nm<=n;nm++){
//			for(int j=0;j<(1<<n);j++){
//				if(((1<<(nm-1)&j)==0)) continue;
//				for(int k=0;k<=i;k++){
//					if(k<c[i]&&sum[i-1]<c[i]){
//						if(c[i]=='0'&&k>0)  f[i][j][k]=(f[i-1][j-(1<<(nm-1))][k-1]+f[i][j][k])%mod;
//						else f[i][j][k]=(f[i-1][j-(1<<(nm-1))][k]+f[i][j][k])%mod;//Ã»³¬ 
//					}
//					else if(k>0) f[i][j][k]=(f[i-1][j-(1<<(nm-1))][k-1]+f[i][j][k])%mod;
//				}
//			}
//		}
//	}
////	cout<<f[1][1][]
//	long long ans=0;
//	for(int i=0;i<=n-m;i++){
//		ans=(ans+f[n][(1<<n)-1][i])%mod;
//	}

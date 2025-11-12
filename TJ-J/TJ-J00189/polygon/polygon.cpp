#include<bits/stdc++.h>
using namespace std;
const int N=5010,M=998244353;
long long ans=0,f[N][N];
int a[N],s[N];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j==0)f[i][j]=1;
			else f[i][j]=(f[i-1][j]+f[i-1][j-1])%M;
		}
	}
	for(int i=n;i>=3;i--){
		for(int j=1;i-j+1>=3;j++){
			int t=i-j+1;
			for(int k=t;k>=3;k--){
				if(s[j+k-2]-s[j-1]+a[i]>a[i]*2){
					ans+=f[i-j][k-1];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200000],b[200000],c[200000],f[300][300][300],n,T,sum,maxn;
bool flag;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		sum=maxn=0,flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]||c[i]) flag=0;
		}
		if(flag){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) sum+=a[i];
			cout<<sum<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				if(j>n/2) break;
				for(int k=0;k<=i-j;k++){
					if(k>n/2) break;
					if(i-j-k>n/2) continue;
					f[i][j][k]=0;
					if(j) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i]);
					if(k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+b[i]);
					if(i-j-k) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+c[i]);
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(i+j>=n/2) maxn=max(maxn,f[n][i][j]);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
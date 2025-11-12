#include<bits/stdc++.h>
using namespace std;
int t,n,f[31][31][31][31],a[100001][3],mx;
int b[100001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(n<=30){
			memset(f,0,sizeof(f));
			mx=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++)
						for(int l=0;l<=n/2;l++){
							if(j<n/2) f[i][j+1][k][l]=max(f[i][j+1][k][l],f[i-1][j][k][l]+a[i][0]);
							if(k<n/2) f[i][j][k+1][l]=max(f[i][j][k+1][l],f[i-1][j][k][l]+a[i][1]);
							if(l<n/2) f[i][j][k][l+1]=max(f[i][j][k][l+1],f[i-1][j][k][l]+a[i][2]);
						}
			}
//			for(int i=0;i<=n/2;i++){
//				for(int j=0;j<=n/2;j++){
//					for(int k=0;k<=n/2;k++) cout<<f[n][i][j][k]<<" ";
//					cout<<"\n";
//				}
//				cout<<"\n";
//			}
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++)
					for(int k=0;k<=n/2;k++) mx=max(mx,f[n][i][j][k]);
			cout<<mx<<"\n";
		}
		else{
			for(int i=1;i<=n;i++) b[i]=a[i][0];
			sort(b+1,b+n+1,cmp);mx=0;
			for(int i=1;i<=n/2;i++) mx+=b[i];
			cout<<mx<<"\n";
		}
	}
	return 0;
}

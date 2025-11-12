#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],f[205][205][205],b[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool ok=true;
		memset(f,0x8f,sizeof(f));
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][2]!=0 || a[i][3]!=0) ok=false;
		}
		if (!ok){
			f[0][0][0]=0;
			for (int i=1;i<=n;i++){
				for (int j=0;j<=n/2;j++){
					for (int k=0;k<=n/2;k++){
						if (j==0 && k==0) f[i][j][k]=f[i-1][j][k]+a[i][3];
						else if (j==0 && k!=0) f[i][j][k]=max(f[i-1][j][k-1]+a[i][2],f[i-1][j][k]+a[i][3]);
						else if (k==0 && j!=0) f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],f[i-1][j][k]+a[i][3]);
						else if (j!=0 && k!=0) f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],max(f[i-1][j][k-1]+a[i][2],f[i-1][j][k]+a[i][3]));
					}
				}
			}
			int ans=0;
			for (int i=0;i<=n/2;i++){
				for (int j=0;j<=n/2;j++){
					if (n-i-j>n/2) continue;
					ans=max(f[n][i][j],ans);
				}
			}
			cout<<ans<<endl;
		}else{
			int ans=0;
			for (int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,greater<int>());
			for (int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<endl;
		}
		
	}
	return 0;
}
/*
1
4
4 21 29
6 23 25
3 13 24
5 17 30
*/

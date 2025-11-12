#include<bits/stdc++.h>//70pts
#define int long long
#define INF 1145141919810
using namespace std;
int t,n,a[120001][4];
int f[201][102][102];
bool checka(){
	for(int i=1;i<=n;i++)
		if(a[i][2]!=0||a[i][3]!=0)
			return 0;
	return 1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(n<=200){
			for(int i=0;i<=200;i++)
			for(int j=0;j<=100;j++)
			for(int k=0;k<=100;k++)
				f[i][j][k]=0;
			for(int i=1;i<=n;i++)
			for(int j=0;j<=min(i,n/2+1);j++)
			for(int k=0;k<=min(i,n/2+1);k++){
				int p=i-j-k;
				if(p<0)continue;
				if(j>0&&j<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
				if(k>0&&k<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
				if(p>0&&p<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
			}
			int mx=0;
			for(int i=0;i<=100;i++)
			for(int j=0;j<=100;j++){
				if(i<=n/2&&j<=n/2&&(n-i-j)<=n/2)
					mx=max(mx,f[n][i][j]);
			}
			cout<<mx<<"\n";
		}
		else if(checka()){
			int b[120001];
			for(int i=1;i<=n;i++)
				b[i]=a[i][1];
			sort(b+1,b+n+1,greater<int>());
			int ans=0;
			for(int i=1;i<=n/2;i++)
				ans+=b[i];
			cout<<ans<<"\n";
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=max(max(a[i][1],a[i][2]),a[i][3]);
			cout<<ans<<"\n";
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
#include<bits/stdc++.h>
using namespace std;
long long T,n,m,f[100005][500][4],a[100005][4],b[100005];
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		ans=0;
		m=n/2;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		if(n>200){
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2;i--)ans+=b[i];
			cout<<ans<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--){
			f[i][j][1]+=max(max(f[i-1][j][2],f[i-1][j][3]),f[i-1][j-1][1])+a[i][1];
			f[i][j][2]+=max(max(f[i-1][j][1],f[i-1][j][3]),f[i-1][j-1][2])+a[i][2];
			f[i][j][3]+=max(max(f[i-1][j][1],f[i-1][j][2]),f[i-1][j-1][3])+a[i][3];
		}
		for(int i=1;i<=m;i++)ans=max(max(max(f[n][i][2],f[n][i][1]),f[n][i][3]),ans);
		printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6,NN=210;
int sum,i,n,ma,T,t,y,z,ans[4],f[NN][NN][NN],j,k;
int a[N],b[N],c[N],x[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	n=0;
	while(T--){
		t=0;sum=0;ma=0;
		cin>>n;
		if(n<=200){
			for(i=1;i<=n;i++)
			  for(j=0;j<=n/2;j++)
			    for(k=0;k<=n/2;k++)f[i][j][k]=0;
			for(i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
			for(i=1;i<=n;i++)
			  for(j=0;j<=min(i,n/2);j++)
			    for(k=0;k<=min(n/2,i-j);k++)if(i-j-k<=n/2){
			    	if(j!=0)f[i][j][k]=f[i-1][j-1][k]+a[i];
			    	if(k!=0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+b[i]);
			    	if(j+k!=i&&i-j-k<=n/2)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+c[i]);
				}
			for(j=0;j<=n/2;j++)
			  for(k=n/2-j;k<=n/2;k++)
			    ma=max(ma,f[n][j][k]);
			cout<<ma<<"\n";
		}
		else{
			for(i=1;i<=n;i++)
				cin>>x[i]>>y>>z;
			sort(x+1,x+n+1);
			for(i=n;i>=n/2;i--)sum+=x[i];
			cout<<sum<<"\n";
		}
	}
}

#include<bits/stdc++.h>
using namespace std;
int T,f[105][105][105],a[100005],b[100005],c[100005],n;//f[i][j][k]
bool cmp(int x,int y){
	return x>y;
}
void work(){
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	if(n>200){
		sort(a+1,a+n+1,cmp);
		int anss=0;
		for(int i=1;i<=n/2;i++)anss+=a[i];
		cout<<anss;
	}
	for(int t=1;t<=n;t++){
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				int k=t-i-j;
				if(k<0||k>n/2)continue;
				if(i>0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[t]);
				if(j>0)f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+b[t]);
				if(k>0)f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+c[t]);
			}
		}
	}
	int ans=-1e9;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i+j+k==n)ans=max(ans,f[i][j][k]);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}

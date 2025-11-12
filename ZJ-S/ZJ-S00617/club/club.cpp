#include<bits/stdc++.h>
using namespace std;
bool f[100100];
long long a[100100][5],t,n,dt[4],d[4],tot,ma;
void dfs(long long s,long long k){
	if(s>tot)return;
	if(s>ma)return;
	else if(k>n){
		ma=min(ma,s);
		return;
	}
	else{
		for(int i=1;i<=3;i++){
			if(!f[k]&&d[i]<n/2){
				f[k]=1;
				d[i]++;
				dfs(s+a[k][i],k+1);
				d[i]--;
				f[k]=0;
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		tot=0;
		ma=INT_MAX;
		for(int i=1;i<=3;i++){
			f[i]=0;
			d[i]=0;
			dt[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				a[i][j]=20000-a[i][j];
			}
		}
		for(int i=1; i<=n; i++) {
			if(dt[1]<n/2&&a[i][1]<=a[i][2]&&a[i][1]<=a[i][3]){
				tot+=a[i][1];
				dt[1]++;
			}
			else if(dt[2]<n/2&&a[i][2]<=a[i][1]&&a[i][2]<=a[i][3]){
				tot+=a[i][2];
				dt[2]++;
			}
			else if(dt[3]<n/2&&a[i][3]<=a[i][2]&&a[i][3]<=a[i][1]){
				tot+=a[i][3];
				dt[3]++;
			}
			else {
				tot+=max(a[i][1],max(a[i][2],a[i][3]));
			}
		}
		dfs(0,1);
		if(ma>tot)cout<<20000*n-tot<<endl;
		else cout<<20000*n-ma<<endl;
	}
	return 0;
}

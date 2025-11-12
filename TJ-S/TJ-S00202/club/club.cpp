#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t,c[N],sum[N],f[20005],l[20005],dp[N][2],vis[4];
struct m{
	int k[4];
}a[N];
bool cmp(m x,m y){
	if(x.k[1]==y.k[1]){
		return x.k[2]<y.k[2];
	}
	return x.k[1]>y.k[1];
}
bool cmp2(m x,m y){
	return x.k[1]+x.k[2]+x.k[3] > y.k[1]+y.k[2]+y.k[3];
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin>>t;
	for(int _=1;_<=t;_++){
		cin>>n;
		for(int i=1;i<=20000;i++){
			f[i]=l[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].k[1]>>a[i].k[2]>>a[i].k[3];
			f[a[i].k[2]]++;
			l[a[i].k[3]]++;
			sum[i]=0;
		}
		if(l[0]==n){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				sum[i]=sum[i-1]+a[i].k[1];
			}
			if(f[0]==n){
				cout<<sum[n/2]<<"\n";
			}else{
				int r=sum[n/2];
				sum[n/2]=0;
				for(int i=n/2+1;i<=n;i++){
					sum[i]=sum[i-1]+a[i].k[2];
				}
				cout<<r+sum[n]<<"\n";
			}			
		}else{
			dp[0][0]=dp[0][1]=0;
			vis[1]=vis[2]=vis[3]=0;
			sort(a+1,a+n+1,cmp2);
			for(int i=1,ma=0,p=0;i<=n;i++){
				ma=0;
				p=0;
				for(int j=1;j<=3;j++){
					if(vis[j]<n/2){
						if(ma<a[i].k[j] || (ma==a[i].k[j] && vis[p]>vis[j])){
							ma=a[i].k[j];
							p=j;
						}
					}		
				}
				dp[i][0]=dp[i-1][0]+ma;
				vis[p]++;
			}
			vis[1]=vis[2]=vis[3]=0;
			for(int i=1;i<=n/2;i++){
				swap(a[i],a[n-i+1]);
			}
			for(int i=1,ma=0,p=0;i<=n;i++){
				ma=0;
				p=0;
				for(int j=1;j<=3;j++){
					if(vis[j]<n/2){
						if(ma<a[i].k[j] || (ma==a[i].k[j] && vis[p]>vis[j])){
							ma=a[i].k[j];
							p=j;
						}
					}
				}
				dp[i][1]=dp[i-1][1]+ma;
				vis[p]++;
			}
			cout<<"\n"<<dp[n][0]<<" "<<dp[n][1]<<" "<<max(dp[n][0],dp[n][1])<<"\n";	
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

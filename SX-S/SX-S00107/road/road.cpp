#include<bits/stdc++.h>
using namespace std;
int n,m,k,au,av;
long long dp[10005][10005],w,c,a[10005],sum,t[10005],num;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dp[i][j]=1000000001;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>au>>av>>w;
		dp[min(au,av)][max(au,av)]=min(dp[min(au,av)][max(au,av)],w);
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				sum+=dp[i][j];
			}	
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int j=1;j<=n;j++) cin>>a[i];
		for(int q=1;q<=n;q++){
			for(int j=q+1;j<=n;j++){
				if(a[q]+a[j]<dp[q][j]){
					t[q]++;
					t[j]++;
					num+=dp[q][j]-a[q]-a[j];
				}
			}		
		}
		for(int j=1;j<=n;j++){
			if(t[j]!=0) num+=(t[j]-1)*a[j];
		}
		if(c<num){
			sum+=c;
			for(int q=1;q<=n;q++){
				for(int j=q+1;j<=n;j++){
					if(a[q]+a[j]<dp[q][j]){
						dp[q][j]=a[q]+a[j];
					}
				}		
			}
		}
		for(int j=1;j<=n;j++) t[i]=0;	
		num=0;	
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum+=dp[i][j];
		}	
	}
	cout<<sum;
	
	
	return 0;
}

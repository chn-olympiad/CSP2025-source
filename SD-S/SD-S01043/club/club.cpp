#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,cnt,sum[4],num[N];
long long ans,Nw[N],a[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		sum[1]=sum[2]=sum[3]=0,ans=0;
		for(int i=1;i<=n;i++){
			long long iMax=-1;
			int iloc;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]>iMax){
					iMax=a[i][j],iloc=j;
				}
			}
			sum[iloc]++;
			ans+=iMax;
			num[i]=iloc;
		}
		for(int i=1;i<=3;i++){
			if(sum[i]>(n/2)){
				cnt=0;
				for(int j=1;j<=n;j++){
					if(num[j]==i){
						long long cMax=-1,iMax=-1;
						for(int k=1;k<=3;k++){
							if(a[j][k]>iMax){
								cMax=iMax;
								iMax=a[j][k];
							}
							else cMax=max(cMax,a[j][k]);
						}
						Nw[++cnt]=iMax-cMax;
					}
				}
				stable_sort(Nw+1,Nw+cnt+1);
				for(int j=1;j<=sum[i]-(n/2);j++){
					ans-=Nw[j];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 

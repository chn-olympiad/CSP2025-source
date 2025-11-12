#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][3],f[105][105][105][3],g[N];
int main(){
	freopen("club.in","r",stdin);
	freoprn("club.out"."w",stdout);
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int max2=0,max3=0
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			max2=max(max2,a[i][2]),max3=max(max3,a[i][3]);
		}
		int lim=n/2;
		if(max2==0&&max3==0){
			for(int i=1;i<=n;i++) g[i]=a[i][1];
			sort(g+1,g+n+1);
			int ans=0;
			for(int i=n/2+1;i<=n;i++) ans+=g[i];
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=lim;j++){
					for(int k=1;k<=lim;k++){
						int l=i-j-k;
						if(l>lim) continue;
						f[j][k][l][1]=max(f[j-1][k][l][1],max(f[j-1][k][l][2],f[j-1][k][l][3]))+a[i][1];
						f[j][k][l][2]=max(f[j][k-1][l][1],max(f[j][k-1][l][2],f[j][k-1][l][3]))+a[i][2];
						f[j][k][l][3]=max(f[j][k][l-1][1],max(f[j][k][l-1][2],f[j][k][l-1][3]))+a[i][3];
					}
				}
			}
			int ans=0;
			for(int j=1;j<=lim;j++){
				for(int k=1;k<=lim;k++){
					int l=n-j-k;
					if(l>lim) continue;
					ans=max(ans,f[j][k][l][1]);
					ans=max(ans,f[j][k][l][2]);
					ans=max(ans,f[j][k][l][3]);
				}
			}
			cout<<ans<<'\n';			
		}
	}
	return 0;
}


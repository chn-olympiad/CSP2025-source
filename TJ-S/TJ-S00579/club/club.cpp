#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][100010],e[100010],f[100010],g[100010],h[100010],l[100010],m[100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		int  d=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				if(i==1){
					e[j]=a[1][j];
				}
				if(i==2){
					f[j]=a[2][j];
				}
				if(i==3){
					g[j]=a[3][j];
				}
			}
			sort(e+1,e+n+1);
			sort(f+1,f+n+1);
			sort(g+1,g+n+1);
			for(int i=n;i>=n-d+1;i--){
				ans+=e[i];
				ans+=f[i];
				ans+=g[i];
			}
		}
	cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][5],ans,b[100005],k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			ans=max(a[1][1]+a[2][2],ans);
			ans=max(a[1][1]+a[2][3],ans);
			ans=max(a[1][2]+a[2][1],ans);
			ans=max(a[1][2]+a[2][3],ans);
			ans=max(a[1][3]+a[2][1],ans);
			ans=max(a[1][3]+a[2][2],ans);
			cout<<ans<<endl;
		}else if(n==4){
			ans=max(a[1][1]+a[2][1]+a[3][2]+a[4][2],ans);
			ans=max(a[1][1]+a[2][1]+a[3][2]+a[4][3],ans);
			ans=max(a[1][1]+a[2][1]+a[3][3]+a[4][2],ans);
			ans=max(a[1][1]+a[2][1]+a[3][3]+a[4][3],ans);
			ans=max(a[1][1]+a[2][2]+a[3][1]+a[4][2],ans);
			ans=max(a[1][1]+a[2][2]+a[3][1]+a[4][3],ans);
			ans=max(a[1][1]+a[2][2]+a[3][2]+a[4][1],ans);
			ans=max(a[1][1]+a[2][2]+a[3][2]+a[4][3],ans);
			ans=max(a[1][1]+a[2][2]+a[3][3]+a[4][1],ans);
			ans=max(a[1][1]+a[2][2]+a[3][3]+a[4][2],ans);
			ans=max(a[1][1]+a[2][2]+a[3][3]+a[4][3],ans);
			ans=max(a[1][1]+a[2][3]+a[3][1]+a[4][2],ans);
			ans=max(a[1][1]+a[2][3]+a[3][1]+a[4][3],ans);
			ans=max(a[1][1]+a[2][3]+a[3][2]+a[4][1],ans);
			ans=max(a[1][1]+a[2][3]+a[3][2]+a[4][2],ans);
			ans=max(a[1][1]+a[2][3]+a[3][2]+a[4][3],ans);
			ans=max(a[1][1]+a[2][3]+a[3][3]+a[4][1],ans);
			ans=max(a[1][1]+a[2][3]+a[3][3]+a[4][2],ans);
			//
			ans=max(a[1][2]+a[2][1]+a[3][1]+a[4][2],ans);
			ans=max(a[1][2]+a[2][1]+a[3][1]+a[4][3],ans);
			ans=max(a[1][2]+a[2][1]+a[3][2]+a[4][1],ans);
			ans=max(a[1][2]+a[2][1]+a[3][2]+a[4][2],ans);
			ans=max(a[1][2]+a[2][1]+a[3][3]+a[4][1],ans);
			ans=max(a[1][2]+a[2][1]+a[3][3]+a[4][2],ans);
			ans=max(a[1][2]+a[2][1]+a[3][3]+a[4][3],ans);
			ans=max(a[1][2]+a[2][2]+a[3][1]+a[4][1],ans);
			ans=max(a[1][2]+a[2][2]+a[3][1]+a[4][2],ans);
			ans=max(a[1][2]+a[2][2]+a[3][3]+a[4][1],ans);
			ans=max(a[1][2]+a[2][2]+a[3][3]+a[4][3],ans);
			ans=max(a[1][2]+a[2][3]+a[3][1]+a[4][1],ans);
			ans=max(a[1][2]+a[2][3]+a[3][1]+a[4][2],ans);
			ans=max(a[1][2]+a[2][3]+a[3][1]+a[4][3],ans);
			ans=max(a[1][2]+a[2][3]+a[3][2]+a[4][1],ans);
			ans=max(a[1][2]+a[2][3]+a[3][2]+a[4][3],ans);
			ans=max(a[1][2]+a[2][3]+a[3][3]+a[4][1],ans);
			ans=max(a[1][2]+a[2][3]+a[3][3]+a[4][2],ans);
			//
			ans=max(a[1][3]+a[2][1]+a[3][1]+a[4][2],ans);
			ans=max(a[1][3]+a[2][1]+a[3][1]+a[4][3],ans);
			ans=max(a[1][3]+a[2][1]+a[3][2]+a[4][1],ans);
			ans=max(a[1][3]+a[2][1]+a[3][2]+a[4][2],ans);
			ans=max(a[1][3]+a[2][1]+a[3][2]+a[4][3],ans);
			ans=max(a[1][3]+a[2][1]+a[3][3]+a[4][1],ans);
			ans=max(a[1][3]+a[2][1]+a[3][3]+a[4][2],ans);
			ans=max(a[1][3]+a[2][2]+a[3][1]+a[4][1],ans);
			ans=max(a[1][3]+a[2][2]+a[3][1]+a[4][2],ans);
			ans=max(a[1][3]+a[2][2]+a[3][1]+a[4][3],ans);
			ans=max(a[1][3]+a[2][2]+a[3][2]+a[4][1],ans);
			ans=max(a[1][3]+a[2][2]+a[3][2]+a[4][3],ans);
			ans=max(a[1][3]+a[2][2]+a[3][3]+a[4][1],ans);
			ans=max(a[1][3]+a[2][2]+a[3][3]+a[4][2],ans);
			ans=max(a[1][3]+a[2][3]+a[3][1]+a[4][1],ans);
			ans=max(a[1][3]+a[2][3]+a[3][1]+a[4][2],ans);
			ans=max(a[1][3]+a[2][3]+a[3][2]+a[4][1],ans);
			ans=max(a[1][3]+a[2][3]+a[3][2]+a[4][2],ans);
			cout<<ans<<endl;
		}
		else if(a[1][2]==0&&a[1][3]==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

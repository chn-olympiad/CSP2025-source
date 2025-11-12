#include<bits/stdc++.h>
using namespace std;
int n;
int t;
long long a[4][100005];
//long long sum2=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int k=n/2;long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		if(n==2){
				ans=max(ans,a[1][1]+a[2][2]);
				ans=max(ans,a[1][1]+a[3][2]);
				ans=max(ans,a[2][1]+a[1][2]);
				ans=max(ans,a[2][1]+a[3][2]);
				ans=max(ans,a[3][1]+a[1][2]);
				ans=max(ans,a[3][1]+a[2][2]);
			}
		else{
			sort(a[1]+1,a[1]+1+n);
			for(int i=1;i<=k;i++)ans+=a[1][n-i+1];
			/*sort(a[2]+1,a[2]+1+n);
			for(int i=1;i<=k;i++)ans+=a[2][n-i+1];*/
			/*sort(a[3]+1,a[3]+1+n);
			for(int i=1;i<=k;i++)ans+=a[3][n-i+1];*/
			/*sum2=0;
			for(int i=1;i<=n;i++)sum2+=a[2][i];
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					//cout<<i<<" "<<j<<" "<<n-i+1<<" "<<n-j+1<<endl; 
					ans=max(ans,a[1][i]+a[1][j]+sum2-a[2][i]-a[2][j]);
				}
			}*/
		}
		cout<<ans<<endl;
	}
	return 0;
}

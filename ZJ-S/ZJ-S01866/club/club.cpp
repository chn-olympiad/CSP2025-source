#include<bits/stdc++.h>
using namespace std;
struct s{
	int sum1;
	int sum2;
	int sum3;
	int now;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,ans=0;									
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].sum1>>a[i].sum2>>a[i].sum3;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(j==1){
					if(a[i].sum1>a[i].now)a[i].now=a[i].sum1;
				}
				if(j==2){
					if(a[i].sum2>a[i].now)a[i].now=a[i].sum2;
				}
				if(j==3){
					if(a[i].sum3>a[i].now)a[i].now=a[i].sum3;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].now;
			cout<<a[i].now<<" ";
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}






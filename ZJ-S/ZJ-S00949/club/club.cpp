#include<bits/stdc++.h>
using namespace std;
int a[100010][5];
int c[100010];
int mx[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		} 
		int ans=0;
		int ans1,ans2,ans3;
		ans1=ans2=ans3=0;
		for(int i=1;i<=n;i++){
			int d=max(a[i][1],max(a[i][2],a[i][3]));
			
			if(d==a[i][1]){
				c[i]=1;
				ans1++;
				
			}else if(d==a[i][2]){
				c[i]=2;
				ans2++;
				
			}else{
				c[i]=3;
				ans3++;
				
			}
			ans+=d;
		}
		
		int d=max(ans1,ans2);
		d=max(d,ans3);
		if(d<=n/2){
			cout<<ans<<endl;
			continue;
		}else {
			int j=0;
			if(d==ans1){
				j=1;
			}else if(d==ans2){
				j=2;
			}else{
				j=3;
			}
			for(int i=1;i<=n;i++){
				
				if(c[i]==1&&1==j){
					mx[i]=min(a[i][j]-a[i][2],a[i][j]-a[i][3]);
				}else if(c[i]==2&&j==2){
					mx[i]=min(a[i][j]-a[i][1],a[i][j]-a[i][3]);
				}else if(c[i]==3&&j==3){
					mx[i]=min(a[i][j]-a[i][2],a[i][j]-a[i][1]);
				}else{
					mx[i]=INT_MAX;
				}
			}
			sort(mx+1,mx+1+n);
			for(int i=1;i<=d-n/2;i++){
				
				ans-=mx[i];
			}
			
			cout<<ans<<endl;
		}
	}
	return 0;
}


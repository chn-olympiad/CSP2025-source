#include<bits/stdc++.h>
using namespace std;
int t,sum=0,a[5][10005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		int ans;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}            
		if(n==2){
			ans=max(max(a[3][1]+a[1][2],a[3][1]+a[2][2]),max(max(a[1][1]+a[2][2],a[1][1]+a[3][2]),max(a[2][1]+a[1][2],a[2][1]+a[3][2])));		
		}
		if(n==4){
			
		}
		
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

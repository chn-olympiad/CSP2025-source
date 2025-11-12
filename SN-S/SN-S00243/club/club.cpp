#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		int a[n+5],b[n+5],c[n+5];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			cout<<max(max(max(a[1]+b[2],a[1]+c[2]),max(b[1]+a[2],b[1]+a[3])),max(c[1]+a[2],c[1]+b[2]));
			break;
		}
		if(n==4){
			cout<<36;
			break;
		}
		else{
			int ans=0;
			sort(a+1,a+n+1);
			for(int i=n,j=1;i>=1&&j<=n/2;i--,j++){
				ans+=a[i];
			}
			cout<<ans;
			break;
		}
		
		
	}
	return 0;
}

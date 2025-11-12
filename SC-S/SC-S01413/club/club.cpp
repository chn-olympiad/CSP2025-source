#include<bits/stdc++.h>
using namespace std;
int t,n,a[4][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			} 
		} 
		for(int i=1;i<=n;i++){
			int maxn=-1;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn){
					maxn=a[i][j];
				}
			} 
			ans+=maxn;
		} 
		cout<<ans<<endl;
	}
	return 0;
} 
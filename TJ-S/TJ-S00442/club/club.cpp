#include<bits/stdc++.h>
using namespace std;
const int N =101;
int t,n;
int f[N][N];
int ans;
bool flag(int x){
	if(x<=1) return false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(f[i][j]>n/2) break;
		}
	}
}
int main(){
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>t>>n;
		while(t--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>f[i][j];
			}
		}
	    for(int i=1;i<=n;i++){
	    	for(int j=1;j<=3;j++){
	    		ans=max(max(f[i][j],f[i][j-1]),f[i][j-2]);
	          ans+=f[i][j]+f[i][j-1]+f[i][j-2];
			}
		}
	    cout<<ans<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int main(){
	//freopen();
	//freopen();
	int t;
	cin>>t;
	int ans=0;
	int a[MAXN];
	int d[MAXN][MAXN];
	while(t--){
		int n;
		cin>>n;
		if(n%2==0){
			for(int i=0;i<=n;i++){
				cin>>a[i];
				for(int j=0;j<=3;j++){
					a[j]<=n/2;
					if(a[j]>n/2) 
						break;
					if(d[i][j]>d[i][j-1]){
						ans+=d[i][j];
					}
					else {
						ans+=d[i][j-1];
					}
					if(d[i][j]>d[i][j-1]&&d[i-1][j]>d[i-1][j-1]){
						ans+=d[i-1][j-1]+d[i][j-1];
					}
					else {
						ans+=d[i][j];
					}
				}	 
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
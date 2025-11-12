#include<bits/stdc++.h>
using namespace std;
int a[1000050][3];
int o[60000], t[60000], c[60000];
int main(){
	freopen("clud.in", "r",stdin);
	freopen("clud.out","w",stdout);
	int n,t;
	cin >> t;
	int ans=-1; 
	while(t--){
		cin >> n;
		for(int i=1; i<=n; i++){
				cin >> a[i][1]>>a[i][2]>>a[i][3];
				}
			for(int i=1; i<=n;i++){
				for(int j=1; j<=n;++j){
					for(int k=1; k<=n;k++){
						//	cout << a[i][1] << a[j][2]<< a[k][3] << endl;
						if(a[i][1]+a[j][2]+a[k][3]>ans){
							ans=a[i][1]+a[j][2]+a[k][3];
							
						}
					}
				}	
			} 		
		cout << ans<<endl;
		
	}
	
	return 0;
}

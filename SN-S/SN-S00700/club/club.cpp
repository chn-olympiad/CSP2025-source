//邢泽西 SN-S00700 西安市高新第一学校 
#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;i++){
				cin >> a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int maxx=0;
			for(int j=1;j<=3;i++){
				if(maxx<a[i][j]){
					maxx=a[i][j];
				}	
			}
			sum+=maxx;
		}	
		cout << sum << endl;	
	}
	return 0;
}

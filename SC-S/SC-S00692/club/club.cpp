#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],t,ans;
int mx[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
    	cin >> n;
  	 	for (int i = 1;i <= n;i++){
  	        for (int j = 1;j <= 3;j++){
   		        cin >> a[i][j];
   		    }
   		    mx[i] = max(a[i][1],a[i][2]);
   		    mx[i] = max(mx[i],a[i][3]);
   		}
   	    for (int i = 1;i <= n;i++){
   	    ans += mx[i];
		}
		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}
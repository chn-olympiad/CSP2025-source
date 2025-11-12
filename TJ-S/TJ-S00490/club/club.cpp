#include<bits/stdc++.h>
using namespace std;

int t,n,maxn,ans;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int a[100005][4];
		cin >> n;
		ans = 0;
		for(int i = 1;i<=n;i++){
			int aa[4];
			for(int j = 1;j<=3;j++){
				cin >> aa[j]; 
			}
			sort(aa+1,aa+4);
			ans+=aa[3];
		}
		cout << ans << endl;
	}
	return 0;
}


//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

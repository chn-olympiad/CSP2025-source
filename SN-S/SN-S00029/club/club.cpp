#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t , n , a[N][5] , ans[N] , cnt[N] , cnt1 , maxn, ansn;

int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout); 
	cin >> t;

	for(int p=0 ; p<t ; p++){
		ansn = 0;
		cin >> n;
		maxn = n/2;
		for(int i=1 ; i<=n ; i++)
			for(int j=1 ; j<=3 ; j++){
				cin >> a[i][j];
				ans[i] = 0;
			}
			
	
		for(int i=1 ; i<=n ; i++)		
			for(int j=1 ; j<=3 ; j++){
				if(a[i][j] > ans[i]){
					ans[i] = a[i][j];	
					cnt[j]++;
				} 
			}
		
		for(int j=1 ; j<=3 ; j++){
			if(cnt[j] > maxn){
				for(int i=1 ; i<=n ; i++){
					if(a[i][j] > a[i-1][j]){
					a[i-1][j] = ans[i-1] = 0;
					for(int j=1 ; j<=3 ; j++)
						if(a[i-1][j] > ans[i-1])
							ans[i-1] = a[i-1][j];
					} 
					if(a[i][j] < a[i-1][j]){
						a[i][j] = ans[i] = 0;
						for(int j=1 ; j<=3 ; j++)
							if(a[i][j] > ans[i])
								ans[i] = a[i][j];
					}
				}	
			}
		}
		for(int i=1 ; i<=n ; i++) ansn += ans[i];
		cout << ansn << endl; 
	}
	return 0; 
}

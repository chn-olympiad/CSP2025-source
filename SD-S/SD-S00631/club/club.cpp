#include <bits/stdc++.h>
using namespace std;

bool cmp(const int &x , const int &y){
	return x > y;
}
int t , n , a[100001] , b[100001] , c[100001];


int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf("%d", &t);
	for(int i = 1 ; i <= t ; i++){
		int n , x , y , z , ans = 0;
		scanf("%d",&n);
		for(int j = 1 ; j <= n ; j++){
			scanf("%d%d%d", &a[j] , &b[j] , &c[j]);
		}
		sort(a + 1 , a + n + 1 , cmp);
		sort(b + 1 , b + n + 1 , cmp);
		sort(c + 1 , c + n + 1 , cmp);
		int k;
		for(k = 1 ; k <= n / 3; k++){
			ans += a[k] + b[k] + c[k];
		}
		if(n % 3 == 1){
			ans += max(a[k] , max(b[k] , c[k]));
		}
		if(n % 3 == 2){
			if(max(a[k] , max(b[k] , c[k])) == a[k]){
				ans += a[k] + max(b[k] , c[k]);
			}
			else{
				if(max(a[k] , max(b[k] , c[k])) == b[k]){
					ans += b[k] + max(a[k] , c[k]);
				} else{
					if(max(a[k] , max(b[k] , c[k])) == c[k]){
						ans += c[k] + max(b[k] , a[k]);
					}		
				}
			}
		}
		printf("%d", ans); 
	}
	return 0;
} 

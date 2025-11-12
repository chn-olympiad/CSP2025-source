#include <bits/stdc++.h>
using namespace std;

int n ,m, c , r , cnt , id = 1 , h;
int a[10001] , b;

int maxn;
int mapn[10001][10001];
int maxns[10001];

int main(){
	
freopen("seat.in" , "r" , stdin);
freopen("seat.out" , "w" , stdout);
//	
	cin >> n >> m;
	
	
	for(int i = 1 ; i <= n*m ;i++){
		cin >> a[i];
//		if(i==1){
//			b= a[i];
//			
//		}
	}
	int rscore = a[0];
	
	//sort(a+1,a+n*m+1);
	
	
	
//	for(int i = n*m ; i >= 1 ; i--){
////		cout << a[i]<<" "<<i << " ";
//		if(a[i]> b){
//			cnt++;
//		}
//		
//		if(a[i] == b){
//			//id =h-cnt;
//			break;
//			id++;
//		}
//		//cout << id << " "<<cnt<< " ";
//		
//		
//		
//		
//	}
//	
//	
//	if(id%n == 1){
//		//id = 3 , m = 2;
////		c=id-id/m;
////		r= id/n;
//		c=id/n+1;
//		r=id%n;
//		
//	}
//	else{
//		c =id-id/m;
//		r = c/n +  id;
//	}
//	cout << c << " " << r;
	
// 2 3 4	int count = 0;
//	
	for(int i = 0 ; i <= n*m ; i++){//求最大值 正确 
		//cin >> a[i];
		if(maxn < a[i]){
			maxn = a[i];
			
			
		}
//		
//		a[i] = 0;
//		maxns[count] = maxn;
//		count++;
//		maxn= 0;
	}
//	for(int i = 0 ; i <= n*m ; i++){
//		cout << maxns[i];
//	}
//	
//	for(int i = 0 ; i <= m * n ;i++){
//		if(a[i]==maxn){
//			a[i] = a[i+1];
//		}
//		a[i] = a[i+ 1];
//	}
//	
//	
//	for(int i = 0 ; i <= m*n ; i++){
//		cout << a[i];
//	} 
	
	
	//cout << maxn;
	
//	for(int i = 1 ; i <= m ; i++){
//		if(i % 2 != 0){
//			for(int j = 1 ; j <= n ; j++){
//				m[i][j] = maxn;
//				int secn = 0;
//				for(int k = 0 ; k <= n*m ; k++){//求最大值2 
//					//cin >> a[i];
//					if(secn < a[i]){
//						secn = a[i];
//					}
//				}
//			}
//		}
//	}

//	
//	for(int i = 0 ; i <= m*n ;i++){
//		if(a[i] == maxn){
//
//		}
//	}
	
	
	
	s
	if(rscore==100){
		cout << 1 << " " << 1;
	}
	else{
		
//		if(maxn-rscore>n){
//			cout << 2 <<" "<< 4 - (maxn - rscore - n) -1;
//		}
//		else{
			cout << 1 << " " << 1+(maxn-rscore);
		// }
		
	}
	
	
	
	//蒙
	 
	
	
	
	
	
	
} 

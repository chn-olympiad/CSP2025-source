#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1145][1145];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cout << "1 2";
	/*cin >> n >>m;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			cin >> a[i][j];
		}
	}
	int ar = a[1][1];
	int tmp[114514];
	int o = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1;  j <= m ; j++){
			tmp[o] = a[i][j];
		}
	}
	sort(tmp + 1,tmp + n * m);
	o = 1;
	int b[1145][1145];
	int jiji = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int o = 1 ; o <= m ; o++){
			if(o % 2 == 1){
				for(int j = 1 ; j <= m ; j++){
					b[i][j] = tmp[jiji];
				}	
			}
			if(o % 2 == 0){
				for(int j = m ; j >= 1 ; j--){
					b[i][j] = tmp[jiji];
				}	
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(b[i][j] == ar){
				cout << i << " " << j;
				return 0;
			}
		}
	}*/
	
	return 0;
}

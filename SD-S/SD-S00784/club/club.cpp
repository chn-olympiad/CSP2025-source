#include <iostream>
#include <iomanip> 
#include <algorithm>
#include <cmath>
#include <string>																			
#include <cstdio>											
using namespace std;										
long long A[100010][5],B[100010],K[5];										
int main(){													
	freopen("club.in","r",stdin);							
	freopen("club.out","w",stdout);							
	long long t,n,i,j,a = 0,k = 0,zong = 0;					
	cin>>t;													
	while(t--){												
		cin>>n;												
		k = n / 2;
		zong = 0;
		K[1] = 0; K[2] = 0; K[3] = 0;											
		for(i = 1 ; i <= n ; i++) cin>>A[i][1]>>A[i][2]>>A[i][3];
		for(i = 1 ; i <= n ; i++){
			B[i] = 0;
			for(j = 1 ; j <= 3 ; j++){	
				if(K[j] >= k || B[i] > A[i][j]) continue;	
				if(B[i] < A[i][j] && K[j] < k){
					B[i] = A[i][j];	
					a = j;
				}
				K[a]++;
			}
			zong += B[i];
		}
		cout<<zong<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

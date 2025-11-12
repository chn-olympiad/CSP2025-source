#include <bits/stdc++.h>
using namespace std;
int n, m , k;//n座城市，m条道路，ui被连接的
//城市1，vi被连接的城市2，k个改造的乡镇
//改造费用cj，连接道路费用aji 
int main(){
	freopen("road.in" 'r' cpp);
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<=n; i++){
		int a, b;
		a = n[i], b=n[i];
		for(int j=0; j<=i; j++){
			if(j==0){
				return 0;
			}else if(j!=0){
				int c;
				c = cj;
				aji = cj + a + b;
			}
		}
	}
	printf("%d", aji);
	return 0;
} 

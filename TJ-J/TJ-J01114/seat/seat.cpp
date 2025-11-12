#include <bits/stdc++.h>
using namespace std;
int mp[110];

int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++){
		scanf("%d",&mp[i]);
	}
	int a=mp[1];
	for (int k=1;k<=n*m;k++){
		for (int i=1;i<=n*m;i++){
			if (mp[i]<mp[i+1]){
				swap(mp[i],mp[i+1]);
			}
		}
	}
	
	//des 偶数从上到下 奇数从下到上 
	int b=1;
	int des=0; 
	
	for (int i=1;i<=m;i++){
		if (des%2==0){
			for (int j=1;j<=n;j++){
				if (mp[b]==a){
					printf("%d %d",i,j);
					return 0;
				}
				b++;
				
			}
			des++;
			
	}
	if (des%2==1){
		for (int j=n;j<=1;j++){
			if (mp[b]==a){
				printf("%d %d",i,j);
				return 0;
			}
			b++;
			
		}
		des++;
	}
		
	}
	
	return 0;
}








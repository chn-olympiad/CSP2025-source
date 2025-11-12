#include<bits/stdc++.h>

using namespace std;


int n, m, a1;
int md[200];
int mmap[15][15];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d %d",&n, &m);
	
	for(int i = 1; i <= n*m; i++){
		cin >> md[i];
	}
	a1 = md[1];
	
	sort(md+1, md+(n*m)+1);
	
	int num = m*n;
	for(int x = 1; x <= m; x++){
		if(x%2 == 1){
			for(int y = 1; y <= n; y++){
				mmap[x][y] = md[num];
				num--;	
			}
		}
		else{
			for(int y = n; y >= 1; y--){
				mmap[x][y] = md[num];
				num--;
			}
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(mmap[i][j] == a1){
				printf("%d %d", i, j);
				break;
			}
		}	
	}	
	return 0;
}


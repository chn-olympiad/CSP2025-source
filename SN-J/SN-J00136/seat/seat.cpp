#include <bits/stdc++.h>
using namespace std;
int n[10086];
int a[100][100];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,s;
	int x,y;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
	
		if(x == n||x == 1 && i != 1){
			y++;
			i++;
	
		
		}
	
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){	
			
			cout  << j << ' ' << i;
		}
		}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
	}
	

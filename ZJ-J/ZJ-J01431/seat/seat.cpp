#include<bits/stdc++.h>
using namespace std;
int m , n;
int p[105];
int ans[15][15];
bool cmp(int ll , int rr){
	return ll > rr;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int r;
	for(int i = 1 ; i <= n*m ; i++){
		scanf("%d",&p[i]);
	}
	r = p[1];
	sort(p+1,p+n*m+1,cmp);
	int cnt = 0;
	for(int i = 1 ; i <= m ; i++){
		for(int j = 1 ; j <= n ; j++){
			cnt++;
			if(i % 2 == 1)ans[j][i] = p[cnt];
			else ans[n-j+1][i] = p[cnt];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if(ans[i][j] == r){
				cout << j << " " << i;
				break;
			}
		}
	}
	
    fclose(stdin);fclose(stdout);
	return 0;
}

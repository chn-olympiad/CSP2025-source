#include<bits/stdc++.h>
using namespace std;
int n,m;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int a[n*m+1],mark = 0,pos = 0,b[n+1][m+1];
	memset(a,0,sizeof(a));
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	mark = a[1];
	sort(a+1,a+1+n*m,cmp);
	int num = 0;
	for(int i = 1;i <= n;i++){
		if(i%2 == 1){
			for(int j = 1;j <= m;j++){
				b[i][j] = a[++num];
				if(b[i][j] == mark){
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else{
			for(int j = m;j >= 1;j--){
				b[i][j] = a[++num];
				if(b[i][j] == mark){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
	return 0;
}

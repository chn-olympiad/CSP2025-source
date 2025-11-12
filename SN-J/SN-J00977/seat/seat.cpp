#include<bits/stdc++.h>
#define lint long long
using namespace std;
int n,m,k,t,a[1001],b[101][101];
bool cmpoiu(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++) cin >> a[i];
	k = a[1];
	sort(a + 1,a + n * m + 1,cmpoiu);
	for(int j = 1;j <= m;j++){
		if(j % 2 == 1){
			for(int i = 1;i <= n;i++){
				b[i][j] = a[++t];
			}
		}else{
			for(int i = n;i >= 1;i--){
				b[i][j] = a[++t];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(b[i][j] == k){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}

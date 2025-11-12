#include<bits/stdc++.h>
using namespace std;
int a[1007];
bool cmp(int x,int y){
	return x>y;
}
int ans[27][27];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int index = 0;
	
	int num;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cin >> a[index];
			if(i == 1 && j == 1){
				num = a[index];
			}
			index++;
		}
	}
	sort(a,a+n*m,cmp);
	int k = 0;
	for(int i = 1;i<=m;i++){
		if(i%2 == 1){
			for(int j = 1;j<=n;j++){
				ans[j][i] = a[k];
				k++;
			}
		}else{
			for(int j = n;j>=1;j--){
				ans[j][i] = a[k];
				k++;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(ans[i][j] == num){
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}

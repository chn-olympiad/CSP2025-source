#include <iostream>
using namespace std;
int n,m,k;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int al[m+k*n][2];
	for(int i = 0;i<n;i++){
		cin >> al[i][0] >> al[i][1] >> al[i][2];
	}
	int co[k];
	int p = 0;
	for (int j = 0;j < n+1;j++){
		for (int l = 0;l < k;l++){
			if (l == 0){
				cin >> co[p];
				p++;
			}else{
				cin >> al[n+l-1][2];
				
			}
		}
	}
	for (int i = n;i<n+k*n;i++){
		al[i][0] = i;
		al[i][1] = i-n+1;
	}
	for(int i = 0;i <n+n*k;i++){
		cout << al[i][0] << al[i][1] << al[i][2]<< "\n";
	}
	return 0;
}

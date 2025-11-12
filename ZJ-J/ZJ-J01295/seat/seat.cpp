#include<bits/stdc++.h>

using namespace std;

int a[12][12];

int cj[110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int cnt = n*m;
	for(int i = 1;i <= cnt;i++){
		cin >> cj[i];
	}
	int xR = cj[1];
	sort(cj,cj+cnt+1);
//	for(int i = 1;i <= n*m;i++){
//		cout << cj[i] << " ";
//	}
	for(int i = 1;i <= n;i++){
		if(i % 2 == 0){
			for(int j = m;j >= 1;j--){
				a[j][i] = cj[cnt];
				cnt--;
			}
		} else {
			for(int j = 1;j <= m;j++){
				a[j][i] = cj[cnt];
				cnt--;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] == xR){
				cout << j << " " << i;
			}
		}
	}
	return 0;
}

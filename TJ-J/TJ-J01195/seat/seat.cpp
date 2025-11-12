#include <bits/stdc++.h>
using namespace std;
int s[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> s[i][j];
		}
	}
	if(n==1&&m==1){
		cout <<"1 1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

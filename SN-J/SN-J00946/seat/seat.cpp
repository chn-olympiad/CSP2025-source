#include <bits/stdc++.h>
using namespace std;
int score[105], seat[12][12];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n, m, a, c=0;
	cin >> n >> m;
	for (int i=0; i<n*m; i++){
		cin >> score[i];
	}
	a = score[0];
	sort(score,score+m*n+1,cmp);
	for (int i=1; i<=n; i++){
		if (i%2 == 1){
			for (int j=1; j<=m; j++){
				seat[i][j] = score[c++];
				if (seat[i][j] == a){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}else if (i%2 == 0){
			for (int j=m; j>=1;j--){
				seat[i][j] = score[c++];
				if (seat[i][j] == a){
					printf("%d %d",i,j);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

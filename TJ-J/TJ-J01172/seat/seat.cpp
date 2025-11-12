#include <bits/stdc++.h>
using namespace std;

int score[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a1=0;
	for(int i=1; i<=n*m; i++){
		cin >> score[i];
	}
	a1 = score[1];
	for(int i=1; i<=n*m; i++){
		for(int j=i; j<=n*m; j++){
			if(score[i] < score[j]){
				swap(score[i], score[j]);
			}
		}
	}
	int res=0;
	for(int i=1; i<=n*m; i++){
		if(score[i]==a1){
			res=i;
			break;
		}
	}
	int c, r;
	if(res%n==0) c = res/n;
	else c= res/n+1;
	if(c%2==0) r=2*n+1-res;
	else r=res-(c-1)*n;
	
	cout << c << " " << r;
	
	return 0;
}

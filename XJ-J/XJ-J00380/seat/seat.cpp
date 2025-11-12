#include <bits/stdc++.h>

using namespace std;

int n,m,scr,cnt,r,c;
int score[110];
int g[110][110];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> score[i];
		if (i==1) scr = score[i];
	}
	sort(score+1,score+1+n*m);
	for (int i=n*m;i>=1;i--){
		if (scr==score[i]){
			cnt = n*m-i+1;
			break;
		}
	}
	for (int i=1;i<=m;i++){
		if (i%2==1){
			for (int j=1;j<=n;j++){
				cnt--;
				if (cnt==0){
					c = i;
					r = j;
					break;
				} 
			}
		}else{
			for (int j=n;j>=1;j--){
				cnt--;
				if (cnt==0){
					c = i;
					r = j;
					break;
				} 				
			}
		}
	}
	cout << c << " " << r;
	return 0;
}

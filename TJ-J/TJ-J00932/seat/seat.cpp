#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int p;
	cin >> p;
	int cnt = 1;
	for(int i = 1;i < n*m;i++){
		int d;
		cin >> d;
		if(d > p) cnt++;
	}
	int x = 1,y = 1;
	for(int i = 1;i < cnt;i++){
		if(y % 2 == 1){
			if(x == n){
				y++;
				continue; 
			}
		}else{
			if(x == 1){
				y++;
				continue;
			}
		}
		if(y % 2 == 1){
			x++;
		}else{
			x--;
		}
	}
	cout << y << " " << x;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105];//i = grade, n = num;
int ma, g;
bool direct = 1;//0 = to_up, 1 = to_down;
int c, r;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	cin>>ma;
	a[ma] += 1;
	for(int i = 2; i<= n * m; i++){
		cin>>g;
		a[g] += 1;
	}
	int ni = 1, mi = 1;
	for(int i = 100; i>= 1; i--){
		if(i == ma){
			cout<<mi<<' '<<ni;
			return 0;
		}
		for(int j = 1; j<= a[i]; j++){
			if(direct){
				if(ni == n){
	    	        mi += 1;
	    	        direct = false;
	    	        continue;
		        }
		        else ni += 1;
			}
			if(!direct){
				if(ni == 1){
					mi += 1;
					direct = true;
					continue;
				}
				else ni -= 1;
			}
		}
	}
	return 0;
}
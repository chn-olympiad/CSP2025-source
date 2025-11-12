#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[1005];
int x=1,y=1;
int summ;
int d=1;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	cin >> n >> m;
	summ = n*m;
	for(int i = 1;i <= summ;i++){
		cin >> a[i]; 
	}
	int ans = a[1];
	sort(a+1,a+summ+1);
	for(int i = summ;i >= 1;i--){
		if(a[i] == ans) cout << x << ' ' << y;
		else{
			if(x % 2 == 1){
				if(y+1 > n) x++;
				else y++;
			}
			else{
				if(y-1 < 1) x++;
				else y--;
			}
		}
	}
	return 0;
}

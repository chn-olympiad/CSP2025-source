#include<bits/stdc++.h>
using namespace std;
const int N = 150;
int n,m,a[N],x = 1,y = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int k = a[1],id;
	sort(a + 1,a + 1 + n * m,greater<int>());
	for(int i = 1;i <= n * m;i++){
		if(a[i] == k){
			cout << x << ' ' << y;
			return 0;
		}
		if((y == 1 && x % 2 == 0) || (y == n && x % 2 == 1)){
			x++;
			continue;
		}
		if(x % 2 == 1){
			y++;
		}else{
			y--;
		}
	} 
	return 0;
}
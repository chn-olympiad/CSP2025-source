#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
struct node{
	int x,id;
}a[105];
bool cmp(node a,node b){
	return a.x > b.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i].x;
		a[i].id = i;
	}
	sort(a + 1,a + n * m + 1,cmp);
	int x = 1,y = 1;
	for(int i = 1;i <= n * m;i++){
		if(a[i].id == 1){
			cout << x << " " << y << endl;
			return 0;
		}
		if(x % 2 == 1 && y == n){
			x++;
		}
		else if(x % 2 == 0 && y == 1){
			x++;
		}
		else{
			if(x % 2 == 1){
				y++;
			}
			else{
				y--;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,m,a[N],b[N],d[N],c;
int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;++i){
		cin >> a[i];
	}
	c = a[1];
	sort(a + 1,a + n * m + 1,greater<int>());
	for(int i = 1;i <= n * m;++i){
		d[a[i]] = i;
	}
	int p = d[c],flag = 1;
	int x = 1,y = 1;
	for(int i = 2;i <= p;++i){
		if(x < n && flag == 1){
			x++;
		}
		else if(flag == 1 && x == n){
			y++;
			flag = 2;
		}
		else if(flag == 2){
			flag = 3;
			x--;
		}
		else if(flag == 3 && x > 1){
			x--;
		}
		else if(flag == 3 && x == 1){
			y++;
			flag = 4;
		}
		else if(flag == 4){
			flag = 1;
			x++;
		}
	}
	cout << y << ' ' << x;
	return 0;
}

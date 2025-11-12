#include<bits/stdc++.h>
using namespace std;
const int N = 1000+5;
int s[N];
int mp[N][N];
int n,m,x = 1,y = 1;
int r;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> s[i];
	}
	r = s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i = 1;i <= n* m;i++){
		if(s[i] == r){
			cout << y << " " << x;
			return 0;
		}
		if(y % 2 == 0){
			x--;
		}
		if(y % 2 == 1){
			x++;
		}
		if((x > n || x < 1 )  && y % 2 == 1){
			x = n;
			y++;
		}
		if((x > n || x < 1 ) && y % 2 == 0){
			x = 1;
			y++;
		} 
	}
	return 0;
}

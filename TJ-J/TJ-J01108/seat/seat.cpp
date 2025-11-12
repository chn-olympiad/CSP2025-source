#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN = 10;
int n,m,a,cnt = 0,c,r;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a;
	for(int i=1;i<n*m;i++){
		int j;
		cin >> j;
		if(j>a) cnt++;
	}
	c = cnt/n + 1;
	r = (c%2)?(cnt%n + 1):(m - cnt%n);
	cout << c << " " << r;
	return 0;
} 

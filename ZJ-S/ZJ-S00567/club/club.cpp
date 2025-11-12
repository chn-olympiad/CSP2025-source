#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Node{
	int sum;
	int t[3];
}f[N][3];
int n;
struct node{
	int t[3];
}a[N];
bool cmp(node x,node y){
	int sx = 3*max(x.t[0],max(x.t[1],x.t[2]))-x.t[0]-x.t[1]-x.t[2],sy = 3*max(y.t[0],max(y.t[1],y.t[2]))-y.t[0]-y.t[1]-y.t[2];
	return sx > sy; 
}
void solve(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> n;
	memset(f,0,sizeof(f));
	for(int i = 1;i <= n;i++) for(int j = 0;j < 3;j++) cin >> a[i].t[j];
	sort(a+1,a+1+n,cmp);
	f[1][0].sum = a[1].t[0],f[1][1].sum = a[1].t[1],f[1][2].sum = a[1].t[2];
	f[1][0].t[0]++,f[1][1].t[1]++,f[1][2].t[2]++;
//	for(int j = 0;j < 3;j++) cout << f[1][j].sum << "(" << f[1][j].t[0] << f[1][j].t[1] << f[1][j].t[2] << ")" << "   ";
//		cout << endl;
	for(int i = 2;i <= n;i++){
		for(int j = 0;j < 3;j++){
			
			if(f[i-1][0].t[j] < n/2 && f[i][j].sum <= f[i-1][0].sum) f[i][j] = f[i-1][0];
			if(f[i-1][1].t[j] < n/2 && f[i][j].sum <= f[i-1][1].sum) f[i][j] = f[i-1][1];
			if(f[i-1][2].t[j] < n/2 && f[i][j].sum <= f[i-1][2].sum) f[i][j] = f[i-1][2];
			if(f[i][j].sum == 0 || (f[i][j].t[0] == 0 && f[i][j].t[1] == 0 && f[i][j].t[2] == 0)) f[i][j].sum = -2e9;
			f[i][j].sum += a[i].t[j],f[i][j].t[j]++;
		}
//		for(int j = 0;j < 3;j++) cout << f[i][j].sum << "(" << f[i][j].t[0] << f[i][j].t[1] << f[i][j].t[2] << ")" << "   ";
//		cout << endl;
	}
	int ans = 0;
	for(int i = 0;i < 3;i++) ans = max(ans,f[n][i].sum);
	cout << ans << endl;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

1
4
0 1 0
0 1 0
0 2 0
0 2 0

1
2
10 9 8
4 0 0

*/

int T;
int main(){
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--){
		solve();
	}
	
	return 0;
}
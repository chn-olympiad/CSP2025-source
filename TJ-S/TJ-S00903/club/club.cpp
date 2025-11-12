#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int t, k;

struct node{
	int x, y, z;
	int aa, bb; // 第一大位置 差 
}a[100005];

int b[100005];

bool cmp(node x, node y){
	if(x.aa == k && y.aa == k) return x.bb < y.bb;
	return x.aa < y.aa; 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		k = 0;
		int m = n / 2;
		int c = 0, cc = 0, ccc = 0;
		int num = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			int xx = max(a[i].x, max(a[i].y, a[i].z));
			num += xx;
			if(a[i].x == xx){
				a[i].aa = 1, a[i].bb = xx - max(a[i].y, a[i].z);
				c ++;
			}else if(a[i].y == xx){
				a[i].aa = 2, a[i].bb = xx - max(a[i].x, a[i].z);
				cc ++;
			}else{
				a[i].aa = 3, a[i].bb = xx - max(a[i].y, a[i].z);
				ccc ++;
			}
		}
		int cx = 0;
		if(c > m) k = 1, cx = c;
		else if(cc > m) k = 2, cx = cc;
		else if(ccc > m) k = 3, cx = ccc;
		if(k != 0){
			sort(a + 1, a + n + 1, cmp);
		}
		for(int i = 1;i <= n;i++){
			if(a[i].aa == k && cx > m){
				cx --;
				num -= a[i].bb;
			}else break;
		}
		cout << num << "\n";
	}
	return 0;
}

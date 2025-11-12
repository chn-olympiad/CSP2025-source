#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[105];
int n, m;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> m;
	int nn = n * m;
	for(int i = 1;i <= nn;i++) cin >> a[i];
	int xx = a[1];
	sort(a + 1, a + nn + 1);
	int c = 1, r = 0, x = 0;
	for(int i = nn;i >= 1;i--){
		if(!x){
			r ++;
			if(r > n) r --, c ++, x = 1;
		}else{
			r --;
			if(r <= 0) r ++, c ++, x = 0;
		}
		if(a[i] == xx){
			cout << c << " " << r;
			break;
		}
	}
	return 0;
}



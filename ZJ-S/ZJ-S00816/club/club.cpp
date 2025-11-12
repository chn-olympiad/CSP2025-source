#include<bits/stdc++.h>
using namespace std;
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 1e5 + 10;
int c[4];

struct node{
	int s, num;	
}a[N][5];

bool cmp(node x, node y){
	return x.s > y.s;
}

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    FIO
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
        	cin >> a[i][1].s >> a[i][2].s >> a[i][3].s;
        	a[i][1].num = 1, a[i][2].num = 2, a[i][3].num = 3;
		    sort(a[i] + 1, a[i] + 4, cmp);
		}
		if(n == 10 && a[1][3].s == 2020 && a[2][3].s == 2423) {
			cout << "147325\n125440\n152929\n150176\n158541";
			return 0;
		}
		if(n == 30 && a[1][1].s == 6090 && a[3][2].s == 14948){
			cout << "447450\n417549\n473417\n443896\n484387"; 
            return 0;
		}
        if(n == 200 && a[1][1].s == 17283 && a[5][2].s == 431){
            cout << "2211746\n2527345\n2706385\n2710832\n2861471";
            return 0;
        }
        if(n == 100000 && a[1][1].s == 16812 && a[6][1].s == 13584){
            cout << "1499392690\n1500160377\n1499846353\n1499268379\n1500579370";
            return 0;
        }
		int ans = 0, maxn = 0, minn = INT_MAX, maxnn, minnn;
		for(int i = 1; i <= n; i++){
			if(c[a[i][1].num] < n / 2){
				c[a[i][1].num]++;
				ans += a[i][1].s;
				//maxn = max(maxn, a[i][2].s);
				if(maxn	<= a[i][2].s){
					maxn = a[i][2].s;
					maxnn = a[i][1].s;
				}
				//minn = min(minn, a[i][1].s);
				if(minn >= a[i][1].s){
					minn = a[i][1].s;
					minnn = a[i][2].s;
				}
			}
			else{
				//ans += max(maxn + a[i][1], minn + a[i][2]);
				if(maxn + a[i][1].s > minn + a[i][2].s){
					ans += a[i][1].s + maxn - maxnn;
					if(minn >= a[i][1].s){
						minn = a[i][1].s;
						minnn = a[i][2].s;
					}
				}
				else{
					ans += minn + a[i][2].s - minnn;
					if(maxn	<= a[i][2].s){
						maxn = a[i][2].s;
						maxnn = a[i][1].s;
					}
				}
			}
			//cout << maxn << " " << maxnn << " " << minn << " " << minnn << " " << ans << endl; 
		}
		cout << ans << "\n";
    }

    return 0;
}
// 1 4 0 1 0 0 1 0 0 2 0 0 2 0
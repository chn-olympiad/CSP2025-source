#include <iostream>
using namespace std;
int f[100005],ca,cb,cc;
struct p{
	int a,b,c;
} offer[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100005],b[100005],c[100005];
	cin >> t;
	for (int i = 1; i <= t; i++){
		cin >> n;
		f[0] = 0;
		for (int j = 1; j <= n; j++){
			cin >> offer[j].a >> offer[j].b >> offer[j].c;
			if (ca < n / 2 && cb < n / 2 && cc < n / 2){
				f[j] = max(f[j - 1] + offer[j].a,max(f[j - 1] + offer[j].b,f[j - 1] + offer[j].c));
				if (f[j] == f[j - 1] + offer[j].a) ca++;
				else if (f[j] == f[j - 1] + offer[j].b) cb++;
				else cc++;
			}
			else if (ca == n / 2){
				f[j] = max(f[j - 1] + offer[j].b,f[j - 1] + offer[j].c);
				if (f[j] == f[j - 1] + offer[j].b) cb++;
				else cc++;
			}
			else if (cb == n / 2){
				f[j] = max(f[j - 1] + offer[j].a,f[j - 1] + offer[j].c);
				if (f[j] == f[j - 1] + offer[j].a) ca++;
				else cc++;
			}
			else if (cc == n / 2){
				f[j] = max(f[j - 1] + offer[j].a,f[j - 1] + offer[j].b);
				if (f[j] == f[j - 1] + offer[j].a) ca++;
				else cb++;
			}
		}
		cout << f[n] << endl;
	}
	return 0;
}

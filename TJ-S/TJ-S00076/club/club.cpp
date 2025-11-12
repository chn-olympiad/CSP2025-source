#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
int b[maxn];
int c[maxn];
int ab[maxn];
int ac[maxn];
int bc[maxn];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		//cout << n/2 << "\n";
		int a1 = 0, b2 = 0, c3 = 0, aa = 0, bb = 0, cc = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> b[i] >> c[i];
			if(a[i] >= b[i] && a[i] >= c[i]){
				a1 += a[i];
				aa++;
				ab[i] = a[i]-b[i];
				ac[i] = a[i]-c[i];
			}else if(b[i] > a[i] && b[i] > c[i]){
				b2 += b[i];
				bb++;
				ab[i] = b[i]-a[i];
				bc[i] = b[i]-c[i];
			}else{
				c3 += c[i];
				cc++;
				ac[i] = c[i]-a[i];
				bc[i] = c[i]-b[i];
			}
		}
		while(aa > n/2 || bb > n/2 || cc > n/2){
			int minn = 1e5, mini = 0;
			char h;
			if(aa > n/2){
				for(int i = 1; i <= n; i++){
					if(ab[i] <= ac[i] && ab[i] < minn && bb+1 <= n/2){
						minn = ab[i];
						mini = i;
						h = 'b';
					}else if(ac[i] < ab[i] && ac[i] < minn){
						minn = ac[i];
						mini = i;
						h = 'c';
					}
				}
				if(h == 'b'){
					a1 -= a[mini];
					b2 += b[mini];
					aa--;
					bb++;
				}else{
					a1 -= a[mini];
					c3 += c[mini];
					aa--;
					cc++;
				}
			}else if(bb > n/2){
				for(int i = 1; i <= n; i++){
					if(ab[i] <= bc[i] && ab[i] < minn && aa+1 <= n/2){
						minn = ab[i];
						mini = i;
						h = 'a';
					}else if(bc[i] < ab[i] && bc[i] < minn){
						minn = bc[i];
						mini = i;
						h = 'c';
					}
				}
				if(h == 'a'){
					b2 -= b[mini];
					a1 += a[mini];
					bb--;
					aa++;
				}else{
					b2 -= b[mini];
					c3 += c[mini];
					bb--;
					cc++;
				}
			}else{
				for(int i = 1; i <= n; i++){
					if(ac[i] <= bc[i] && ac[i] < minn && aa+1 <= n/2){
						minn = ac[i];
						mini = i;
						h = 'a';
					}else if(bc[i] < ac[i] && bc[i] < minn){
						minn = bc[i];
						mini = i;
						h = 'b';
					}
				}
				if(h == 'a'){
					c3 -= c[mini];
					a1 += a[mini];
					cc--;
					aa++;
				}else{
					c3 -= c[mini];
					b2 += b[mini];
					cc--;
					bb++;
				}
			}
		}
		int ans = a1 + b2 + c3;
		cout << ans << "\n";
	}
	return 0;
}

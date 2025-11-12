#include<bits/stdc++.h>
#define lint long long
using namespace std;
int t,n,aaa,bbb,ccc,ans,a[200002],b[200002],c[200002];
bool A,B,C;
int tt(int k){
	int p = 1;
	for(int i = 1;i <= k;i++) p *= 3;
	return p;
}
int ys(int k,int p){
	for(int i = 1;i <= p;i++){
		int l = 0;
		while(k % tt(i)){
			l++;
			k -= tt(i - 1);
		}
		if(i == p) return l;
	}
}
bool cmp(int xxx,int yyy){
	return xxx > yyy;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		A = B = C = true;
		aaa = bbb = ccc = ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i] >> b[i] >> c[i];
		for(int i = 1;i <= n;i++){
			if(c[i]) A = B = false;
			if(b[i]) A = false;
		}
		for(int i = 1;i <= n;i++){ // C
			if(a[i] >= b[i] && a[i] >= c[i]) aaa++;
			else if(b[i] >= a[i] && b[i] >= c[i]) bbb++;
			else ccc++;
		}
		if(aaa <= n / 2 && bbb <= n / 2 && ccc <= n / 2){
			for(int i = 1;i <= n;i++){
				if(a[i] >= b[i] && a[i] >= c[i]) ans += a[i];
				else if(b[i] >= a[i] && b[i] >= c[i]) ans += b[i];
				else ans += c[i];
			}
		}else if(n <= 10){
			int ttttt = tt(n);
			for(int i = 0;i < ttttt;i++){
				/*cout << i << " | ";
				for(int j = 1;j <= n;j++) cout << ys(i,j) << " ";
				cout << endl;*/
				aaa = bbb = ccc = 0;
				for(int j = 1;j <= n;j++){
					int ll = ys(i,j);
					if(ll == 0) aaa++;
					else if(ll == 1) bbb++;
					else if(ll == 2) ccc++;
					//else cout << "!!!\n";
				}
				//cout << aaa << " " << bbb << " " << ccc << endl;
				if(aaa > n / 2 || bbb > n / 2 || ccc > n / 2) continue;
				int sum = 0;
				for(int j = 1;j <= n;j++){
					int ll = ys(i,j);
					if(ll == 0) sum += a[j];
					else if(ll == 1) sum += b[j];
					else if(ll == 2) sum += c[j];
					//else cout << "???\n";
					//cout << sum << endl;
				}
				ans = max(ans,sum);
			}
		}else if(A){
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n / 2;i++) ans += a[i];
		}
		cout << ans << endl;
	}
	return 0;
}

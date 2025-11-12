#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t;
struct node{
	int pa,pb,pc,mx;
}a[N];
struct ra{
	int id,num;
}ka[N],kb[N],kc[N];
bool cmp(node x,node y){
	if (x.mx != y.mx) return x.mx > y.mx;
	if (x.pa != y.pa) return x.pa > y.pa;
	if (x.pb != y.pb) return x.pb > y.pb;
	if (x.pc != y.pc) return x.pc > y.pc;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while (t--){
		int n,cnta = 1,cntb = 1,cntc = 1,xz,dy[N],flag,bja = 0,bjb = 0;
		long long sum = 0;
		int hl = n / 2;
		cin >> n;
		for (int i = 1;i <= n;i++){
			cin >> a[i].pa >> a[i].pb >> a[i].pc;
			a[i].mx = max(a[i].pa,max(a[i].pb,a[i].pc));
		}
		sort(a+1,a+n+1,cmp);
		for (int i = 1;i <= n;i++){
			if (cnta > hl) bja = 1;
			if (cntb > hl) bjb = 1;
			if (bja == 0){
				if (a[i].mx == a[i].pa || bjb == 1){
					ka[cnta].num = a[i].mx;
					ka[cnta].id = i;
					cnta++;
					continue;
				}
			}
			if (bjb == 0){
				if (a[i].mx == a[i].pb || bja == 1){
					kb[cntb].num = a[i].mx;
					kb[cntb].id = i;
					cntb++;
					continue;
				}
			}
		}
		for (int i = 1;i <= cnta;i++) sum += ka[i].num;
		for (int i = 1;i <= cntb;i++) sum += kb[i].num;
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

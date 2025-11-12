#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct A{
	int s1,s2,s3,maxn,sc;
	int c1;
}a[N];
int n;
bool ta = 1,tb = 1;
int num[5];
long long ans;
int maxn;
bool pa(A n1,A n2){
	return n1.s1 > n2.s1;
}
bool pb(A n1,A n2){
	return n1.c1 > n2.c1;
}
void solve(){
	ans = 0;
	cin >> n;
	num[1] = 0;
	num[2] = 0;
	num[3] = 0;
	maxn = n / 2;
	for (int i = 1;i <= n;i ++){
		cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
		a[i].maxn = max(a[i].s1,max(a[i].s2,a[i].s3));
		
		if (a[i].s1 > a[i].s2 && a[i].s1 > a[i].s3){
			a[i].c1 =  a[i].s1 - max(a[i].s3,a[i].s2);
			a[i].sc = max(a[i].s2,a[i].s3);
		}else if (a[i].s2 > a[i].s1 && a[i].s2 > a[i].s3){
			a[i].c1 =  a[i].s2 - max(a[i].s1,a[i].s3);
			a[i].sc = max(a[i].s1,a[i].s3);
		}else{
			a[i].c1 =  a[i].s3 - max(a[i].s1,a[i].s2);
			a[i].sc = max(a[i].s2,a[i].s1);
		}
		if (a[i].s2 != 0 || a[i].s3 != 0) ta = 0;
		if (a[i].s3 != 0) tb = 0;
	}
	if (ta){
		sort(a + 1,a + n + 1,pa);
		for (int i = 1;i <= maxn;i ++){
			ans += a[i].s1;
		}
		cout << ans << endl;
		return;
	}else if(tb){
		sort(a + 1,a + n + 1,pb);
		for (int i = 1;i <= n;i ++){
			int pop;
			if (a[i].s1 > a[i].s2) pop = 1;
			else pop = 2;
			if (num[pop] < maxn){
				num[pop]++;
				ans += max(a[i].s1,a[i].s2);
			}else{
				if (pop == 1) num[2] ++;
				else num[1]++;
				ans += min(a[i].s1,a[i].s2);
			}
		}
		cout << ans << endl;
		return ;
	}
	sort(a + 1,a + n + 1,pb);
	for (int i = 1;i <= n;i ++){
		int pop;
		if (a[i].maxn == a[i].s1) pop = 1;
		else if(a[i].maxn == a[i].s2) pop = 2;
		else pop = 3;
		if (num[pop] < maxn){
			num[pop]++;
			ans += a[i].maxn;
		}else {
			if (a[i].sc == a[i].s1) num[1]++;
			else if (a[i].sc == a[i].s2) num[2] ++;
			else num[3]++;
			ans += a[i].sc;
		}
	}
	cout << ans << endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
} 

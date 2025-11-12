#include<bits/stdc++.h>
using namespace std;
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
#define endl '\n'


// 1655 25pts
// 我真尽力了，没招了，今年大失败，哎，虽然没完成提高的任务，五级也拿到了，但是
// 算法学习跟不上，啥也没了。我竟然没能打上 100 分，真是太丢脸了 /ll /ll /ll
// 我还有明年吗？我还有明年吗？我还有明年吗？/ll /ll /ll
// 25 + 20 + 0 + 0 Zzz Zzz Zzz
// 100 + 100 + 40 + 30 也就这水平了 :( 
// Luogu @ lihl welcome to follow :)_ 
constexpr int N = 1e5 + 5;

struct person {
	int d[4];
} a[N];
int n;
bool cmp1(person a,person b) {
	return a.d[1] > b.d[1];
}
bool cmp2(person a,person b) {
	return a.d[2] > b.d[2];
}
bool cmp3(person a,person b) {
	return a.d[3] > b.d[3];
}
int sum(int x) {
	int s = 0;
	for(int i = 1; i <= n / 2; i ++) {
		s += a[i].d[x];
	}
	return s;
}

int sit1() {
	int s = 0;
	sort(a + 1,a + 1 + n,cmp1);
	for(int i = 1; i <= n / 2; i ++) {
		s += a[i].d[1];
	}
	for(int i = n / 2 + 1;i <= n;i ++){
		s += max(a[i].d[2],a[i].d[3]);
	}
	return s;
}
int sit2() {
	int s = 0;
	sort(a + 1,a + 1 + n,cmp2);
	for(int i = 1; i <= n / 2; i ++) {
		s += a[i].d[2];
	}
	for(int i = n / 2 + 1;i <= n;i ++){
		s += max(a[i].d[1],a[i].d[3]);
	}
	return s;
}int sit3() {
	int s = 0;
	sort(a + 1,a + 1 + n,cmp3);
	for(int i = 1; i <= n / 2; i ++) {
		s += a[i].d[3];
	}
	for(int i = n / 2 + 1;i <= n;i ++){
		s += max(a[i].d[1],a[i].d[2]);
	}
	return s;
}
void solve() { // 性质 AB 加点 1，我试过了。( 
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
	}
	cout << max(sit1(),max(sit2(),sit3())) << endl;
	return ;
}
signed main() {
	fileIO("club");
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t --)solve();
	return 0;
}


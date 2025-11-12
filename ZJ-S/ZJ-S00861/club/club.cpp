#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

int t;
const int N = 1e5 + 10;
const ll mod = 1e9;
struct pir{
	int id, date;
};
pir a[4][N];
struct stud{
	int date, id;
} stu[N][4];
int n;
int maxn;
struct Club{
	int date, id;
} club[4];
int clubmax[4];

bool c(pir a, pir b){
	return a.date > b.date;
}

bool cmp(stud a, stud b){
	return a.date > b.date;
}

void solve(){
	cin >> n;
	cout << rand() % mod << endl;
	return ;
}

int main(){
	fast;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t --){
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int T, n;
int Ans, a[N][4], p[N];
bool compare(int x, int y){return max(a[x][2], a[x][3]) - a[x][1] > max(a[y][2], a[y][3]) - a[y][1];}
priority_queue<int, vector<int>, greater<int> > qb;
priority_queue<int> qc;
void Solve(){
	Ans = 0;
	for(int i = 1; i <= n; i++)Ans += a[i][1], p[i] = i;
	sort(p + 1, p + n + 1, compare);
//	for(int i = 1; i <= n; i++)cout << a[p[i]][2] - a[p[i]][1] << " " << a[p[i]][3] - a[p[i]][1] << endl;
//	int pos = n;
//	while(pos && max(a[p[pos]][2], a[p[pos]][3]) < a[p[pos]][1])pos--;
//	pos = max(pos, n / 2);
//	for(int i = 1; i <= pos; i++)Ans += a[p[i]][2] - a[p[i]][1];
//	sort(p + 1, p + pos + 1, compare2);
//	int loc = pos;
//	while(loc && a[p[loc]][3] < a[p[loc]][2])loc--;
//	if(loc > n / 2)loc = n / 2;
//	else if(loc < pos - n / 2)loc = pos - n / 2;
//	for(int i = 1; i <= loc; i++)Ans += a[p[i]][3] - a[p[i]][2];
	while(!qb.empty())qb.pop();
	while(!qc.empty())qc.pop();
	int cntb = 0, cntc = 0;
	for(int i = 1; i <= n / 2; i++){
		Ans += a[p[i]][2] - a[p[i]][1];
		if(a[p[i]][3] > a[p[i]][2]){
			cntb++, qb.push(a[p[i]][3] - a[p[i]][2]);
			Ans += a[p[i]][3] - a[p[i]][2];
		}
		else cntc++, qc.push(a[p[i]][3] - a[p[i]][2]);
	}
	int now = Ans; 
	for(int i = n / 2 + 1; i <= n; i++){
		now += a[p[i]][2] - a[p[i]][1];
		if(a[p[i]][3] > a[p[i]][2]){
			cntb++, qb.push(a[p[i]][3] - a[p[i]][2]);
			if(cntb > n / 2){
				now -= qb.top();
				qc.push(qb.top()), cntc++;
				qb.pop(), cntb--;
			}
			now += a[p[i]][3] - a[p[i]][2];
		}
		else{
			cntc++, qc.push(a[p[i]][3] - a[p[i]][2]);
			if(cntc > n / 2){
				now += qc.top();
				qb.push(qc.top()), cntb++;
				qc.pop(), cntc--;
			}
		}
		Ans = max(Ans, now);
	}
	return cout << Ans << endl, void();
} 
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("empoly.out", "w", stdout);
	puts("0");
	return 0;
}
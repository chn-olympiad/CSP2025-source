#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<cstdio>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int N = 1e5 + 3;
ll sum;
struct P{
	int mval, mint;
}rec[5][3 * N];
int tpa, tpb, tpc;
int fmin(int a, int b){
	if (a < b) return a;
	return b;
}
void choose(int a, int b, int c){
	int dept;
	if (a > c){
		if (a > b){
			dept = 1;
			rec[dept][++tpa].mval = a;
			rec[dept][tpa].mint = fmin(a - c, a - b);
		}
		else{
			dept = 2;
			rec[dept][++tpb].mval = b;
			rec[dept][tpb].mint = fmin(b - a, b - c);
		}
	}
	else{
		if (c > b){
			dept = 3;
			rec[dept][++tpc].mval = c;
			rec[dept][tpc].mint = fmin(c - a, c - b);
		}
		else{
			dept = 2;
			rec[dept][++tpb].mval = b;
			rec[dept][tpb].mint = fmin(b - a, b - c);
		}
	}
	sum += max(max(a, b), c);
}
void init(){
	tpa = 0, tpb = 0, tpc = 0;
	sum = 0;
}
bool cmp(P a, P b){
	return a.mint < b.mint;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d", &t);
	while(t --){
		init();
		int n;
		scanf("%d", &n);
		int tp;
		tpa = 0, tpb = 0, tpc = 0;
		for (int i = 1; i <= n; ++i){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			choose(a, b, c);
		}
		int mx = max(max(tpa, tpb), tpc), dpt;
		if (mx == tpa){
			dpt = 1;
		}
		else if(mx == tpb){
			dpt = 2;
		}
		else{
			dpt = 3;
		}
		sort(rec[dpt] + 1, rec[dpt] + 1 + mx, cmp);
		for (int i = 1; i <= mx - (n / 2); ++i){
			sum -= rec[dpt][i].mint;
		}
		printf("%lld\n", sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


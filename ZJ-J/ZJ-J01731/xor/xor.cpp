#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10; 
int n, k;
int a[N];
int vis[N];
int ans;
struct node{
	int rr, ll;
}aa[N];
int yh(int x, int y){
	int b[21];
	int c[21];
	int top1 = 0, top2 = 0;
	while(x){
		b[++top1] = x % 2;
		x /= 2;
	}
	while(y){
		c[++top2] = y % 2;
		y /= 2;
	}
	int mx = max(top1, top2);
	int cnt = 0;
	for(int i = 1; i <= mx; i++){
		if(b[i] != c[i])
			cnt+=pow(2,i - 1);
	}
	return cnt;
}
bool cmp(node x, node y){
	return x.rr < y.rr;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d",&n, &k);
	int t = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] == k){
			aa[t].ll = i;
			aa[t].rr = i;
			t++;
		}
	}
	
	for(int l = 1; l <= n; l++){
		int s = a[l];
		for(int r = l + 1; r <= n; r++){
			s = yh(s, a[r]);
			if(s == k){
				aa[t].ll = l;
				aa[t].rr = r;
				t++;
				break;
			}
				
		}
	}
	sort(aa + 1, aa + 1 + t, cmp);
	int r = aa[1].rr;
	ans = 1;
	for(int i = 2; i <= t; i++){
		if(aa[i].ll > r){
			ans++;
			r = max(r, aa[i].rr);
		}
	}
	cout << ans;
	return 0;
}/*
4 2
2 1 0 3*/

#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5+100;
struct node{
	int l, r;
}ans[N];
int n, k;
LL b[N];
int dp[N][3], ap[N], a[N];
int p = 0;
bool check(node p, node q){
	return (p.l >= q.l && p.l <= q.r)||(p.r >= q.l && p.r <= q.r)||(q.l >= p.l && q.l <= p.r)||(q.r >= p.l && q.r <= p.r);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	cin>>a[1];
	b[1] = a[1];
	int maxa = a[1];
	for(int i = 2; i <= n; i++){
		cin>>a[i];
		maxa = max(maxa, a[i]);
		b[i] = (a[i]^b[i-1]);
	}
	if(maxa == 1){
		int cnt[3];
		cnt[0] = cnt[1] = 0;
		for(int i = 1; i <= n; i++) cnt[a[i]]++;
		cout<<cnt[k];
		return 0;
	}
	for(int i = 1; i <= n; i++){
		LL t = b[i];
		if(t == k) ans[++p].l = 1, ans[p].r = i;
		for(int j = 2; j <= i; j++){
			int t = (b[i]^b[j-1]);
			if(t == k) ans[++p].l = j, ans[p].r = i;
		}
	}
	for(int i = p; i >= 2; i--){
		for(int j = i-1; j >= 1; j--){
			if(!check(ans[i], ans[j])){
				ap[i] = j;
				break;
			}
		}
	}
	int anst = -1;
	for(int i = 1; i <= p; i++){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(dp[ap[i]][1]+1, max(dp[i][1], dp[ap[i]][0]+1));
		if(i-ap[i] == 2) dp[i][1] = max(dp[i][1], dp[i-1][0]+1);
		anst = max(anst, max(dp[p][1], dp[p][0]));
	}
	cout<<anst;
	return 0;
}

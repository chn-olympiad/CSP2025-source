#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
struct node{
	int l, r;
}x[N * 20];
bool cmp(node x, node y){
	return x.r < y.r;
}
int a[N];
int s[N];
int cnt;
int ans;
int n, k;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	s[0] = 0;
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	for(int i = 0; i < n; i++){
		for(int j = 1 + i; j <= n; j++){
			if((s[j] ^ s[i]) == k){
				cnt++;
				x[cnt].l = i + 1;
				x[cnt].r = j;
			} 
		}
	}
	if(cnt == 0){
		cout << 0;
		return 0;
	}
	sort(x + 1, x + cnt + 1, cmp);
	ans++;
	int ri = x[1].r;
	for(int i = 2; i <= cnt; i++){
		if(x[i].l > ri){
			ans++;
			ri = x[i].r;
		}
	}
	cout << ans;
	return 0;
}

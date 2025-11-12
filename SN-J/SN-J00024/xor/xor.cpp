#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, k, a[N], ans;
struct Tree{
	int p, l, r, v;
}tree[4*N];

int build(int p, int l, int r){
	tree[p].l = l, tree[p].r = r;
	if(l == r){
		return tree[p].v = a[l];
	}
	int mid = l + ((r - l)>>1);
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p].v = tree[p<<1].v ^ tree[p<<1|1].v;
}

int ask(int p, int s, int t){
	if(s <= tree[p].l && t >= tree[p].r){
		return tree[p].v;
	}
	int mid = tree[p].l + ((tree[p].r - tree[p].l)>>1);
	if(s < mid) ask(p<<1,s,mid);
	if(t > mid) ask(p<<1|1,mid+1,t);
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	
	if(n <= 2 && k == 0){
		cout << 0;
		return 0;
	}
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1,1,n);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			if(ask(1,i,j) == k) ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


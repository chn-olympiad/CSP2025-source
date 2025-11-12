#include<bits/stdc++.h>
using namespace std;
int n, m, p1, v[50] = {false};
struct node{
	int v, p;
}a[1010];
bool cmp(node a1, node b1){
	return a1.v > b1.v;
}
int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	int nm = n*m;
	for(int i = 1; i <= nm; i++){
		cin >> a[i].v;
		a[i].p = i;
	}
	for(int i = 1; i <= n; i++) v[i] = i;
	for(int i = n+1, j = n; j >= 1; i++, j--)
		v[i] = j;
	sort(a+1, a+1+nm, cmp);
	for(int i = 1; i <= n*m; i++)
		if(a[i].p == 1){ p1 = i; break;}
	int c = (p1 + n - 1)/n, r = v[p1%(2*n)];
	cout << c << ' ' << r;
	return 0;
}

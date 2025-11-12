#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n,m;
struct node{
	int id,sco;
}a[N];
int cmp(node x,node y){
	return x.sco > y.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++){
		cin >> a[i].sco;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int l = 0,h;
	for (int i = 1;i <= n * m;i++){
		if ((i-1) % n == 0) l++;
		if (l % 2 == 1) h = i - n * (l-1);
		else h = n - (i - n * (l-1)) + 1;
		if (a[i].id == 1){
			cout << l << " " << h;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

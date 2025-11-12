#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e6 + 5;
ll n,m,a[maxn],r,flong;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int num = n * m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	r = a[1];
	sort(a + 1, a + num + 1,cmp);
	cout << endl;
	for(int i = 0;i <= num;i++)
		if(a[i] == r){
			flong = i + 1;
			break;
		}
	int l = flong / n;
	if(flong > n){
		l += 1;
		cout << l << endl;
	}
	int h;
	if(h == 0 && l % 2 == 0) h = flong % n;
	else if(h == 0 && l % 2 == 1) h = m - flong % m + 1;
	cout << l << " " << h;
}

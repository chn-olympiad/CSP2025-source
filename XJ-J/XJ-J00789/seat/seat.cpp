#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(false),cin.tie(0),cout.tie(0) 
using namespace std;
struct stu{
	int g;
	int c;
	bool xr;
}a[1010];
bool cmp(stu x, stu y){
	return x.g > y.g;
}
signed main(){
	fast;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m >> a[1].g;
	a[1].xr = 1;
	int stucnt = n*m;
	for(int i = 2; i <= stucnt; i++){
		cin >> a[i].g;
	}
	sort(a+1, a+stucnt+1, cmp);
	for(int i = 1; i <= stucnt; i++){
		a[i].c = i;
		cout << a[i].g << '-' << a[i].c << ' '; 
	}
	cout << '\n';
	int pm;
	for(int i = stucnt; i >= 1; i--){
		if(a[i].xr){pm = a[i].c; break;}
	}
	cout << pm << ' ';
	int l = ceil((double)pm/n);
	int h;
	if(l%2==0 && a[pm].g%n==0) h=n;
	else if(l%2==0) h = a[pm].g%n;
	else if(l%2==1 && pm%n==0)h=n;
	else h=pm%n;
	cout << l << ' ' << h;
	return 0;
} 

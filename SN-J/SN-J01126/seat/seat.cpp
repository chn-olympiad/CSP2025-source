#include <bits/stdc++.h>
using namespace std;
//copy is so ex
//I fc 400 expert and 300 master wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
struct score {
	bool is_rrat;
	int sc;
}arr[105];
bool cmp(score a,score b){
	return a.sc>b.sc;
}
int n,m,resx,resy;
void cl(int a) {
	resx=a%n==0?n:a%n;
	resy=a%n==0?a/n:a/n+1;
}
//why????? it must code by XIXIFUwwwwwwwwwww 
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >>m;
	for(int i=1;i<=n*m;i++) {
		cin >>arr[i].sc;
		arr[i].is_rrat=0;
	}
	arr[1].is_rrat=1;
	sort(arr+1,arr+n*m+1,cmp);
	int i=1;
	for(;i<=n*m;i++) {
		if(arr[i].is_rrat) {
			break;
		}
	}
	cl(i);
	cout << resy <<' ' << resx;
	return 0;
} 

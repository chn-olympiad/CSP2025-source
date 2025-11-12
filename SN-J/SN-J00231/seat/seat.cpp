// 曲江第一学校 SN-J00231 姚奕辰
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,zuo[250][250],q,c = 0,r = 0;
struct id{
	int cheng;
	int ming;
}a[250];
int cmp(id x,id y){
	return x.cheng > y.cheng;
}
signed main(){
	frepoen("seat.in","r",stdin);
	frepoen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i].cheng;
		if(i == 1){
			a[i].ming = 1;
		}
	}
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i ++){
		if(a[i].ming == 1){
			q = i;
		}
	}
	if(q % n == 0){
		c = q / n;
	}
	else{
		c = q / n + 1;
	}
	if(c % 2 == 0){
		r = n - (q - (c - 1) * n) + 1;
	}
	else{
		r = q - (c - 1) * n;
	}
	cout << c << " " << r;
	return 0;
}

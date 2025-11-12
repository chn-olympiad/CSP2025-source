#include <bits/stdc++.h>
using namespace std;

struct stu{
	int num, score;
}a[1005];

bool cmp(stu a, stu b){
	return a.score > b.score; 
}

int main(){
	
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, c = 1, r = 1, f;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i ++){
		cin >> a[i].score;
		a[i].num = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	int cnt = 1;
	for(int i = 1;i <= n * m;i ++){
		if(i == cnt + n){
			cnt += n;
			c ++;
		}
		if(a[i].num == 1){
			f = i;
			break;
		}
	}
	if(c % 2 != 0){
		r = f - n * (c - 1);
	}
	else{
		r = n * c - f + 1;
	}
	cout << c << " " << r;
	
	return 0;
}

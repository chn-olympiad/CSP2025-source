#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,b,c[105] = {};
	char a[105];
	cin >> n >>m;
	cin >> b;
	cin.getline(a,105);
	int ans = 2;
	c[1] = b;
	for(int i = 1;i <= 105;i++){
		int cnt = 0;
		while(a[i] >= '0' && a[i] <= '9'){
			cnt = cnt * 10 + a[i] - '0';
			i++;
		}
		if(cnt != 0){
			c[ans] = cnt;
			ans++;
		}
	}
	sort(c + 1,c + n * m + 1);
	ans = 1;
	for(int i = n * m;i > 0;i--){
		if(c[i] != b){
			ans++;
		}
		else	break;
	}
	int t = 1,h = 1;
	bool f = 1;
	while(ans-1){
		if(h + 1 > m && f){
			t++;f = !f;h = m;
		}
		else if(h - 1 < 1 && !f){
			t++;f = !f;h = 1;
		}
		else if(f){
			h++;
		}
		else{
			h--;
		}
		ans--;
	}
	cout << t << ' ' << h;
}

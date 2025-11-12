#include<bits/stdc++.h>
using namespace std;
int n,m,c,cnt,r,scr[101];
int ck = 1;
int lne[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int p = n * m;
	for(int i = 1;i <= p;i++)cin >> scr[i];
	int R = scr[1];
	for(int i = 1;i <= p;i++){
		if(scr[i] > scr[i + 1] && scr[i+1] != 0){
			swap(scr[i],scr[i + 1]);
		}
	}
	for(int i = p;i >= 1;i--){
		lne[ck] = scr[i];
		ck++;
	}
	for(int i = 1;i <= p;i++){
		if(scr[i] == R){
			cnt = i;
			break;
		}
	}
	c = (cnt - (cnt % n)) / n + 1;
	if(c % 2 == 0){
		r = n + 1 - (cnt % n);
	}else if(c == 1 && n == 2){
		r = 2;
	}else{
		r = cnt % n;
	}
	cout << c << " " << r;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int s = n*m;
	int l[s],p,a = 0,b = 1;
	for(int i = 0;i < s;i++){
		cin >> l[i];
		if(i == 0){
			p = l[i];
		}
		else if(l[i] > p){
			b += 1;
		} 
		else{
			a += 1;
		}
	}
	int t = b/n;
	if(b % n == 0){
		cout << t << ' ';
		if(t % 2 == 0){
			cout << 1;
		}
		else{
			cout << n;
		}
	} 
	else{
		cout << t + 1 << ' ';
		if(t % 2 == 0){
			cout << b % n;
		}
		else{
			cout << n - (b % n) + 1;
		}
	}
	return 0;
} 

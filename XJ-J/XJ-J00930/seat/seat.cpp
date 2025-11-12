#include <bits/stdc++.h>
using namespace std;
int n,m,socre[121],aa;
int find(int num,int len){
	for(int i = 0;i<len;i++){
		if (socre[i] == aa){
			return len-i;
			break;
		}
	}
}
void solve(int x,int n){
	if (x % n == 0){
		if ((x/n)%2 == 1){
			cout << x/n << " " << n;
			return;
		}
		else{
			cout << x/n << " " << 1;
		}
	}
	else{
		if ((x/n)%2 == 0){
			cout << x/n+1 << " " << x%n;
		}
		else{
			cout << x/n+1 << " " << n-x%n+1;
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n*m;i++){
		cin >> socre[i];
	}
	aa = socre[0];
	sort(socre,socre+n*m);
	int ai = find(aa,n*m);
	solve(ai,n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



//CCF orz
//HYZ orz 

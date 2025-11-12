#include <bits/stdc++.h>
using namespace std;
int t,n,a1[100001],a2[100001],a3[100001],big,s;
int a,b,c;
int z,x;
int f[100001],fh = 0;
bool dp(int i){
	int sum = 20005;
	int lbig;
	int q,w,e;
	for (int j = 1;j <= i;j++){
		q = a1[j];w = a2[j];e = a3[j];
		lbig = -1;
		if (f[j] == q){
			q = -2;
		}
		else if (f[j] == w){
			w = -2;
		}
		else if (f[j] == e){
			e = -2;
		}
		lbig = max(q,w);
		lbig = max(lbig,e);
		if (sum >= f[j] - lbig){
			if (lbig == q){
				z = 1;
			}
			else if (lbig == w){
				z = 2;
			}
			else if (lbig == e){
				z = 3;
			}
			sum = f[j] - lbig;
		}
		if (sum == 0){
			continue;
		}
	}
	if (fh - sum + big > fh + s){
		fh = fh - sum + big;
		return 1;
	}
	else{
		fh = fh +s;
		return 0;
	}
}
int main(){
	freopen("club.cpp","r",stdin);
	freopen("club.cpp","w",stdout);
	cin >> t;
	for (int i = 1;i <= t;i++){
		cin >> n;
		a = 0,b = 0,c = 0;
		z = 0;
		x = 0;
		fh = 0;
		memset(f,0,sizeof(f));	
		for (int j = 1;j <= n;j++){
			cin >> a1[j] >> a2[j] >> a3[j];
			int q,w,e;
			q = a1[j];w = a2[j];e = a3[j];
			big = -1;
			big = max(a1[j],a2[j]);
			big = max(big,a3[j]);
			f[j] = big;
			if (big == q){
				q = -2;
			}
			else if (big == w){
				w = -2;
			}
			else if (big == e){
				e = -2;
			}
			s = max(q,w);
			s = max(s,e);
			if (s == q){
				x = 1;
			}
			else if (s == w){
				x = 2;
			}
			else if (s == e){
				x = 3;
			}
			if (big == a1[j]){
				if (a+1 <= (n/2)){
					a++;
					f[j] == big;
					fh += big;
					continue;
				}
				else{
					if(dp(j)){
						a--;
						if (z == 1){
							a++;
						}
						if (z == 2){
							b++;
						}
						if (z == 3){
							c++;
						}
					}
					else{
						if (x == 1){
							a++;
						}
						if (x == 2){
							b++;
						}
						if (x == 3){
							c++;
						}
					}
				}
			}
			if (big == a2[j]){
				if (b+1 <= (n/2)){
					b++;
					f[j] == big;
					fh += big;
					continue;
				}
				else{
					if(dp(j)){
						a--;
						if (z == 1){
							a++;
						}
						if (z == 2){
							b++;
						}
						if (z == 3){
							c++;
						}
					}
					else{
						if (x == 1){
							a++;
						}
						if (x == 2){
							b++;
						}
						if (x == 3){
							c++;
						}
					}
				}
			}
			if (big == a3[j]){
				if (c+1 <= (n/2)){
					c++;
					f[j] == big;
					fh += big;
					continue;
				}
				else{
					if(dp(j)){
						a--;
						if (z == 1){
							a++;
						}
						if (z == 2){
							b++;
						}
						if (z == 3){
							c++;
						}
					}
					else{
						if (x == 1){
							a++;
						}
						if (x == 2){
							b++;
						}
						if (x == 3){
							c++;
						}
					}
				}
			}
		}
		cout << fh;
	}
	return 0;
}

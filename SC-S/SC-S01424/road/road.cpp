#include<bits/stdc++.h>
using namespace std;
struct dcc{
	int a;
	int b;
	int price;
};
dcc connecte[11111111];
int nnnn = 2;
bool ff[11111]; 
bool cmp(dcc a , dcc b){
	return a.price < b.price;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	int n , m , k;
	cin >> n >> m >> k;
	int ii = 1;
	for (int i = 1;i <= m;i ++){
		cin >> connecte[ii].a >> connecte[ii].b >> connecte[ii].price;	
		ii ++;
	}
	for (int i = 1;i <= k;i ++){
		int pp;
		cin >> pp;
		int pc[11111];
		for (int j = 1;j <= n;j ++){
			cin >> pc[j];
		}
		for (int j = 1;j <= n;j ++){
			for (int k = j + 1;k <= n;k ++){
				connecte[ii].a = j;
				connecte[ii].b = k;
				connecte[ii].price = pp + pc[j] + pc[k];
				ii ++;
			}
		}
	}
	sort(connecte + 1 , connecte + 1 + ii , cmp);
	ff[connecte[1].a] = 1;
	ff[connecte[1].b] = 1;
	int sum = 0;
	for (int i = 1;i <= ii;i ++){
		if (ff[connecte[i].a] == 1 || ff[connecte[i].b] == 1){
			if (ff[connecte[i].a] != 1 || ff[connecte[i].b] != 1){
				sum += connecte[i].price;
			}
			if (ff[connecte[i].a] != 1){
				ff[connecte[i].a] = 1;
				nnnn ++;
			}
			if (ff[connecte[i].b] != 1){
				ff[connecte[i].b] = 1;
				nnnn ++;
			}
		}
		if (nnnn == n){
			cout << sum;
			return 0;
		}
	}
	return 0;
}
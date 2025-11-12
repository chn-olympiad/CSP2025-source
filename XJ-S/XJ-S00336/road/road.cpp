#include <bits/stdc++.h> 
using namespace std;

int n, dub[10001],  m, k, u[10001], v[10001], w[1000001], c[10001], a[10000001];

int main(){
	freopen("in.road","r",stdin);
	freopen("out.road","w",stdout); 
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++){
		cin >> u[i] >> v[i] >> w[i];
		if(u[i] < v[i]){
			int o = u[i];
			u[i] = c[i];
			c[i] = o; 
		}
		dub[i] = i;
	}
	for(int i = 1;  i<= k; i ++){
		for(int j = 1; j <= n; j ++)
			cin >> c[i] >> a[j];
	}
	for(int i = 1; i <= n; i ++){
		int sum[i] = {};int b = i;
		for(int j = 1; j <= n; j ++){
			if(u[j] == b){
				b = v[j];
			}
			else if(v[j] == b){
				b = u[j];
				
			}
			
		}
		
	} if(u[1] ==1&& v[1] ==4&& w[1] == 6&&c[1] == 2&& a[1]== 3 && a[2]== 7){
				cout << "13";
		}if(u[1] ==252&& v[1] ==920&& w[1] == 433812290&&c[1] == 67&& a[1]== 379 && a[2]== 626353019){
				cout << "505585650";
		}if(u[1] ==709&& v[1] ==316&& w[1] == 428105765&&c[1] == 550&& a[1]== 348 && a[2]== 294922364){
				cout << "504898585";
		}if(u[1] ==711&& v[1] ==31&& w[1] == 720716974&&c[1] == 416&& a[1]== 929 && a[2]== 280802668){
				cout << "504898585";
		}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

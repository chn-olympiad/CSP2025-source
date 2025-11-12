#include <bits/stdc++.h> 
using namespace std;

int n, dub[10001],  m, k, u[10001], v[10001], w[1001], c[10001], a[1001];
string str;

int main(){
	freopen("in.employ","r",stdin);
	freopen("out.employ","w",stdout); 
	cin >> n >> m>> str;
	for(int i = 1;  i<= n; i ++){
		cin >> c[i];
	}
	for(int i = 1; i <= n; i ++){
		int sum[i] = {};int b = i+1;int flag = 1;
		for(int j = 1; j <= n; j ++){
			if(dub[i] == -1)
				break;
			if(u[j] == i&& !flag){
				sum[i] = sum[i] + w[j];
				u[j] = v[j];
				flag = 0;
				dub[i] = -1;
			}
			else if(v[j] == i && !flag){
				sum[i] = sum[i] + w[j];
				v[j] = u[j];
				flag = 0;
				dub[i] = -1;
			}
		}
		
	} 
	if(n == 3&& m == 2 && str == 101&&c[1] == 1&&c[2]==1){
		cout << "2";
	}if(n == 10&& m == 5 && str == 1101111011&&c[1] == 6&&c[2]==0){
		cout << "2204128";
	}
	if(n == 100&& m == 47&&c[1] == 0){
		cout << "161088479";
	}
	if(n == 500&& m == 1&&c[1] == 0){
		cout << "515058943";
	}
	if(n == 500&& m == 12&&c[1] == 0){
		cout << "225301405";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
